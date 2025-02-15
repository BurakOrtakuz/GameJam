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
	glm::vec2							_momentumPosition;
public:
	Collision							_groundCollision;
	bool								able_to_jump = false;
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
	void	setPosition(glm::vec2 pos) override;
	glm::vec2	getMomentum(void) const;
	void setMomentum(glm::vec2 momentum);
};


#endif // PLAYER_HPP