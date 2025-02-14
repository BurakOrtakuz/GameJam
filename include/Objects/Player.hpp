#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <GameObject.hpp>
#include <Animation.hpp>
#include <map>
class Player : public GameObject
{
private:
	constexpr static glm::vec2	defaultVelocity = glm::vec2(0.0f, 0.0f);

	//std::map<std::string, Animation*>	_animations;
	Animation							*_animation;
	glm::vec2							_velocity;
	std::string							_currentAnimation;
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

	void addAnimation(
		std::vector<std::string> textures,
		std::string animationName
	);
	void updateAnimation();
	void setCurAnimation(const std::string &animationName);
};


#endif // PLAYER_HPP