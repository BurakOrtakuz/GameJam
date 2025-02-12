/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:41:23 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/12 20:46:06 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Camera.hpp>

Camera::Camera(
		float screenWidth,
		float screenHeight,
		glm::vec2 position,
		float lerpSpeed
	):
		_position(position),
		_zoom(1.0f),
		_rotation(0.0f),
		_targetPosition(0.0f, 0.0f),
		_screenWidth(screenWidth),
		_screenHeight(screenHeight),
		_lerpSpeed(lerpSpeed)
{
}

glm::mat4 Camera::getViewProjectionMatrix() const
{
	glm::mat4 projection = glm::ortho(
		-_screenWidth / 2.0f / _zoom,
		_screenWidth / 2.0f / _zoom,
		_screenHeight / 2.0f / _zoom,
		-_screenHeight / 2.0f / _zoom,
		-1.0f,
		1.0f
	);
	glm::mat4 view = glm::mat4(1.0f);
	view =glm::translate(
				glm::mat4(1.0f),
				glm::vec3(-_position, 0.0f)
			);
	view =	glm::rotate(
				view,
				glm::radians(_rotation),
				glm::vec3(0.0f, 0.0f, 1.0f)
		);
	return projection * view;			
}

void Camera::updateCamera(float dt)
{
	_position = glm::mix(
					_position,
					_targetPosition,
					_lerpSpeed * dt
				);
}
void Camera::move(glm::vec2 &delta)
{
	_targetPosition += delta;
}


void Camera::zoom(const float zoom)
{
	if(_zoom >= 0.1f && _zoom <= 10.0f)
		_zoom += zoom;
}

void Camera::setPosition(const glm::vec2 &position)
{
	_targetPosition = position;
}

void Camera::setRotation(const float degree)
{
	_rotation = degree;
}

void Camera::setLerpSpeed(const float lerpSpeed)
{
	_lerpSpeed = lerpSpeed;
}

