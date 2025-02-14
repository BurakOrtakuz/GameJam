#include <Enemy.hpp>

Enemy::Enemy(
	glm::vec2 pos,
	glm::vec2 size,
	std::string spriteName,
	glm::vec3 color
) :  GameObject(pos, size, spriteName, color)
{
	
}

Enemy::~Enemy(void)
{

}



