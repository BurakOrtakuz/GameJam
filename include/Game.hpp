/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:38:06 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/11 20:38:07 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SpriteRenderer.hpp>
#include <GameLevel.hpp>

class Game
{
public:
	enum GameState {
		GAME_ACTIVE,
		GAME_MENU,
		GAME_WIN
	};
private:
	const glm::vec2 _playerSize = glm::vec2(200.0f, 200.0f);
	constexpr static float _playerVelocity = 500.0f;
	std::vector<GameLevel>	_levels;
	GameObject				*_player;
	unsigned int			_currentLevel;
	Game::GameState				_state;
	SpriteRenderer			*_renderer;
	bool					_keys[1024];
	unsigned int			_width, _height;

public:

	Game(unsigned int width, unsigned int height);
	~Game();
	void init();
	// game loop
	void processInput(float dt);
	void update(float dt);
	void render();
	
	//Getters
	unsigned int getLevel() const;
	bool getKeys(int key) const;

	void setKeys(int key, bool value);
	void setLevel(unsigned int level);
};

#endif