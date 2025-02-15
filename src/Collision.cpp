/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collision.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:59:32 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 23:59:30 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Collision.hpp"

#include <iostream>

// constructor
Collision::Collision(glm::vec2 position, glm::vec2 size)
	: _square({position.y, position.y + size.y, position.x, position.x + size.x}) , _position(position), _size(size)
{
}

// copy constructor
Collision::Collision(Collision const &src) : _square(src._square), _position(src._position), _size(src._size)
{

}

// destructor
Collision::~Collision()
{
}

// assignment operator
Collision &Collision::operator=(Collision const &src)
{
	if (this != &src)
	{
		this->_square = src._square;
		this->_position = src._position;
		this->_size = src._size;
	}
	return *this;
}

// setters
void Collision::setCollision(glm::vec2 position, glm::vec2 size)
{
	this->_square = {position.y, position.y + size.y, position.x, position.x + size.x};
	this->_position = position;
	this->_size = size;
}

void Collision::setCollision(square square)
{
	this->_square = square;
	this->_position = glm::vec2(square.left, square.up);
	this->_size = glm::vec2(square.right - square.left, square.down - square.up);
}

void Collision::setPosition(glm::vec2 position)
{
	this->_position = position;
	this->_square = {position.y, position.y + this->_size.y, position.x, position.x + this->_size.x};
}

void Collision::setSize(glm::vec2 size)
{
	this->_size = size;
	this->_square = {this->_position.y, this->_position.y + size.y, this->_position.x, this->_position.x + size.x};
}

// getters
square Collision::getCollision() const
{
	return this->_square;
}

glm::vec2 Collision::getSize() const
{
	return this->_size;
}

glm::vec2 Collision::getPosition() const
{
	return this->_position;
}

// member functions
bool	Collision::checkCollision(Collision const &other) const
{
	if (this->_square.right >= other._square.left &&
		this->_square.left <= other._square.right &&
		this->_square.down >= other._square.up &&
		this->_square.up <= other._square.down)
	{
		return true;
	}
	return false;
}
