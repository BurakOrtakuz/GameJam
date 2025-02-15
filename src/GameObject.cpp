#include <GameObject.hpp>
#include <TagManager.hpp>

/* ******************* [v] CONSTRUCTOR AND DESTRUCTOR [v] ******************* */
GameObject::GameObject(
	glm::vec2 pos,
	glm::vec2 size,
	std::string sprite,
	glm::vec3 color
):
	_position(pos),
	_size(size),
	_color(color),
	_rotation(0.0f),
	_isSolid(false),
	_destroyed(false),
	_sprite(sprite),
	_collision(pos, size)
{

}
GameObject::~GameObject()
{}
/* ******************* [^] CONSTRUCTOR AND DESTRUCTOR [^] ******************* */

/* **************************** [v] GETTERS [v] ***************************** */
glm::vec2 GameObject::getPosition() const
{
	return _position;
}

glm::vec2 GameObject::getSize() const
{
	return _size;
}

bool GameObject::isSolid() const
{
	return _isSolid;
}

bool GameObject::isDestroyed() const
{
	return _destroyed;
}

Collision	GameObject::getCollision() const
{
	return (this->_collision);
}
/* **************************** [^] GETTERS [^] ***************************** */

/* **************************** [v] SETTERS [v] ***************************** */
void GameObject::setSolid(bool solid)
{
	_isSolid = solid;
}

void GameObject::setPosition(glm::vec2 pos)
{
	_collision.setPosition(pos + _collision.getPosition() - _position);
	_position = pos;
}

void GameObject::setCollisionSize(glm::vec2 size)
{
	_collision.setSize(size);
}

void GameObject::setCollisionPosition(glm::vec2 pos)
{
	_collision.setPosition(pos);
}

void GameObject::setCollision(glm::vec2 pos, glm::vec2 size)
{
	_collision.setCollision(pos, size);
}
/* **************************** [^] SETTERS [^] ***************************** */

/* **************************** [v] FUNCTIONS [v] *************************** */
void GameObject::draw(SpriteRenderer &renderer)
{
    renderer.drawSprite(_sprite, _position, _size, _rotation, _color);
}

void GameObject::tagAdd(e_tag tag)
{
	TagManager::addTag(tag, this);
}
/* **************************** [^] FUNCTIONS [^] *************************** */
