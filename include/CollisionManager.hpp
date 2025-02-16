/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CollisionManager.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:35:09 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/15 17:45:09 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISIONMANAGER_HPP
# define COLLISIONMANAGER_HPP

#include "Collision.hpp"
#include "GameObject.hpp"
#include "tag.hpp"

class CollisionManager
{
	private:
		// private constructor
		CollisionManager() = delete;
		CollisionManager(CollisionManager const &src) = delete;
		CollisionManager &operator=(CollisionManager const &src) = delete;
		~CollisionManager();
	public:

		// member functions
		static bool	checkCollision(e_tag tag, const GameObject *other);
		static bool	checkCollision(e_tag tag, const Collision &other);
		static bool	checkCollision(Collision obj1, Collision obj2);
		static bool	checkCollision(const GameObject *obj1, const GameObject *obj2);
		static bool	checkCollision(const GameObject *obj1, Collision obj2);
		static bool	checkCollision(Collision obj1, const GameObject *obj2);
		static bool	checkCollision(glm::vec2 position, glm::vec2 size, glm::vec2 position2, glm::vec2 size2);
		static bool	checkCollision(glm::vec2 a, glm::vec2 b, glm::vec2 size);
};
#endif // COLLISIONMANAGER_HPP
