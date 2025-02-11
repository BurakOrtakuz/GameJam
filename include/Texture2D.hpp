#ifndef TEXTURE2D_HPP
#define TEXTURE2D_HPP

#include <glad/glad.h>

class Texture2D
{
private:
	unsigned int _id;
	// Image dimensions
	unsigned int _width, _height; 
	unsigned int _internal_Format; // format of texture object
	unsigned int _image_Format; // Format of loaded image
	// texture configuration
	unsigned int _wrap_S; // wrapping mode on S axis
	unsigned int _wrap_T; // wrapping mode on T axis
	unsigned int _filter_Min; // filtering mode if texture pixels < screen pixels
	unsigned int _filter_Max; // filtering mode if texture pixels > screen pixels
public:
	Texture2D();
	
	void generate(unsigned int width, unsigned int height, unsigned char* data);
	// binds the texture as the current active GL_TEXTURE_2D texture object
	void bind() const;
	unsigned int getID() const;
	unsigned int *getIDPointer();
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	unsigned int getInternalFormat() const;
	unsigned int getImageFormat() const;
	void setInternalFormat(unsigned int internalFormat);
	void setImageFormat(unsigned int imageFormat);
};

#endif // TEXTURE2D_HPP