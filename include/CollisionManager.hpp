/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CollisionManager.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:35:09 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/13 20:54:22 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISIONMANAGER_HPP
# define COLLISIONMANAGER_HPP

#include "Collision.hpp"

#include <map>
#include <string>
#include <vector>

class CollisionManager
{
	private:
		static	std::map<std::string, std::vector<Collision *> >	_collisions;

		// private constructor
		CollisionManager() = delete;
		CollisionManager(CollisionManager const &src) = delete;
		~CollisionManager();
		CollisionManager &operator=(CollisionManager const &src) = delete;
	public:

		// member functions
		static Collision	*addCollision(std::string const &name);
		static void			removeAllCollisions(std::string const &name);
		static void			removeCollision(std::string const &name, Collision *collision);
		static bool			checkCollision(std::string const &name, Collision *other);

};
#endif // COLLISIONMANAGER_HPP
