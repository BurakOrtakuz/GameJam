#include <GameMap.hpp>

#include <fstream>
#include <sstream>

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
    float			unit_width	= levelWidth / static_cast<float>(width), unit_height = levelHeight / height;

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
                glm::vec2 size = (*textures)["leftUPCorner"].getSize();
                std::cout << "size.x: " << size.x << " size.y: " << size.y << std::endl;
				GameObject obj(pos, (*textures)["leftUPCorner"].getSize(), (*textures)["leftUPCorner"], glm::vec3(0.8f, 0.8f, 0.7f));
                obj.setSolid(true);
                this->objects.push_back(obj);
            }
            else if (tileData[y][x] == 9)
            {
				const glm::vec2 _playerSize(unit_width * x, unit_height * y);
				glm::vec2 playerPos = glm::vec2(levelWidth / 2.0f - _playerSize.x / 2.0f, (levelHeight * 2) - _playerSize.y);
				_player = new Player(playerPos, _playerSize, (*textures)["player"]);
				_player->setSolid(true);
            }
        }
    }
}
/* ************************ [^] PRIVATE FUNCTIONS [^] *********************** */

/* ******************* [v] CONSTRUCTOR AND DESTRUCTOR [v] ******************* */

GameMap::GameMap(void) : textures(NULL) {}

GameMap::GameMap(map<string, Texture2D> *_textures): textures(_textures)
{
}

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
    for (GameObject &tile : this->objects)
        if (!tile.isDestroyed())
            tile.draw(renderer);
}
/* **************************** [^] FUNCTIONS [^] *************************** */