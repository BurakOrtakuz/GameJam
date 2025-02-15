#include <Wowo.hpp>


Wowo::Wowo(
	glm::vec2 pos,
	glm::vec2 size,
	std::string spriteName,
	glm::vec3 color
): Enemy(pos, size, spriteName, color)
{
	this->_velocity = 250;
}

Wowo::~Wowo()
{
    
}