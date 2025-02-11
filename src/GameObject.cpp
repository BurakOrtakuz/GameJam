/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:41:31 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/11 20:41:31 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GameObject.hpp>

/* ******************* [v] CONSTRUCTOR AND DESTRUCTOR [v] ******************* */
GameObject::GameObject(
	glm::vec2 pos,
	glm::vec2 size,
	Texture2D sprite,
	glm::vec3 color,
	glm::vec2 velocity
): 
	_position(pos),
	_size(size),
	_velocity(velocity),
	_color(color),
	_rotation(0.0f),
	_sprite(sprite),
	_isSolid(false),
	_destroyed(false) 
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
/* **************************** [^] GETTERS [^] ***************************** */

/* **************************** [v] SETTERS [v] ***************************** */
void GameObject::setSolid(bool solid)
{
	_isSolid = solid;
}

void GameObject::setPosition(glm::vec2 pos)
{
	_position = pos;
}
/* **************************** [^] SETTERS [^] ***************************** */

/* **************************** [v] FUNCTIONS [v] *************************** */
void GameObject::draw(SpriteRenderer &renderer)
{
    renderer.drawSprite(_sprite, _position, _size, _rotation, _color);
}
/* **************************** [^] FUNCTIONS [^] *************************** */
