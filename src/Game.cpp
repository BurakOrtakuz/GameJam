#include <glm/glm.hpp>
#include <glad/glad.h>
#include <graphic/Graphic.hpp>
#include <Utils.hpp>
#include <Game.hpp>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <CollisionManager.hpp>
#include <TagManager.hpp>

bool Game::_keys[1024] = {0};

Game::Game(void)
{
	_state = GameState::GAME_ACTIVE;
}

Game::~Game(void)
{
	gl_destroy_window(_window);
}

void Game::start(void)
{
	this->_shader.init("lib/Shaders/shader.vs", "lib/Shaders/shader.fs");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(SCREEN_WIDTH),
		static_cast<float>(SCREEN_HEIGHT), 0.0f, -1.0f, 1.0f);
	this->_shader.Use().SetInteger("image", 0);
	this->_shader.SetMatrix4("projection", projection);
	_renderer = new SpriteRenderer(this->_shader);
	initRender();
	this->_camera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT, _player->getPosition(), 1.0f);
	this->loop();
}

void Game::loop(void)
{
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	float fpsTimer = 0.0f;
	int frameCount = 0;
	while (!glfwWindowShouldClose(_window))
	{
		// calculate delta time
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		fpsTimer += deltaTime;
        frameCount++;
		if (fpsTimer >= 1.0f)
        {
			//std::cout << "playerPos\nx: " <<  _player->getPosition().x << " y: " << _player->getPosition().y << std::endl;
			//std::cout << "Player Collision\ndown: " << _player->getCollision().getCollision().down << "up: " << _player->getCollision().getCollision().up << "left: " << _player->getCollision().getCollision().left << "right: " << _player->getCollision().getCollision().right << std::endl;

			if (CollisionManager::checkCollision(e_tag::WALL, _player) == true)
				std::cout << "duvarın içerisinde" << std::endl;
            std::cout << "FPS: " << frameCount << std::endl; //__??__
            fpsTimer = 0.0f;
            frameCount = 0;
        }

		glfwPollEvents();


		
		processInput(deltaTime);

		update(deltaTime);

		render();

		glfwSwapBuffers(_window);
	}
}

void Game::init(void)
{
	init_window();

	const GLFWvidmode* mode = get_primary_monitor();
	this->SCREEN_WIDTH = 1500; // mode->width / 2;
	this->SCREEN_HEIGHT = 1000; // mode->height / 2;

	this->_window = errCheck(
		(GLFWwindow *)NULL,
		gl_create_window(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout"),
		"Failed to create GLFW window"
		);


	gl_keyboard_hook(_window, key_callback);
	gl_framebuffer_size_hook(_window, framebuffer_size_callback);
}

void Game::initRender()
{
	float vertices[] = {
		// pos      // tex
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	this->_quadVAO = gl_init_render(vertices, sizeof(vertices));

	newTexture("assets/back.png", true, "background");
	newTexture("assets/Discard/Ground_texture_corner_L.png", true, "leftUPCorner");
	newTexture("assets/Discard/Ground_texture_corner_R.png", true, "rightUPCorner");
	newTexture("assets/Player.png", true, "player");

	newMap("levels/one.lvl", "level1");

	// O_o Beg your pardon but the fuck?
	// Most manuel shit I've ever seen
	// - Teo
	_player = maps["level1"]._player;
	_player->tagAdd(e_tag::PLAYER);
	_walls = &(maps["level1"].walls);
	for (Wall &wall : *_walls)
		wall.tagAdd(e_tag::WALL);
	//_enemy = maps["level1"]._enemy;
}

void
	Game::newTexture(const char *filePath, bool alpha, const char *name)
{
	Texture2D texture;
	if (alpha)
	{
		texture.setInternalFormat(GL_RGBA);
		texture.setImageFormat(GL_RGBA);
	}
	int width, height, nrChannels;
	unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);
	texture.generate(width, height, data);
	stbi_image_free(data);
	this->textures[name] = texture;
}

void
	Game::newMap(const char *filePath, const char *name)
{
	GameMap gmap(&this->textures);
	gmap.load(filePath, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
	this->maps[name] = gmap;
}

void
	Game::processInput(float dt)
{
	if (_state == GameState::GAME_ACTIVE)
	{
		float velocity = _playerVelocity * dt;
		glm::vec2 playerPos = _player->getPosition();

		(void)_keys;

		if (_keys[GLFW_KEY_A])
		{
			//if (playerPos.x >= 0.0f)
				playerPos.x -= velocity;
		}

		if (_keys[GLFW_KEY_D])
		{
			//if (playerPos.x <= SCREEN_WIDTH - _player->getSize().x)
				playerPos.x += velocity;

		}

		glm::vec2 position = playerPos;
		position.y -= 300;
		_player->setPosition(playerPos);
		_camera->setPosition(position);
		_shader.SetMatrix4("projection", _camera->getViewProjectionMatrix());
	}
}

void
	Game::render(void)
{
	if (_state == GameState::GAME_ACTIVE)
	{
		_renderer->drawSprite(textures["background"],
			glm::vec2(0.0f, 0.0f), glm::vec2(SCREEN_WIDTH * 2, SCREEN_HEIGHT), 0.0f);
		maps["level1"].draw(*_renderer);

		_player->draw(*_renderer);
		//_enemy->draw(*_renderer);


		//_renderer->drawSprite(textures["rightUPCorner"],
		//	glm::vec2(1430.0f, 0.0f), textures["rightUPCorner"].getSize(), 0.0f);
		//Texture2D text = textures["rightUPCorner"];
		//_renderer->drawSprite(text, glm::vec2(90.0f, 0.0f), text.getSize(), 0.0f);
		////maps["level1"]._player->draw(*_renderer);
	}
}

void
	Game::updateKeyStatus(int key, bool status)
{
	_keys[key] = status;
}

void
	Game::update(float dt)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	this->_camera->updateCamera(dt);
}
