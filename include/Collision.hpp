/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collision.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:56:02 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/13 20:42:47 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_HPP
# define COLLISION_HPP

#include <glm/glm.hpp>

struct	square
{
	glm::vec2	position;
	glm::vec2	size;
};

class Collision
{
	private:
		square	_square;

		// private constructor
		Collision() = delete;

		// private destructor
		~Collision() = delete;

	public:
		// member functions
		Collision(glm::vec2 position, glm::vec2 size);
		Collision(Collision const &src);

		// private operator
		Collision &operator=(Collision const &src);
		bool	checkCollision(Collision const &other);
};

#endif // COLLISION_HPP
