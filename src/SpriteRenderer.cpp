/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpriteRenderer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:41:43 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/15 00:00:35 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SpriteRenderer.hpp>
#include <iostream>
#include <ResourceManager.hpp>

SpriteRenderer::SpriteRenderer(std::string shaderName)
{
	_shaderName = shaderName;
	this->initRenderData();
}

SpriteRenderer::~SpriteRenderer()
{
	glDeleteVertexArrays(1, &_quadVAO);
}

void SpriteRenderer::drawSprite(std::string textureName, glm::vec2 position, glm::vec2 size, bool flip, float rotate, glm::vec3 color)
{
	Texture2D texture = ResourceManager::getTexture(textureName);
	ResourceManager::getShader(_shaderName).Use();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position, 0.0f));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)

	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f)); // move origin of rotation to center of quad
	model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f)); // move origin back

	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, glm::radians((float)flip * 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
	
	model = glm::scale(model, glm::vec3(size, 1.0f)); // last scale
	
	ResourceManager::getShader(_shaderName).SetMatrix4("model", model);
	ResourceManager::getShader(_shaderName).SetVector2f("tilingFactor", glm::vec2(1.0f, 1.0f)); // Pass tiling to shader

	// prepare transformations
	// render textured quad

	ResourceManager::getShader(_shaderName).SetVector3f("spriteColor", color);

	glActiveTexture(GL_TEXTURE0);
	texture.bind();

	// glGenerateMipmap(GL_TEXTURE_2D);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindVertexArray(_quadVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void SpriteRenderer::drawSpriteTiled(
    std::string textureName,
    glm::vec2 position,
    glm::vec2 size,
    bool flip,
    float rotate,
    glm::vec3 color
) {
    Texture2D texture = ResourceManager::getTexture(textureName);
    glm::vec2 textureSize = texture.getSize(); // Get original texture size

    // Calculate how many times to repeat the texture
    glm::vec2 tilingFactor = size / textureSize;

    // Activate shader and set uniforms
    Shader shader = ResourceManager::getShader(_shaderName);
    shader.Use();
    shader.SetVector2f("tilingFactor", tilingFactor); // Pass tiling to shader
    shader.SetVector3f("spriteColor", color);

    // Configure model matrix (same as before)
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));

    // Handle rotation (same as original)
    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    // Handle flipping (same as original)
    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::rotate(model, glm::radians((float)flip * 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    // Scale geometry to desired size
    model = glm::scale(model, glm::vec3(size, 1.0f));
    shader.SetMatrix4("model", model);

    // Bind texture and enable tiling
    glActiveTexture(GL_TEXTURE0);
    texture.bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Enable tiling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Draw the quad
    glBindVertexArray(_quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::initRenderData()
{
	// configure VAO/VBO
	unsigned int VBO;
	float vertices[] = { 
		// pos      // tex
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f, 
	
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &_quadVAO);
	glGenBuffers(1, &VBO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(_quadVAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);  
	glBindVertexArray(0);
}