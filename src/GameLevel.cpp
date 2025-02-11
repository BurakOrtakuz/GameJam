/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameLevel.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:22:51 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/11 17:59:03 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameLevel.hpp>

#include <fstream>
#include <sstream>

GameLevel::GameLevel()
{
}

void GameLevel::load(const char *file, unsigned int levelWidth, unsigned int levelHeight)
{
    // clear old data
    _levelObjects.clear();
    // load from file
    unsigned int tileCode;
    GameLevel level;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<unsigned int>> tileData;
    if (fstream)
    {
        while (std::getline(fstream, line)) // read each line from level file
        {
            std::istringstream sstream(line);
            std::vector<unsigned int> row;
            while (sstream >> tileCode) // read each word separated by spaces
                row.push_back(tileCode);
            tileData.push_back(row);
        }
        if (tileData.size() > 0)
            this->init(tileData, levelWidth, levelHeight);
    }
}

void GameLevel::draw(SpriteRenderer &renderer)
{
    for (GameObject &tile : _levelObjects)
        if (!tile.isDestroyed())
            tile.draw(renderer);
}

bool GameLevel::isCompleted()
{
    for (GameObject &tile : _levelObjects)
        if (!tile.isSolid() && !tile.isDestroyed())
            return false;
    return true;
}

void GameLevel::init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight)
{
    // calculate dimensions
    unsigned int height = tileData.size();
    unsigned int width = tileData[0].size(); // note we can index vector at [0] since this function is only called if height > 0
    float unit_width = levelWidth / static_cast<float>(width), unit_height = levelHeight / height; 
    // initialize level tiles based on tileData		
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            // check block type from level data (2D level array)
            if (tileData[y][x] == 1) // solid
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                GameObject obj(pos, size, ResourceManager::getTexture("block_solid"), glm::vec3(0.8f, 0.8f, 0.7f));
                obj.setSolid(true);
                _levelObjects.push_back(obj);
            }
            else if (tileData[y][x] > 1)	// non-solid; now determine its color based on level data
            {
                glm::vec3 color = glm::vec3(1.0f); // original: white
                if (tileData[y][x] == 2)
                    color = glm::vec3(0.2f, 0.6f, 1.0f);
                else if (tileData[y][x] == 3)
                    color = glm::vec3(0.0f, 0.7f, 0.0f);
                else if (tileData[y][x] == 4)
                    color = glm::vec3(0.8f, 0.8f, 0.4f);
                else if (tileData[y][x] == 5)
                    color = glm::vec3(1.0f, 0.5f, 0.0f);

                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                _levelObjects.push_back(GameObject(pos, size, ResourceManager::getTexture("block"), color));
            }
        }
    }
}

GameObject GameLevel::getGameObject(int index)
{
	return _levelObjects[index];
}

void GameLevel::addGameObject(GameObject obj)
{
	_levelObjects.push_back(obj);
}