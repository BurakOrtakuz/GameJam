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
	_groundCollision(Collision(glm::vec2(pos.x + 65.0f, pos.y + 150.0f), glm::vec2(30.0f, 10.0f)))
{
	_collision.setCollision(glm::vec2(pos.x + 47.0f, pos.y + 13.0f), glm::vec2(61.0f, 127.0f));
	_momentumPosition = pos;
	this->_currentAnimation = "";
}

Player::Player(const Player &player)
	: GameObject(player), _velocity(player._velocity), _groundCollision(player._groundCollision)
{
}
// 267 x +
// 128 y +
// 800 - 562 = 238
// weight 800 - 550
// heigt 800 - 562
// 285 560
// 800 800
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

void Player::setPosition(glm::vec2 pos)
{
	_position = glm::vec2(pos.x - 47.0f, pos.y - 13.0f);
	_collision.setPosition(glm::vec2(pos.x, pos.y));
	_groundCollision.setPosition(glm::vec2(pos.x + 15.5f, pos.y + 143.0f));
}

void Player::setCurAnimation(const std::string &animationName)
{
	_currentAnimation = animationName;
}

glm::vec2 Player::getMomentum(void) const
{
	return (this->_momentumPosition);
}

void Player::setMomentum(glm::vec2 momentum)
{
	this->_momentumPosition = momentum;
}

