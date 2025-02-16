#include <Wowo.hpp>
#include <utils.hpp>
#include <CollisionManager.hpp>

Wowo::Wowo(
	glm::vec2 pos,
	glm::vec2 size,
	std::string spriteName,
	glm::vec3 color
): Enemy(pos, size, spriteName, color)
{
	_collision = Collision(glm::vec2(pos.x + 20.0, pos.y + 90.0f), glm::vec2(size.x - 40.0f, size.y - 105.0f));
	_moment = pos;

}

Wowo::~Wowo()
{

}

void	Wowo::gravity(float deltaTime)
{
	_moment.y += 100.0f * deltaTime;
}

void	Wowo::move(float deltaTime)
{
	_moment.x += _direction * (300.0f * deltaTime);
}

void Wowo::update(float deltaTime)
{
	if (_direction != 1.0f)
		_isReversed = false;
	else
		_isReversed = true;
	gravity(deltaTime);
 	triggers trigger = CollisionManager::checkTriggers(e_tag::WALL, _moment, _collision.getSize());
	if (trigger.bottom)
		_moment.y = _collision.getPosition().y;

	move(deltaTime);
	trigger = CollisionManager::checkTriggers(e_tag::WALL, _moment, _collision.getSize());
	if (trigger.right)
		_direction = -1.0f;
	if (trigger.left)
		_direction = +1.0f;
	_position.x = lerp(_position.x, _moment.x - 20.0f, 0.1f);
	_position.y = lerp(_position.y, _moment.y - 90.0f, 0.1f);

	_collision.setPosition(glm::vec2(_position.x + 20.0, _position.y + 90.0f));

}
