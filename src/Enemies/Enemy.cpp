#include <Enemy.hpp>
#include <TagManager.hpp>

Enemy::Enemy(
	glm::vec2 pos,
	glm::vec2 size,
	std::string spriteName,
	glm::vec3 color
) :  GameObject(pos, size, spriteName, color)
{
	TagManager::addTag(e_tag::ENEMY, this);
}

Enemy::~Enemy(void)
{

}

void Enemy::update(float deltaTime)
{
	(void)deltaTime;
}



