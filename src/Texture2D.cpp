#include <iostream>
#include <Texture2D.hpp>
#include <graphic/Graphic.hpp>

Texture2D::Texture2D()
    : _width(0), _height(0), _internal_Format(GL_RGB), _image_Format(GL_RGB), _wrap_S(GL_REPEAT), _wrap_T(GL_REPEAT), _filter_Min(GL_LINEAR), _filter_Max(GL_LINEAR)
{
    glGenTextures(1, &_id);
}

void Texture2D::generate(unsigned int width, unsigned int height, unsigned char* data)
{
    _width = width/3;
    _height = height/3;
	struct s_texture text;
	
	text.data = data;
	text.width = width;
	text.height = height;
	text.id = _id;
	text.wrap_S = _wrap_S;
	text.wrap_T = _wrap_T;
	text.filter_Min = _filter_Min;
	text.filter_Max = _filter_Max;
	text.internal_Format = _internal_Format;
	text.image_Format = _image_Format;
    gl_generate_texture(text);
}

void Texture2D::bind() const
{
    glBindTexture(GL_TEXTURE_2D, _id);
}

glm::vec2	 Texture2D::getSize() const
{
	return glm::vec2(_width, _height);
}

unsigned int Texture2D::getID() const
{
    return _id;
}

unsigned int *Texture2D::getIDPointer()
{
    return &_id;
}
unsigned int Texture2D::getWidth() const
{
    return _width;
}

unsigned int Texture2D::getHeight() const
{
    return _height;
}

unsigned int Texture2D::getInternalFormat() const
{
    return _internal_Format;
}

unsigned int Texture2D::getImageFormat() const
{
    return _image_Format;
}

void Texture2D::setInternalFormat(unsigned int internalFormat)
{
    _internal_Format = internalFormat;
}

void Texture2D::setImageFormat(unsigned int imageFormat)
{
    _image_Format = imageFormat;
}