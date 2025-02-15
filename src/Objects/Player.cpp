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


void Player::updateAnimation(float deltaTime)
{
	std::string tempAnim = _sprite;
	std::string res = getUpdate(deltaTime);

	// std::cout << "RES: " << res << std::endl;

	if (res == "1")
	{
		// if (tempAnim == "death")
		// {
		// 	_sprite = 
		// }
		_sprite = "still1";
	}
	else
		_sprite = res;
}
