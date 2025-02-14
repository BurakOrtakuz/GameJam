#include <GameMap.hpp>

#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ResourceManager.hpp>

/* ************************ [v] PRIVATE FUNCTIONS [v] *********************** */
void
	GameMap::init(
		std::vector<std::vector<unsigned int>>	tileData,
		unsigned int							levelWidth,
		unsigned int							levelHeight
	)
{

	unsigned int	height		= tileData.size();
	unsigned int	width		= tileData[0].size();
	//float			unit_width	= levelWidth / static_cast<float>(width), unit_height = levelHeight / height;
	float			unit_width  = 100.0f;
	float			unit_height = 100.0f;

	for (unsigned int y = 0; y < height; ++y)
	{
		for (unsigned int x = 0; x < width; ++x)
		{
			//if (tileData[y][x] == 0)
			//{
			//    glm::vec2 pos(unit_width * x, unit_height * y);
			//    //glm::vec2 size(unit_width, unit_height);
			//    GameObject obj(pos, (*textures)["leftUPCorner"].getSize(), (*textures)["leftUPCorner"], glm::vec3(0.8f, 0.8f, 0.7f));
			//    obj.setSolid(true);
			//    this->objects.push_back(obj);
			//}
			if (tileData[y][x] == 1)
			{
				glm::vec2 pos(unit_width * x, unit_height * y);
				glm::vec2 size = ResourceManager::getTexture("leftUPCorner").getSize();
				Wall wall(pos, ResourceManager::getTexture("leftUPCorner").getSize(), ResourceManager::getTexture("leftUPCorner"), glm::vec3(0.8f, 0.8f, 0.7f));
				wall.setSolid(true);
				this->walls.push_back(wall);
			}
			else if (tileData[y][x] == 9)
			{
				//glm::vec2 playerPos = glm::vec2(levelWidth / 2.0f - _playerSize.x / 2.0f, (levelHeight * 2) - _playerSize.y);
				glm::vec2 playerPos = glm::vec2(unit_width * x, unit_height * y);
				_player = new Player(playerPos, ResourceManager::getTexture("player").getSize(), ResourceManager::getTexture("player"));
				_player->setSolid(true);
			}
			else if (tileData[y][x] == 200)
			{
				glm::vec2 enemyWowoPos(unit_width * x, unit_height * y);
				_enemyWowo = new Wowo(enemyWowoPos, ResourceManager::getTexture("wowo").getSize(), ResourceManager::getTexture("wowo"), glm::vec3(1.0f));
				_enemyWowo->setSolid(true);
			}
		}
	}
}
/* ************************ [^] PRIVATE FUNCTIONS [^] *********************** */

/* ******************* [v] CONSTRUCTOR AND DESTRUCTOR [v] ******************* */

GameMap::GameMap(void){}

GameMap::~GameMap()
{
}
/* ******************* [^] CONSTRUCTOR AND DESTRUCTOR [^] ******************* */

/* **************************** [v] GETTERS [v] ***************************** */
GameObject GameMap::getGameObject(int index)
{
	return this->objects[index];
}

bool GameMap::isCompleted()
{
	for (GameObject &tile : this->objects)
		if (!tile.isSolid() && !tile.isDestroyed())
			return false;
	return true;
}
/* **************************** [^] GETTERS [^] ***************************** */

/* **************************** [v] SETTERS [v] ***************************** */
void GameMap::addGameObject(GameObject obj)
{
	this->objects.push_back(obj);
}
/* **************************** [^] SETTERS [^] ***************************** */

/* **************************** [v] FUNCTIONS [v] *************************** */
void
	GameMap::load(
		const char *file,
		unsigned int levelWidth,
		unsigned int levelHeight
	)
{
	// clear old data
	this->objects.clear();
	// load from file
	unsigned int tileCode;
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

void GameMap::draw(SpriteRenderer &renderer)
{
	for (Wall &tile : this->walls)
		if (!tile.isDestroyed())
			tile.draw(renderer);
}
/* **************************** [^] FUNCTIONS [^] *************************** */