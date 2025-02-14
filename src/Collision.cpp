/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collision.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:59:32 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 18:45:19 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Collision.hpp"

#include <iostream>

// constructor
Collision::Collision(glm::vec2 position, glm::vec2 size) : _square({position.y, position.y + size.y, position.x, position.x + size.x})
{
}

// copy constructor
Collision::Collision(Collision const &src) : _square(src._square)
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
	}
	return *this;
}

// setters
void Collision::setCollision(glm::vec2 position, glm::vec2 size)
{
	this->_square = {position.y, position.y + size.y, position.x, position.x + size.x};
}

// getters
square Collision::getCollision() const
{
	return this->_square;
}

#include <iostream>
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

