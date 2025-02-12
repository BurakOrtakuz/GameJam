/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:04:56 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/12 13:26:03 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <GameObject.hpp>

class Player : public GameObject
{
private:
	constexpr static glm::vec2	defaultVelocity = glm::vec2(0.0f, 0.0f);

	glm::vec2	_velocity;
public:
	Player(
		glm::vec2 pos = defaultPosition, 
		glm::vec2 size = defaultSize,
		Texture2D sprite = Texture2D(),
		glm::vec3 color = glm::vec3(1.0f),
		glm::vec2 velocity = defaultVelocity
	);
	Player(const Player &player);
	Player &operator=(const Player &player);
	~Player();
};


#endif // PLAYER_HPP