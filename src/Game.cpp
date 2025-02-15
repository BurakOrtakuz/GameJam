#include <glm/glm.hpp>
#include <glad/glad.h>
#include <graphic/Graphic.hpp>
#include <Utils.hpp>
#include <Game.hpp>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <CollisionManager.hpp>
#include <TagManager.hpp>
#include <ResourceManager.hpp>

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
	ResourceManager::loadShader("lib/Shaders/shader.vs", "lib/Shaders/shader.fs", nullptr, "shader");
	ResourceManager::getShader("shader").Use().SetInteger("image", 0);
	_renderer = new SpriteRenderer("shader");
	initRender();
	this->_camera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT, maps["level1"]._player->getPosition(), 1.0f);
	ResourceManager::getShader("shader").SetMatrix4("projection", _camera->getViewProjectionMatrix());
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
			//
			//

			
            std::cout << "FPS: " << frameCount << std::endl; //__??__
            fpsTimer = 0.0f;
            frameCount = 0;
        }

		glfwPollEvents();

		process(deltaTime);

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


	ResourceManager::loadTexture("assets/background.jpg", false, "background");
	ResourceManager::loadTexture("assets/back.png", true, "background");
	ResourceManager::loadTexture("assets/Discard/Ground_texture_corner_L.png", true, "leftUPCorner");
	ResourceManager::loadTexture("assets/Discard/Ground_texture_corner_R.png", true, "rightUPCorner");
	ResourceManager::loadTexture("assets/Wowo/Attack/Attack-1.png", true, "wowo");
	ResourceManager::loadTexture("assets/Player.png", true, "player");

	std::vector<std::string> textures;
	textures.push_back("sprint1");
	textures.push_back("sprint2");
	textures.push_back("sprint3");
	textures.push_back("sprint4");
	textures.push_back("sprint5");
	textures.push_back("sprint6");
	textures.push_back("sprint7");
	textures.push_back("sprint8");

	ResourceManager::loadTexture("assets/Characters/Fork_(mc)/Fork_sprint/1_run_loop.png", true, "sprint1");
	ResourceManager::loadTexture("assets/Characters/Fork_(mc)/Fork_sprint/2_run_loop.png", true, "sprint2");
	ResourceManager::loadTexture("assets/Characters/Fork_(mc)/Fork_sprint/3_run_loop.png", true, "sprint3");
	ResourceManager::loadTexture("assets/Characters/Fork_(mc)/Fork_sprint/4_run_loop.png", true, "sprint4");
	ResourceManager::loadTexture("assets/Characters/Fork_(mc)/Fork_sprint/5_run_loop.png", true, "sprint5");
	ResourceManager::loadTexture("assets/Characters/Fork_(mc)/Fork_sprint/6_run_loop.png", true, "sprint6");
	ResourceManager::loadTexture("assets/Characters/Fork_(mc)/Fork_sprint/7_run_loop.png", true, "sprint7");
	ResourceManager::loadTexture("assets/Characters/Fork_(mc)/Fork_sprint/8_run_loop.png", true, "sprint8");

	newMap("levels/one.lvl", "level1");
	maps["level1"]._player->addAnimation(textures, "sprint");
	std::cout << "Textures loaded" << std::endl;
	maps["level1"]._player->setCurAnimation("sprint");
	// O_o Beg your pardon but the fuck?
	// Most manuel shit I've ever seen
	// - Teo
	
	//_player = maps["level1"]._player;
	
	// _enemyWowo = maps["level1"]._enemyWowo;
	maps["level1"]._player->tagAdd(e_tag::PLAYER);
	_walls = &(maps["level1"].walls);
	for (Wall &wall : *_walls)
		wall.tagAdd(e_tag::WALL);
	//_enemy = maps["level1"]._enemy;
}

void
	Game::newMap(const char *filePath, const char *name)
{
	GameMap gmap;
	gmap.load(filePath, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
	this->maps[name] = gmap;
}

void Game::process(float dt)
{
	if (_state == GameState::GAME_ACTIVE)
	{
		float velocity = maps["level1"]._enemyWowo->_velocity * dt;
		glm::vec2 wowoPos = maps["level1"]._enemyWowo->getPosition();

		glm::vec2 playerSize = maps["level1"]._enemyWowo->getSize();

		glm::vec2 wowo_ru = {wowoPos.x, wowoPos.y};
		glm::vec2 wowo_lu = {wowoPos.x + wowoPos.x, wowoPos.y};
		glm::vec2 wowo_rd = {wowoPos.x, wowoPos.y + wowoPos.y};
		glm::vec2 wowo_ld = {wowoPos.x + wowoPos.x, wowoPos.y + wowoPos.y};

		glm::vec2 playerPos = maps["level1"]._player->getPosition();

		if (playerPos.x < wowoPos.x)
		{
			wowoPos.x -= velocity;
		}
		else if (playerPos.x > wowoPos.x)
		{
			wowoPos.x += velocity;
		}

		glm::vec2 position = wowoPos;
		maps["level1"]._enemyWowo->setPosition(wowoPos);
	}
}

void
	Game::processInput(float dt)
{
	if (_state == GameState::GAME_ACTIVE)
	{
		float velocity = _playerVelocity * dt;
		glm::vec2 playerPos = maps["level1"]._player->getPosition();

		glm::vec2 playerSize = maps["level1"]._player->getSize();

		glm::vec2 player_ru = {playerPos.x, playerPos.y};
		glm::vec2 player_lu = {playerPos.x + playerSize.x, playerPos.y};
		glm::vec2 player_rd = {playerPos.x, playerPos.y + playerSize.y};
		glm::vec2 player_ld = {playerPos.x + playerSize.x, playerPos.y + playerSize.y};

		(void)_keys;

		/*
		for (Wall wall : _walls)
		{
			glm::vec2 wallPos = wall->getPosition();
			glm::vec2 wallSize = wall->getSize();

			glm::vec2 wall_lu = {wallPos.x, wallPos.y};
			glm::vec2 wall_ru = {wallPos.x + wallSize.x, wallPos.y};
			glm::vec2 wall_ld = {wallPos.x, wallPos.y + wallSize.y};
			glm::vec2 wall_rd = {wallPos.x + wallSize.x, wallPos.y + wallSize.y};
		}
		*/

		

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
		
		glm::vec2 tempPos = maps["level1"]._player->getPosition();
		maps["level1"]._player->setPosition(playerPos);
		if (CollisionManager::checkCollision(e_tag::WALL, maps["level1"]._player) == true)
		{
			maps["level1"]._player->setPosition(tempPos);
		}
		
		_camera->setPosition(position);
		ResourceManager::getShader("shader").SetMatrix4("projection", _camera->getViewProjectionMatrix());
	}
}

void
	Game::render(void)
{
	if (_state == GameState::GAME_ACTIVE)
	{
		_renderer->drawSprite("background",
			glm::vec2(0.0f, 0.0f), glm::vec2(SCREEN_WIDTH * 2, SCREEN_HEIGHT), 0.0f);
		maps["level1"].draw(*_renderer);

		maps["level1"]._player->draw(*_renderer);
		maps["level1"]._enemyWowo->draw(*_renderer);

		
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

	maps["level1"]._player->updateAnimation(dt);
	this->_camera->updateCamera(dt);
}
