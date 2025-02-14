/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CollisionManager.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:35:09 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 14:57:32 by bdemirbu         ###   ########.fr       */
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
		~CollisionManager();
		CollisionManager &operator=(CollisionManager const &src) = delete;
	public:

		// member functions
		static bool			checkCollision(e_tag tag, GameObject *other);

};
#endif // COLLISIONMANAGER_HPP
