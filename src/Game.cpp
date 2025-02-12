/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:36:12 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/12 20:46:24 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>
#include <glm/glm.hpp>
#include <ResourceManager.hpp>
#include <iostream>
Game::Game(unsigned int width, unsigned int height) : _keys()
{
	_width = width;
	_height = height;
	_state = GameState::GAME_ACTIVE;
}

Game::~Game()
{
	
}

void Game::init()
{
	glm::vec2 playerPos = glm::vec2(
							_width / 2.0f - _playerSize.x / 2.0f,
							_height - _playerSize.y);
	// load shaders
	ResourceManager::loadShader("lib/Shaders/shader.vs", "lib/Shaders/shader.fs", nullptr, "sprite");
	// configure shaders
	_camera = new Camera(_width, _height,playerPos, 1.0f);
	ResourceManager::getShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::getShader("sprite").SetMatrix4("projection", _camera->getViewProjectionMatrix());
	// set render-specific controls
	_renderer = new SpriteRenderer(ResourceManager::getShader("sprite"));
	// load textures
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
	_player = new Player(
					playerPos,
					_playerSize,
					ResourceManager::getTexture("player"),
					glm::vec3(1.0f),
					glm::vec2(400.0f, 0.0f)
				);

}

void Game::update(float dt)
{
	if (_state == Game::GameState::GAME_ACTIVE)
	{
		_camera->updateCamera(dt);
	}
}

void Game::processInput(float dt)
{
	if (_state == Game::GameState::GAME_ACTIVE)
	{
		float velocity = _player->getVelocity().x * dt;
		glm::vec2 playerPos = _player->getPosition();
		// move playerboard
		if (_keys[GLFW_KEY_A])
		{
				playerPos.x -= velocity;
		}
		if (_keys[GLFW_KEY_D])
		{
				playerPos.x += velocity;
		}
		glm::mat4 projection = glm::ortho(
					playerPos.x -(_width/2),
					playerPos.x + (_width/2),
					playerPos.y + (_height/2),
					playerPos.y - (_height/2),
					-1.0f, 2.0f
				);
		_camera->setPosition(playerPos);
		ResourceManager::getShader("sprite").SetMatrix4("projection", _camera->getViewProjectionMatrix());
		_player->setPosition(playerPos);
	}
}

void Game::render()
{
	if(_state == Game::GameState::GAME_ACTIVE)
	{
		// draw background
		_renderer->drawSprite(
			ResourceManager::getTexture("background"), 
			glm::vec2(static_cast<float>(-1000), 0.0f),
			glm::vec2(_width, _height*2),
			0.0f
		);
		// draw level
		_levels[_currentLevel].draw(*_renderer);
		_player->draw(*_renderer);
	}
}  

unsigned int Game::getLevel() const
{
	return _currentLevel;
}

bool Game::getKeys(int key) const
{
	return _keys[key];
}

void Game::setKeys(int key, bool value)
{
	_keys[key] = value;
}

void Game::setLevel(unsigned int level)
{
	if(level < _levels.size())
		_currentLevel = level;
}