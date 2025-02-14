/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CollisionManager.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:52:27 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 15:11:08 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CollisionManager.hpp"
#include "TagManager.hpp"

bool	CollisionManager::checkCollision(e_tag tag, GameObject *other)
{
	std::vector<GameObject *> objects = TagManager::getTags(tag);

	for (auto object : objects)
	{
		if (object->isDestroyed() || object == other)
			continue;
		if (object->getPosition().x + object->getSize().x >= other->getPosition().x &&
			other->getPosition().x + other->getSize().x >= object->getPosition().x &&
			object->getPosition().y + object->getSize().y >= other->getPosition().y &&
			other->getPosition().y + other->getSize().y >= object->getPosition().y)
			return true;
	}
	return false;
}
