#ifndef WOWO_HPP
#define WOWO_HPP

#include <Enemy.hpp>

class Wowo : public Enemy
{
public:
	Wowo(
		glm::vec2 pos,
		glm::vec2 size,
		std::string spriteName,
		glm::vec3 color
	);
	~Wowo();
private:


};

#endif