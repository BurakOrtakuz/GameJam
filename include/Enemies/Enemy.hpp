#ifndef ENEMY_HPP
#define ENEMY_HPP 202502

#include <GameObject.hpp>

class Enemy : public GameObject
{
public:
	Enemy(
		glm::vec2 pos,
		glm::vec2 size,
		Texture2D sprite,
		glm::vec3 color
	);
	~Enemy();

//Private
	float		_velocity;		//hiz
	int			healty;			//Can puani
	int			attackPower;	//Saldiri hasari
	int			isAlive;		//Hayatta mi ?
	size_t		attackRange;
};

#endif /* ENEMY */