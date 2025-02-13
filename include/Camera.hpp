/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:38:11 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/12 20:39:13 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
	constexpr static float defaultLerpSpeed = 0.1f;
	constexpr static glm::vec2 defaultPosition = glm::vec2(0.0f, 0.0f);
	glm::vec2 _position;
	glm::vec2 _targetPosition;
	float _zoom;
	float _rotation;
	float _lerpSpeed;
	const float _screenWidth;
	const float _screenHeight;

public:
	Camera(
		float screenWidth,
		float screenHeight,
		glm::vec2 position = defaultPosition,
		float lerpSpeed = defaultLerpSpeed
	);
	glm::mat4 getViewProjectionMatrix() const;
	void updateCamera(float dt);
	void move(glm::vec2 &delta);
	void zoom(const float zoom);
	void setPosition(const glm::vec2 &position);
	void setRotation(const float degree);
	void setLerpSpeed(const float lerpSpeed);
};

#endif // CAMERA_HPP