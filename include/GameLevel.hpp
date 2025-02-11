/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameLevel.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:18:50 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/11 17:27:58 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMELEVEL_HPP
#define GAMELEVEL_HPP
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <GameObject.hpp>
#include <SpriteRenderer.hpp>
#include <ResourceManager.hpp>


/// GameLevel holds all Tiles as part of a Breakout level and 
/// hosts functionality to Load/render levels from the harddisk.
class GameLevel
{
private:
	std::vector<GameObject> _levelObjects;
	
	// Initialize level from tile data
	void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
public:
	GameLevel();
	// Loads level from file
	void load(const char *file, unsigned int levelWidth, unsigned int levelHeight);
	// Render level
	void draw(SpriteRenderer &renderer);
	// Check if the level is completed (all non-solid tiles are destroyed)
	bool isCompleted();

	// Getters
	GameObject getGameObject(int index);
	
	// Setters
	void addGameObject(GameObject obj);
};

#endif // GAMELEVEL_HPP