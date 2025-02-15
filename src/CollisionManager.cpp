/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CollisionManager.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:52:27 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 23:33:26 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CollisionManager.hpp>
#include <TagManager.hpp>
#include <iostream>

bool	CollisionManager::checkCollision(e_tag tag, const GameObject *other)
{
	std::vector<GameObject *> objects = TagManager::getTags(tag);
	Collision otherCollision = other->getCollision();
	for (auto object : objects)
	{
		if (object->isDestroyed() || object == other)
			continue;
		if (object->getCollision().checkCollision(otherCollision))
			return true;
	}
	return false;
}

bool	CollisionManager::checkCollision(e_tag tag, Collision other)
{
	std::vector<GameObject *> objects = TagManager::getTags(tag);
	for (auto object : objects)
	{
		if (object->isDestroyed())
			continue;
		if (object->getCollision().checkCollision(other))
			return true;
	}
	return false;
}

bool	CollisionManager::checkCollision(Collision obj1, Collision obj2)
{
	if (obj1.checkCollision(obj2))
		return true;
	return false;
}

bool	CollisionManager::checkCollision(const GameObject *obj1, const GameObject *obj2)
{
	if (obj1->getCollision().checkCollision(obj2->getCollision()))
		return true;
	return false;
}

bool	CollisionManager::checkCollision(const GameObject *obj1, Collision obj2)
{
	if (obj1->getCollision().checkCollision(obj2))
		return true;
	return false;
}

bool	CollisionManager::checkCollision(Collision obj1, const GameObject *obj2)
{
	if (obj1.checkCollision(obj2->getCollision()))
		return true;
	return false;
}

bool	CollisionManager::checkCollision(glm::vec2 position, glm::vec2 size, glm::vec2 position2, glm::vec2 size2)
{
	Collision obj1(position, size);
	Collision obj2(position2, size2);
	if (obj1.checkCollision(obj2))
		return true;
	return false;
}
