#ifndef ENEMY_HPP
#define ENEMY_HPP 202502

#include <GameObject.hpp>
#include <iostream>

class Enemy : public GameObject
{
public:
	Enemy(
		glm::vec2 pos,
		glm::vec2 size,
		std::string spriteName,
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