/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collision.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:56:02 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 15:14:40 by bdemirbu         ###   ########.fr       */
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

	public:
		// member functions
		Collision(glm::vec2 position, glm::vec2 size);
		Collision(Collision const &src);
		~Collision();

		// private operator
		Collision &operator=(Collision const &src);

		// setters
		void	setPosition(glm::vec2 position);
};

#endif // COLLISION_HPP
