/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResourceManager.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:40:19 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/12 14:38:32 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <string>

#include <glad/glad.h>

#include <Texture2D.hpp>
#include <Shader.hpp>


// A static singleton ResourceManager class that hosts several
// functions to load Textures and Shaders. Each loaded texture
// and/or shader is also stored for future reference by string
// handles. All functions and resources are static and no 
// public constructor is defined.
class ResourceManager
{
private:
	// private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
	ResourceManager() = delete;
	ResourceManager(ResourceManager const &) = delete;
	ResourceManager &operator=(ResourceManager const &) = delete;

	static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
	// loads a single texture from file
	static Texture2D loadTextureFromFile(const char *file, bool alpha);
	static std::map<std::string, Shader>    _shaders;
	static std::map<std::string, Texture2D> _textures;
public:
	// Loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
	static Shader loadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
	// Retrieves a stored shader
	static Shader& getShader(const std::string &name);
	// Loads (and generates) a texture from file
	static Texture2D loadTexture(const char *file, bool alpha, std::string name);
	// Retrieves a stored texture
	static Texture2D& getTexture(const std::string &name);
	// Properly de-allocates all loaded resources
	static void      clear();
};

#endif // RESOURCEMANAGER_HPP