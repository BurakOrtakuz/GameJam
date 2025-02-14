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
	try {
		_animation = new Animation(textures, false, 1, false);
		puts("tayyib");
        //std::cout << _animation->getFrameCount() << std::endl;
		std::cout << "BEFORE Adding Animation: " << animationName << std::endl;
		std::cout << "AFTER Adding Animation: " << animationName << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception caught during Animation creation: " << e.what() << std::endl;
	}
}

void Player::updateAnimation()
{
	std::cout << "Current Animation: " << _currentAnimation << std::endl;
	std::cout << "SPRITE: " << _sprite << std::endl;
	_sprite = _animation->update(0.0f);
}

void Player::setCurAnimation(const std::string &animationName)
{
	_currentAnimation = animationName;
}