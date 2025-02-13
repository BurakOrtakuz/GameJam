/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture2D.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:41:48 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/11 20:41:48 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <Texture2D.hpp>


Texture2D::Texture2D()
    : _width(0), _height(0), _internal_Format(GL_RGB), _image_Format(GL_RGB), _wrap_S(GL_REPEAT), _wrap_T(GL_REPEAT), _filter_Min(GL_LINEAR), _filter_Max(GL_LINEAR)
{
    glGenTextures(1, &_id);
}

void Texture2D::generate(unsigned int width, unsigned int height, unsigned char* data)
{
    _width = width;
    _height = height;
    // create Texture
    glBindTexture(GL_TEXTURE_2D, _id);
    glTexImage2D(GL_TEXTURE_2D, 0, _internal_Format, width, height, 0, _image_Format, GL_UNSIGNED_BYTE, data);
    // set Texture wrap and filter modes
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _wrap_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _wrap_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _filter_Min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _filter_Max);
    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::bind() const
{
    glBindTexture(GL_TEXTURE_2D, _id);
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