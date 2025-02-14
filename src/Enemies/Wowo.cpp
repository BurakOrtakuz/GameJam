#include <Wowo.hpp>


Wowo::Wowo(
	glm::vec2 pos,
	glm::vec2 size,
	Texture2D sprite,
	glm::vec3 color
): Enemy(pos, size, sprite, color)
{
	this->_velocity = 250;
}

Wowo::~Wowo()
{
    
}