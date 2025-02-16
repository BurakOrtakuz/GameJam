#ifndef ENEMY_HPP
#define ENEMY_HPP 202502

#include <GameObject.hpp>
#include <Animationable.hpp>
#include <iostream>

class Enemy : public GameObject
{
	protected:
		glm::vec2	_moment;		//moment
		float		_velocity;		//hiz
		int			healty;			//Can puani
		int			attackPower;	//Saldiri hasari
		int			isAlive;		//Hayatta mi ?

		size_t		attackRange;
	public:
		Enemy(
			glm::vec2 pos,
			glm::vec2 size,
			std::string spriteName,
			glm::vec3 color
		);
		~Enemy();

		virtual void update(float deltaTime);
};

#endif /* ENEMY */
