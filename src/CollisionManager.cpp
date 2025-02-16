/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CollisionManager.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:52:27 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/16 11:51:39 by bdemirbu         ###   ########.fr       */
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

bool	CollisionManager::checkCollision(e_tag tag, const Collision &other)
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

static bool pointInRect(const glm::vec2 &point, const glm::vec2 &rectPos, const glm::vec2 &rectSize)
{
    return (point.x >= rectPos.x && point.x <= rectPos.x + rectSize.x &&
            point.y >= rectPos.y && point.y <= rectPos.y + rectSize.y);
}

bool CollisionManager::checkCollision(glm::vec2 a, glm::vec2 b, glm::vec2 size)
{
    // Calculate the effective region for point "a" and point "b" using extraSize.
    // Instead of just a + extraSize, we take the min and max so it works even if extraSize is negative.
    glm::vec2 a_min = glm::min(a, a + size);
    glm::vec2 a_max = glm::max(a, a + size);

    glm::vec2 b_min = glm::min(b, b + size);
    glm::vec2 b_max = glm::max(b, b + size);

    std::vector<GameObject *> objects = TagManager::getTags(e_tag::WALL);
    for (auto object : objects)
    {
        if (object->isDestroyed())
            continue;
/*
        glm::vec2 object_position = object->getCollision().getPosition();
        glm::vec2 object_size     = object->getCollision().getSize();

		float	a_up = a.y;
		float	a_down = a.y + size.y;
		float	a_left = a.x;
		float	a_right = a.x + size.x;

		float	b_up = b.y;
		float	b_down = b.y + size.y;
		float	b_left = b.x;
		float	b_right = b.x + size.x;

		if (a_right >= b_left &&
			a_left <= b_right &&
			a_down >= b_up &&
			a_up <= b_down)
		{
			return true;
		} */
		if (object->getCollision().checkCollision(Collision(b, size)))
			return true;
    }
    return false;
}


triggers	CollisionManager::checkTriggers(e_tag tag, Collision const &obj2)
{
	std::vector<GameObject *> objects = TagManager::getTags(tag);
	triggers trigger = {false, false, false, false};
	for (auto object : objects)
	{
		if (object->isDestroyed())
			continue;
		triggers temp = object->getCollision().checkTriggers(obj2);

		trigger.top = trigger.top || temp.top;
		trigger.bottom = trigger.bottom || temp.bottom;
		trigger.left = trigger.left || temp.left;
		trigger.right = trigger.right || temp.right;
	}
	return trigger;
}

triggers	CollisionManager::checkTriggers(e_tag tag, glm::vec2 position, glm::vec2 size)
{
	return checkTriggers(tag, Collision(position, size));
}
