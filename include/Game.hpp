/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameLevel.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*   Organizer: enver yılmaz                      +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:18:50 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/11 17:27:58 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H 250211L

/* **************************** [v] INCLUDES [v] **************************** */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SpriteRenderer.hpp>
#include <GameLevel.hpp>
/* **************************** [^] INCLUDES [^] **************************** */

class Game
{
public:
/* *************************** [v] ENUM CLASS [v] *************************** */
	enum class GameState
	{
		GAME_ACTIVE,
		GAME_MENU,
		GAME_WIN
	};
/* *************************** [^] ENUM CLASS [^] *************************** */
/* ******************* [v] CONSTRUCTOR AND DESTRUCTOR [v] ******************* */
	Game(unsigned int width, unsigned int height);
	~Game();
/* ******************* [^] CONSTRUCTOR AND DESTRUCTOR [^] ******************* */
/* **************************** [v] GETTERS [v] ***************************** */
	unsigned int	getLevel()			const;
	bool			getKeys(int key)	const;
/* **************************** [^] GETTERS [^] ***************************** */
/* **************************** [v] SETTERS [v] ***************************** */
	void	setKeys(int key, bool value);
	void	setLevel(unsigned int level);
/* **************************** [^] SETTERS [^] ***************************** */
/* **************************** [v] FUNCTIONS [v] *************************** */
	void init();
	// game loop
	void processInput(float dt);
	void update(float dt);
	void render();
/* **************************** [^] FUNCTIONS [^] *************************** */

private:
/* **************************** [v] VARIABLES [v] *************************** */
	const glm::vec2			_playerSize = glm::vec2(200.0f, 200.0f);
	constexpr static float	_playerVelocity = 500.0f;
	std::vector<GameLevel>	_levels;
	GameObject				*Player;
	unsigned int			_currentLevel;
	Game::GameState			_state;
	SpriteRenderer			*_renderer;
	bool					_keys[1024];
	unsigned int			_width, _height;
/* **************************** [^] VARIABLES [^] *************************** */
};

#endif