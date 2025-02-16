/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpriteRenderer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:33:30 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/15 00:01:00 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP

#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Texture2D.hpp>


class SpriteRenderer
{
private:
	// Render state
	std::string		_shaderName; 
	unsigned int	_quadVAO;
	// Initializes and configures the quad's buffer and vertex attributes
	void initRenderData();

public:
	SpriteRenderer(std::string shaderName);
	// Destructor
	~SpriteRenderer();
	// Renders a defined quad textured with given sprite
	void drawSprite(
		std::string textureName,
		glm::vec2 position,
		glm::vec2 size = glm::vec2(10.0f, 10.0f),
		bool flip = false,
		float rotate = 0.0f,
		glm::vec3 color = glm::vec3(1.0f)
	);

};
#endif