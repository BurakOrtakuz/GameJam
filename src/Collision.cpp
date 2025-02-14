/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collision.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:59:32 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 15:14:54 by bdemirbu         ###   ########.fr       */
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
void Collision::setPosition(glm::vec2 position)
{
	_square.position = position;
}
