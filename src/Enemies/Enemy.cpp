#include <Enemy.hpp>

Enemy::Enemy(
	glm::vec2 pos,
	glm::vec2 size,
	Texture2D sprite,
	glm::vec3 color
) :  GameObject(pos, size, sprite, color)
{
	
}

Enemy::~Enemy(void)
{

}



