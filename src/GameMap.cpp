#include <GameMap.hpp>

#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ResourceManager.hpp>

std::string getSpriteName(int i)
{
	switch (i)
	{
	case 1:
		return "ground_texture_middle"; //"platform_L_M";
	case 2:
		return "platform_L";
	case 3:
		return "platform_M";
	case 4:
		return "platform_R_M";
	case 5:
		return "ground_texture_corner_L"; //"platform_R";
	case 6:
		return "ground_texture_corner_L";
	case 7:
		return "ground_texture_corner_R";
	case 8:
		return "ground_texture_middle";
	default:
		return "";
	}
}

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
			if (tileData[y][x] > 0 && tileData[y][x] < 9)
			{
				glm::vec2 pos(unit_width * x, unit_height * y);
				std::string spriteName = getSpriteName(tileData[y][x]);
				glm::vec2 size = ResourceManager::getTexture(spriteName).getSize();
				Wall wall(pos, ResourceManager::getTexture(spriteName).getSize(), spriteName, glm::vec3(0.8f, 0.8f, 0.7f));
				wall.setSolid(true);
				this->walls.push_back(wall);
			}
			else if (tileData[y][x] == 100)
			{
				//glm::vec2 playerPos = glm::vec2(levelWidth / 2.0f - _playerSize.x / 2.0f, (levelHeight * 2) - _playerSize.y);
				glm::vec2 playerPos = glm::vec2(unit_width * x, unit_height * y - 60.0f);
				_player = new Player(playerPos, ResourceManager::getTexture("player").getSize(), "player");
				_player->setSolid(true);
			}
			else if (tileData[y][x] == 200)
			{
				glm::vec2 enemyWowoPos(unit_width * x, unit_height * y);
				_enemyWowo = new Wowo(enemyWowoPos, ResourceManager::getTexture("wowo").getSize(), "wowo", glm::vec3(1.0f));
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
