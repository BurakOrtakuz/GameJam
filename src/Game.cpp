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

#define GRAVITY_FALL_POWER 0.8F
#define JUMP_POWER 4.0F
#define SLIPPERINESS 0.0012F

Game::Game(void)
{
	_state = GameState::GAME_ACTIVE;
	SCREEN_WIDTH = 0;
	SCREEN_HEIGHT = 0;
	_quadVAO = 0;
	_renderer = nullptr;
	_window = nullptr;
	_walls = nullptr;
	_camera = nullptr;
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

static float
	my_lerp(float x, float y, float f)
{
	return (x + f * (y - x));
}

void Game::loop(void)
{
	float slipperiness = SLIPPERINESS;
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	float fpsTimer = 0.0f;
	int frameCount = 0;
	float delta_momentum = 0.0F;
	while (!glfwWindowShouldClose(_window))
	{
		Player *player = maps["level1"]._player;
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

		glm::vec2 playerPos = player->getCollision().getPosition();
		glm::vec2 playerMomentum = player->getMomentum();

		glm::vec2 temp = playerPos;

		if (CollisionManager::checkCollision(e_tag::WALL, player->_groundCollision) == false)
		{
			player->able_to_jump = false;
			delta_momentum += GRAVITY_FALL_POWER;
		}
		else
		{
			player->able_to_jump = true;
			delta_momentum = 0.0F;
		}

		playerMomentum.y = playerMomentum.y + ((392.0f + delta_momentum) * (deltaTime)); // gravity
		playerPos.x = my_lerp(playerPos.x, playerMomentum.x, slipperiness);
		playerPos.y = my_lerp(playerPos.y, playerMomentum.y, slipperiness);


		{ // COLISSION
			const float p_right = playerPos.x + player->getCollision().getSize().x;
			const float p_left = playerPos.x;
			const float p_up = playerPos.y;
			const float p_down = playerPos.y + player->getCollision().getSize().y;
			std::vector<GameObject *> objects = TagManager::getTags(e_tag::WALL);

			for (auto object : objects)
			{
				if (object->isDestroyed())
					continue;

				glm::vec2 object_position = object->getCollision().getPosition();
				glm::vec2 object_size = object->getCollision().getSize();

				const float o_right = object_position.x + object_size.x;
				const float o_left = object_position.x;
				const float o_up = object_position.y;
				const float o_down = object_position.y + object_size.y;

				bool bottomCollision =
					(fabs(p_down - o_up) < 1.0f) &&
					(p_up < o_up) &&
					(p_right > o_left) &&
					(p_left < o_right);

				bool topCollision =
					(fabs(p_up - o_down) < 1.0f) &&
					(p_down > o_down) &&
					(p_right > o_left) &&
					(p_left < o_right);

				bool leftCollision =
					(fabs(p_left - o_right) < 1.0f) &&
					(p_right > o_right) &&
					(p_down > o_up) &&
					(p_up < o_down);

				bool rightCollision =
					(fabs(p_right - o_left) < 1.0f) &&
					(p_left < o_left) &&
					(p_down > o_up) &&
					(p_up < o_down);

				if (bottomCollision)
				{
					playerPos = glm::vec2(playerPos.x, temp.y - 0.1F);
					playerMomentum = glm::vec2(playerMomentum.x, temp.y);
				}

				if (topCollision)
				{
					playerPos = glm::vec2(playerPos.x, temp.y + 0.1F);
					playerMomentum = glm::vec2(playerMomentum.x, temp.y);
				}

				if (leftCollision)
				{
					playerPos = glm::vec2(temp.x + 0.1F, playerPos.y);
					playerMomentum = glm::vec2(temp.x, playerMomentum.y);
				}

				if (rightCollision)
				{
					playerPos = glm::vec2(temp.x - 0.1F, playerPos.y);
					playerMomentum = glm::vec2(temp.x, playerMomentum.y);
				}
			}
		} // COLISSION

		player->setMomentum(playerMomentum);
		player->setPosition(playerPos);

		/*
		if (
			CollisionManager::checkCollision(
				player->getCollision().getPosition(),
				playerMomentum,
				player->getCollision().getSize()
			) == true
		)
		{
			player->setPosition(temp);
			player->setMomentum(temp);
		}
		*/


		glfwPollEvents();

		process(deltaTime);

		processInput(deltaTime);

		update(deltaTime);

		render();
		_renderer->drawSprite("merhaba", player->_groundCollision.getPosition(),
			player->_groundCollision.getSize(), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
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


	ResourceManager::loadTexture("assets/Levelconcept.png", true, "background");
	ResourceManager::loadTexture("assets/Discard/Ground_texture_corner_L.png", true, "leftUPCorner");
	ResourceManager::loadTexture("assets/Discard/Ground_texture_corner_R.png", true, "rightUPCorner");
	ResourceManager::loadTexture("assets/Characters/Wowo_(mob)/Crawl/Crawl-1.png", true, "wowo");
	ResourceManager::loadTexture("assets/Characters/Fork_mc/Fork_still.png", true, "player");

	newMap("levels/one.lvl", "level1");

	uploadForkBattle_stance();
	uploadForkClimb();
	uploadForkDash();
	uploadForkDeath();
	uploadForkDoublePunch();
	uploadForkJump();
	uploadForkSprint();
	uploadForkStill();
	uploadForkHide();
	uploadForkQuickPunch();

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
		Player *player = maps["level1"]._player;
		float velocity = _playerVelocity * dt;
		glm::vec2 playerMomentum = maps["level1"]._player->getMomentum();

		glm::vec2 playerSize = maps["level1"]._player->getSize();

		/*
		glm::vec2 player_ru = {playerMomentum.x, playerMomentum.y};
		glm::vec2 player_lu = {playerMomentum.x + playerMomentum.x, playerMomentum.y};
		glm::vec2 player_rd = {playerMomentum.x, playerMomentum.y + playerMomentum.y};
		glm::vec2 player_ld = {playerMomentum.x + playerMomentum.x, playerMomentum.y + playerSize.y};
		*/

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
		glm::vec2 size = player->getSize();
		size.y = 0.0f;
		size.x += 20.0f;
		if (CollisionManager::checkCollision(e_tag::WALL, Collision(player->getPosition(), size)) == true)
		{
			player->setCurAnimation("battle_stance");
		}
		else
			player->setCurAnimation("still");
		if (_keys[GLFW_KEY_A])
		{
			//if (playerPos.x >= 0.0f)
			player->setCurAnimation("sprint");
			playerMomentum.x -= velocity;
		}
		if (_keys[GLFW_KEY_D])
		{
			{
				player->setCurAnimation("sprint");
				playerMomentum.x += velocity;
			}
		}
		if (_keys['C'])
		{
			player->setCurAnimation("climb");
		}
		if (_keys['B'])
		{
			player->setCurAnimation("battle_stance");
		}
		if (_keys['N'])
		{
			player->setCurAnimation("dash");
			playerMomentum.x += velocity * 2;
		}
		if (_keys[GLFW_KEY_SPACE] && player->able_to_jump)
		{
			player->setCurAnimation("jump");
			playerMomentum.y -= JUMP_POWER;
		}


		glm::vec2 camPosition = player->getCollision().getPosition();
		camPosition.y -= 100;

		player->setMomentum(playerMomentum);

		_camera->setPosition(camPosition);
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

		Wall wall = maps["level1"].walls[0];
		for (Wall wall : maps["level1"].walls)
		{
			_renderer->drawSprite("merhaba", wall.getCollision().getPosition(),
				wall.getCollision().getSize(), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		}
		_renderer->drawSprite("merhaba", maps["level1"]._player->_groundCollision.getPosition(),
			maps["level1"]._player->_groundCollision.getSize(), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));

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
