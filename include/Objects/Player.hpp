#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <GameObject.hpp>
#include <Animation.hpp>
#include <map>
#include <Animationable.hpp>

class Player : public GameObject, public Animationable
{
private:
	constexpr static glm::vec2	defaultVelocity = glm::vec2(0.0f, 0.0f);

	glm::vec2							_velocity;
public:
	Player(
		glm::vec2 pos = defaultPosition, 
		glm::vec2 size = defaultSize,
		std::string sprite = "",
		glm::vec3 color = glm::vec3(1.0f),
		glm::vec2 velocity = defaultVelocity
	);
	Player(const Player &player);
	Player &operator=(const Player &player);
	~Player();
	void updateAnimation(float deltaTime);
};


#endif // PLAYER_HPP