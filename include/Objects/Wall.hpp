#ifndef WALL_HPP
# define WALL_HPP

# include <GameObject.hpp>

class Wall : public GameObject
{
private:
	constexpr static glm::vec2	defaultVelocity = glm::vec2(0.0f, 0.0f);

	glm::vec2	_velocity;
public:
	Wall(
		glm::vec2 pos = defaultPosition, 
		glm::vec2 size = defaultSize,
		std::string sprite = "",
		glm::vec3 color = glm::vec3(1.0f),
		glm::vec2 velocity = defaultVelocity
	);
	Wall(const Wall &player);
	Wall &operator=(const Wall &wall);
	~Wall();
};


#endif // WALL_HPP