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
	ResourceManager::loadShader("lib/Shaders/shaderlight.vs", "lib/Shaders/shaderlight.fs", nullptr, "shaderlight");
	unsigned int shaderId = ResourceManager::getShader("shaderlight").getID();
	ResourceManager::getShader("shaderlight").Use();
	createLight();
	uniformShaders["lightPosition"] = glGetUniformLocation(shaderId, "lightPosition");
	uniformShaders["lightIntensity"] = glGetUniformLocation(shaderId, "lightIntensity");
	glUniform2f(uniformShaders["lightPosition"], 0.0f, 0.0f);
	glUniform1f(uniformShaders["lightIntensity"], 1.0f);

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
		gl_create_window(SCREEN_WIDTH, SCREEN_HEIGHT, "Labiryntika"),
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


	ResourceManager::loadTexture("assets/Levelconcept.png", true, "background");
	ResourceManager::loadTexture("assets/Discard/Ground_texture_corner_L.png", true, "leftUPCorner");
	ResourceManager::loadTexture("assets/Discard/Ground_texture_corner_R.png", true, "rightUPCorner");
	ResourceManager::loadTexture("assets/Characters/Wowo_(mob)/Attack/Attack-1.png", true, "wowo");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_still.png", true, "player");
	
	newMap("levels/one.lvl", "level1");
	
	uploadForkBattle_stance();
	uploadForkClimb();
	uploadForkDamage();
	uploadForkDash();
	uploadForkDeath();
	uploadForkDoublePunch();
	uploadForkJump();
	uploadForkSprint();
	uploadForkHide();
	uploadForkQuickPunch();
	uploadForkStill();
	uploadForkHurt();

	std::cout << "Textures loaded" << std::endl;
	// O_o Beg your pardon but the fuck?
	// Most manuel shit I've ever seen
	// - Teo
	ResourceManager::loadTexture("assets/Collision.png", true, "merhaba");
	
	maps["level1"]._player->setCurAnimation("still");
	//_player = maps["level1"]._player;

	// _enemyWowo = maps["level1"]._enemyWowo;
	Player *player = maps["level1"]._player;
	player->tagAdd(e_tag::PLAYER);
	player->setCollision(glm::vec2(player->getPosition().x + 10.0f, player->getPosition().y + 5.0f),
							glm::vec2 (player->getSize().x - 10.0f, player->getSize().y - 6.0f));
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
			maps["level1"]._enemyWowo->setIsReversed(false);
		}
		else if (playerPos.x > wowoPos.x)
		{
			wowoPos.x += velocity;
			maps["level1"]._enemyWowo->setIsReversed(true);
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
		resetInputs();
		glm::vec2 size = maps["level1"]._player->getSize();
		size.y = 0.0f;
		size.x += 20.0f;
		if (CollisionManager::checkCollision(e_tag::WALL, Collision(maps["level1"]._player->getPosition(), size)) == true)
		{
			maps["level1"]._player->setCurAnimation("battle_stance");
		}
		else
			maps["level1"]._player->setCurAnimation("still");
		
		if (_keys[GLFW_KEY_A])
		{
			
			maps["level1"]._player->setCurAnimation("sprint");
			maps["level1"]._player->setIsReversed(true);
			playerPos.x -= velocity;
		}
		else if (_keys[GLFW_KEY_D])
		{
			maps["level1"]._player->setCurAnimation("sprint");
			maps["level1"]._player->setIsReversed(false);
			playerPos.x += velocity;
		}
		else if (_keys['C'])
		{
			maps["level1"]._player->setCurAnimation("climb");
		}
		else if (_keys['B'])
		{
			maps["level1"]._player->setCurAnimation("battle_stance");
		}
		else if (_keys['N'])
		{
			maps["level1"]._player->setCurAnimation("dash");
			playerPos.x += velocity * 2;
		}
		else if (_keys['H'])
		{
			maps["level1"]._player->setCurAnimation("hide");
		}
		else if (_keys['O'])
		{
			maps["level1"]._player->setCurAnimation("quickPunch");
		}
		else if (_keys['P'])
		{
			maps["level1"]._player->setCurAnimation("doublePunch");
		}
		else if (_keys['I'])
		{
			maps["level1"]._player->setCurAnimation("hurt");
		}
		else if (_keys['K'])
		{
			maps["level1"]._player->setCurAnimation("damage");
		}

		glm::vec2 position = playerPos;
		position.y -= 200;
		
		glm::vec2 playerViewPos = glm::vec2(playerPos.x + 800, playerPos.y - 100) - _camera->getPosition();
		//std::cout << "Player Position: (" << playerViewPos.x << ", " << playerViewPos.y << ")" << std::endl;
		ResourceManager::getShader("shaderlight").Use();

		glm::vec2 windowSize = glm::vec2(SCREEN_WIDTH, SCREEN_HEIGHT);
		glm::vec2 normalizedPos = (playerViewPos / windowSize) * 2.0f - 1.0f;
		glUniform2f(uniformShaders["lightPosition"], normalizedPos.x, normalizedPos.y);
		

		ResourceManager::getShader("shader").Use();

		glm::vec2 tempPos = maps["level1"]._player->getPosition();
		maps["level1"]._player->setPosition(playerPos);
		//if (CollisionManager::checkCollision(e_tag::WALL, position, maps["level1"]._player->getSize()) == true)
		if (CollisionManager::checkCollision(e_tag::WALL, maps["level1"]._player) == true)
		{
			maps["level1"]._player->setPosition(tempPos);
		}


		_camera->setPosition(position);
		ResourceManager::getShader("shader").SetMatrix4("projection", _camera->getViewProjectionMatrix());
	}
}

void Game::createLight()
{
	unsigned int shaderId = ResourceManager::getShader("shaderlight").getID();
	ResourceManager::getShader("shaderlight").Use();
	GLfloat lightPos[2];
	GLfloat intensity;
	glGetUniformfv(shaderId, uniformShaders["lightPosition"], lightPos);
	glGetUniformfv(shaderId, uniformShaders["lightIntensity"], &intensity);
	glGetUniformfv(shaderId, uniformShaders["lightPosition"], lightPos);
	std::cout << "Light Position: (" << lightPos[0] << ", " << lightPos[1] << ")" << std::endl;
	std::cout << "Light Intensity: " << intensity << std::endl;

	float vertices[] = {
		-1.0f, -1.0f, 0.0f,0.0f,0.0f,  // Bottom-left
		 1.0f, -1.0f, 0.0f,0.0f,0.0f, // Bottom-right
		-1.0f,  1.0f, 0.0f,0.0f,0.0f, // Top-left
		1.0f,   1.0f, 0.0f,0.0f,0.0f  // Top-right
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Game::printLight()
{
	ResourceManager::getShader("shaderlight").Use();
	glUseProgram(ResourceManager::getShader("shaderlight").getID());
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
void
	Game::render(void)
{

	if (_state == GameState::GAME_ACTIVE)
	{
		_renderer->drawSprite("background",
			glm::vec2(0.0f, 0.0f), glm::vec2(SCREEN_WIDTH * 2, SCREEN_HEIGHT));
		maps["level1"].draw(*_renderer);

		maps["level1"]._player->draw(*_renderer);
		// maps["level1"]._enemyWowo->draw(*_renderer);

		_renderer->drawSprite("merhaba",maps["level1"]._player->getCollision().getPosition(),
			maps["level1"]._player->getCollision().getSize(),false, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		//_renderer->drawSprite(textures["rightUPCorner"],
		//	glm::vec2(1430.0f, 0.0f), textures["rightUPCorner"].getSize(), 0.0f);

		//Texture2D text = textures["rightUPCorner"];
		//_renderer->drawSprite(text, glm::vec2(90.0f, 0.0f), text.getSize(), 0.0f);
		////maps["level1"]._player->draw(*_renderer);
	}
	printLight();
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