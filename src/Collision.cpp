/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collision.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:59:32 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/13 20:43:26 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Collision.hpp"

// constructor
Collision::Collision(glm::vec2 position, glm::vec2 size) : _square({position, size})
{
}

// copy constructor
Collision::Collision(Collision const &src) : _square(src._square)
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

// member functions
bool		Collision::checkCollision(Collision const &other)
{
	if (other._square.position.x + other._square.size.x >= this->_square.position.x &&
		this->_square.position.x + this->_square.size.x >= other._square.position.x &&
		other._square.position.y + other._square.size.y >= this->_square.position.y &&
		this->_square.position.y + this->_square.size.y >= other._square.position.y)
		return true;
	return false;
}
