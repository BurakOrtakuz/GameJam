#ifndef WOWO_HPP
#define WOWO_HPP

#include <Enemy.hpp>
#include <Animationable.hpp>

class Wowo : public Enemy
{
	private:

		float	_direction = 1.0f;

		void	gravity(float deltaTime);
		void	move(float deltaTime);
	public:
		Wowo(
			glm::vec2 pos,
			glm::vec2 size,
			std::string spriteName,
			glm::vec3 color
		);
		~Wowo();
		void	update(float deltaTime);
};

#endif
