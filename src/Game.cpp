/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:36:12 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/11 20:36:13 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <Game.hpp>
#include <glm/glm.hpp>
#include <ResourceManager.hpp>
#include <iostream>
/* **************************** [^] INCLUDES [^] **************************** */

/* ******************* [v] CONSTRUCTOR AND DESTRUCTOR [v] ******************* */
Game::Game(unsigned int width, unsigned int height) : _keys()
{
	_width = width;
	_height = height;
	_state = GameState::GAME_ACTIVE;
}

Game::~Game()
{
	
}
/* ******************* [^] CONSTRUCTOR AND DESTRUCTOR [^] ******************* */

/* **************************** [v] GETTERS [v] ***************************** */
unsigned int Game::getLevel() const
{
	return _currentLevel;
}

bool Game::getKeys(int key) const
{
	return _keys[key];
}
/* **************************** [^] GETTERS [^] ***************************** */

/* **************************** [v] SETTERS [v] ***************************** */
void Game::setKeys(int key, bool value)
{
	_keys[key] = value;
}

void Game::setLevel(unsigned int level)
{
	if(level < _levels.size())
		_currentLevel = level;
}
/* **************************** [^] SETTERS [^] ***************************** */

/* **************************** [v] FUNCTIONS [v] *************************** */
void Game::init()
{
	// load shaders
	ResourceManager::loadShader("lib/Shaders/shader.vs", "lib/Shaders/shader.fs", nullptr, "sprite");
	// configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(_width), 
		static_cast<float>(_height), 0.0f, -1.0f, 1.0f);
	ResourceManager::getShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::getShader("sprite").SetMatrix4("projection", projection);
	// set render-specific controls
	_renderer = new SpriteRenderer(ResourceManager::getShader("sprite"));
	// load textures
	std::cout<<"Loading textures"<<std::endl;
	ResourceManager::loadTexture("assets/background/back.png", true, "background");
	// ResourceManager::loadTexture("assets/awesomeface.png", true, "face");
	// ResourceManager::loadTexture("assets/block.png", false, "block");
	// ResourceManager::loadTexture("assets/block_solid.png", false, "block_solid");
	// ResourceManager::loadTexture("assets/paddle.png", true, "paddle");
    ResourceManager::loadTexture("assets/player/sabit.PNG", true, "player");
	// load levels
	GameLevel one; one.load("levels/one.lvl", _width, _height / 2);
	GameLevel two; two.load("levels/two.lvl", _width, _height / 2);
	GameLevel three; three.load("levels/three.lvl", _width, _height / 2);
	GameLevel four; four.load("levels/four.lvl", _width, _height / 2);
	_levels.push_back(one);
	_levels.push_back(two);
	_levels.push_back(three);
	_levels.push_back(four);
	_currentLevel = 0;
	// configure game objects
	glm::vec2 playerPos = glm::vec2(_width / 2.0f - _playerSize.x / 2.0f, _height - _playerSize.y);
	_player = new GameObject(playerPos, _playerSize, ResourceManager::getTexture("player"));
}

void Game::update(float dt)
{
	
}

void Game::processInput(float dt)
{
	if (_state == GameState::GAME_ACTIVE)
	{
		float velocity = _playerVelocity * dt;
		glm::vec2 playerPos = _player->getPosition();
		// move playerboard
		if (_keys[GLFW_KEY_A])
		{
			if (playerPos.x >= 0.0f)
				playerPos.x -= velocity;
		}
		if (_keys[GLFW_KEY_D])
		{
			if (playerPos.x <= _width - _player->getSize().x)
				playerPos.x += velocity;
		}
		_player->setPosition(playerPos);
	}
}

void Game::render()
{
	if(_state == GameState::GAME_ACTIVE)
	{
		// draw background
		_renderer->drawSprite(ResourceManager::getTexture("background"), 
			glm::vec2(0.0f, 0.0f), glm::vec2(_width, _height), 0.0f
		);
		// draw level
		_levels[_currentLevel].draw(*_renderer);
		_player->draw(*_renderer);
	}
}
/* **************************** [^] FUNCTIONS [^] *************************** */