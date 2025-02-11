/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:02:32 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/11 13:02:41 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h> 
#include <glm/glm.hpp>
#include <string>

class Shader
{
private:
	unsigned int ID; 
	void    checkCompileErrors(unsigned int object, std::string type); 
public:
	Shader();
	Shader(const char *vertexPath, const char *fragmentPath, const char *geometryPath = nullptr);
	Shader(const Shader &other);
	~Shader();
	
	Shader &operator=(const Shader &other);
	
	Shader  &Use();
	void    Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource = nullptr); // note: geometry source code is optional 
	void    SetFloat    (const char *name, float value, bool useShader = false);
	void    SetInteger  (const char *name, int value, bool useShader = false);
	void    SetVector2f (const char *name, float x, float y, bool useShader = false);
	void    SetVector2f (const char *name, const glm::vec2 &value, bool useShader = false);
	void    SetVector3f (const char *name, float x, float y, float z, bool useShader = false);
	void    SetVector3f (const char *name, const glm::vec3 &value, bool useShader = false);
	void    SetVector4f (const char *name, float x, float y, float z, float w, bool useShader = false);
	void    SetVector4f (const char *name, const glm::vec4 &value, bool useShader = false);
	void    SetMatrix4  (const char *name, const glm::mat4 &matrix, bool useShader = false);
	unsigned int getID() const;
};

#endif