#include <Player.hpp>

Player::Player(
	glm::vec2 pos, 
	glm::vec2 size, 
	std::string sprite, 
	glm::vec3 color,
	glm::vec2 velocity
): 
	GameObject(pos, size, sprite, color),
	_velocity(velocity)
{
	this->_currentAnimation = "";
}

Player::Player(const Player &player)
	: GameObject(player), _velocity(player._velocity)
{
}

Player &Player::operator=(const Player &player)
{
	if (this != &player)
	{
		GameObject::operator=(player);
		_velocity = player._velocity;
	}
	return (*this);
}

Player::~Player()
{
}

void Player::addAnimation(
	std::vector<std::string> textures,
	std::string animationName
)
{
	_animations[animationName] = Animation(textures, true, 15, true);
	_animations[animationName].setPlaying(true);
}

void Player::updateAnimation(float deltaTime)
{
	_sprite = _animations[_currentAnimation].update(deltaTime);
}

void Player::setCurAnimation(const std::string &animationName)
{
	_currentAnimation = animationName;
}