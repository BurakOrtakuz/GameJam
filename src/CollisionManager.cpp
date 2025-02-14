/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CollisionManager.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:52:27 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 19:12:45 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CollisionManager.hpp"
#include "TagManager.hpp"
#include <iostream>

bool	CollisionManager::checkCollision(e_tag tag, const GameObject *other)
{
	std::vector<GameObject *> objects = TagManager::getTags(tag);
	Collision otherCollision = other->getCollision();
	int i = 0;
	for (auto object : objects)
	{
		if (object->isDestroyed() || object == other)
			continue;
		if (object->getCollision().checkCollision(otherCollision))
			return true;
	}
	return false;
}
