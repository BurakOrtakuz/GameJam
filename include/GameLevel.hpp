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

#ifndef GAMELEVEL_HPP
#define GAMELEVEL_HPP 250211L

/* **************************** [v] INCLUDES [v] **************************** */
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>

#include <GameObject.hpp>
#include <SpriteRenderer.hpp>
#include <ResourceManager.hpp>
/* **************************** [^] INCLUDES [^] **************************** */

/// GameLevel holds all Tiles as part of a Breakout level and 
/// hosts functionality to Load/render levels from the harddisk.

class GameLevel
{
private:
/* **************************** [v] VARIABLES [v] *************************** */
	std::vector<GameObject> _levelObjects;
/* **************************** [^] VARIABLES [^] *************************** */
/* *********************** [v] PRIVATE FUNCTIONS [v] ************************ */
	// Initialize level from tile data
	void init(
		std::vector<std::vector<unsigned int>>	tileData,
		unsigned int							levelWidth,
		unsigned int							levelHeight
	);
/* *********************** [^] PRIVATE FUNCTIONS [^] ************************ */

public:
/* ******************* [v] CONSTRUCTOR AND DESTRUCTOR [v] ******************* */
	GameLevel();
/* ******************* [^] CONSTRUCTOR AND DESTRUCTOR [^] ******************* */
/* **************************** [v] GETTERS [v] ***************************** */
	GameObject getGameObject(int index);
	bool isCompleted();
/* **************************** [^] GETTERS [^] ***************************** */
/* **************************** [v] SETTERS [v] ***************************** */
	void addGameObject(GameObject obj);
/* **************************** [^] SETTERS [^] ***************************** */
/* **************************** [v] FUNCTIONS [v] *************************** */
	// Loads level from file
	void load(
		const char *file,
		unsigned int levelWidth,
		unsigned int levelHeight
	);
	// Render level
	void draw(SpriteRenderer &renderer);
/* **************************** [^] FUNCTIONS [^] *************************** */

};

#endif // GAMELEVEL_HPP