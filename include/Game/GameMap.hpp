#ifndef GAMEMAP_HPP
# define GAMEMAP_HPP 202502L

#include <SpriteRenderer.hpp>
#include <GameObject.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <Player.hpp>
#include <Wowo.hpp>
#include <Wall.hpp>

using std::map;
using std::string;
using std::vector;

class GameMap
{
public:
	GameMap(void);
	~GameMap(void);

	GameObject getGameObject(int index);
	bool isCompleted();
	void addGameObject(GameObject obj);
	void load(
		const char *file,
		unsigned int levelWidth,
		unsigned int levelHeight
	);
	void draw(SpriteRenderer &renderer);
	Player				*_player;
	Wowo				*_enemyWowo;
	std::vector<Wall>	walls;
private:
	std::vector<GameObject>		objects;

	void init(
		std::vector<std::vector<unsigned int>>	tileData,
		unsigned int							levelWidth,
		unsigned int							levelHeight
	);
};


#endif /* GAMEMAP_HPP */