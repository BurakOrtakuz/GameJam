/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:09:46 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/12 13:16:02 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Player.hpp>

Player::Player(
	glm::vec2 pos, 
	glm::vec2 size, 
	Texture2D sprite, 
	glm::vec3 color,
	glm::vec2 velocity
): 
	GameObject(pos, size, sprite, color),
	_velocity(velocity)
{
}

Player::Player(const Player &player)
	: GameObject(player), _velocity(player._velocity)
{
}

Player &Player::operator=(const Player &player)
{
	if (this != &player)
	{
		GameObject::operator=(player);
		_velocity = player._velocity;
	}
	return (*this);
}

Player::~Player()
{
}

