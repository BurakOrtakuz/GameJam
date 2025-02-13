/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CollisionManager.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:52:27 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/13 20:55:25 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CollisionManager.hpp"

std::map<std::string, std::vector<Collision *> >	CollisionManager::_collisions;

Collision	*CollisionManager::addCollision(std::string const &name)
{
	Collision	*collision = new Collision({0, 0}, {0, 0});

	_collisions[name].push_back(collision);
	return collision;
}

void		CollisionManager::removeAllCollisions(std::string const &name)
{
	for (auto &collision : _collisions[name])
		delete collision;
	_collisions[name].clear();
}

