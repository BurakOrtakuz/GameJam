#ifndef SHADER_HPP
#define SHADER_HPP 202502

#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader
{
private:
	unsigned int ID;
public:
	Shader();
	Shader(const Shader &other);
	~Shader();
	Shader &operator=(const Shader &other);

	Shader  &Use();
	void	init(const char *, const char *);
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


#endif /* SHADER_HPP */

