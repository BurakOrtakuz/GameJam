/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collision.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:56:02 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 23:59:25 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_HPP
# define COLLISION_HPP

#include <glm/glm.hpp>

struct	square
{
	float	up;
	float	down;
	float	left;
	float	right;
};

class Collision
{
	private:
		square	_square;
		glm::vec2	_position;
		glm::vec2	_size;

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
		void	setCollision(glm::vec2 position, glm::vec2 size);
		void	setCollision(square square);
		void	setPosition(glm::vec2 position);
		void	setSize(glm::vec2 size);

		// getters
		square		getCollision() const;
		glm::vec2	getSize() const;
		glm::vec2	getPosition() const;

		// member functions
		bool	checkCollision(Collision const &other) const;
};

#endif // COLLISION_HPP
