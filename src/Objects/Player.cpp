#include <Player.hpp>

Player::Player(
	glm::vec2 pos, 
	glm::vec2 size, 
	std::string sprite, 
	glm::vec3 color,
	glm::vec2 velocity
):
	GameObject(pos, size, sprite, color),
	_velocity(velocity),
	_groundCollision(Collision(glm::vec2(pos.x, pos.y + 143.0f), glm::vec2(30.0f, 10.0f)))
{
	_collision.setCollision(glm::vec2(pos.x + 67.0f, pos.y + 13.0f), glm::vec2(31.0f, 127.0f));
	_momentumPosition = glm::vec2(pos.x + 67.0f, pos.y);
	_position = pos;
}

Player::Player(const Player &player)
	: GameObject(player), _velocity(player._velocity), _groundCollision(player._groundCollision)
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

void Player::setPosition(glm::vec2 pos)
{
	_position = glm::vec2(pos.x - 67.0f, pos.y - 13.0f);
	_collision.setPosition(glm::vec2(pos.x, pos.y));
	_groundCollision.setPosition(glm::vec2(pos.x, pos.y + 157.0f));
}

glm::vec2 Player::getMomentum(void) const
{
	return (this->_momentumPosition);
}

void Player::setMomentum(glm::vec2 momentum)
{
	this->_momentumPosition = momentum;
}

void Player::onHide(bool value)
{
	this->_onHide = value;
}

bool Player::getHide(void) const
{
	return (this->_onHide);
}