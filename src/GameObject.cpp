#include <GameObject.hpp>

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity)
	: _position(pos), _size(size), _velocity(velocity), _color(color), _rotation(0.0f), _sprite(sprite), _isSolid(false), _destroyed(false) 
{

}
	
void GameObject::draw(SpriteRenderer &renderer)
{
    renderer.drawSprite(_sprite, _position, _size, _rotation, _color);
}

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

void GameObject::setSolid(bool solid)
{
	_isSolid = solid;
}

void GameObject::setPosition(glm::vec2 pos)
{
	_position = pos;
}