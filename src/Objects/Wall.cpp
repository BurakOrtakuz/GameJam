#include <Wall.hpp>

Wall::Wall(
	glm::vec2 pos, 
	glm::vec2 size, 
	std::string sprite, 
	glm::vec3 color,
	glm::vec2 velocity
):
	GameObject(pos, size, sprite, color),
	_velocity(velocity)
{
}

Wall::Wall(const Wall &wall)
	: GameObject(wall), _velocity(wall._velocity)
{}

Wall &Wall::operator=(const Wall &wall)
{
	if (this != &wall)
	{
		GameObject::operator=(wall);
		_velocity = wall._velocity;
	}

	return (*this);
}

Wall::~Wall(void)
{}
