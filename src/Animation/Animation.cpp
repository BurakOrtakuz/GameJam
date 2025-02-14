/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:16 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/13 14:42:50 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animation/Animation.hpp>

// Constructors
Animation::Animation(std::vector<std::string> textures, bool alpha, unsigned int frameRate, bool isLooping) : _frameManager(textures, alpha)
{

}

Animation::Animation(std::vector<Texture2D> textures, unsigned int frameRate, bool isLooping) : _frameManager(textures)
{

}

Animation::Animation(const std::string &path, bool alpha, unsigned int frameRate, bool isLooping) : _frameManager(path, alpha)
{

}

Animation::Animation(Texture2D texture, unsigned int frameRate, bool isLooping) : _frameManager(texture)
{

}


// Destructor
Animation::~Animation()
{

}


// Setters
void	Animation::setCurrentFrame(unsigned int index)
{
	this->_frameManager.setCurrentFrame(index);
}

void	Animation::setFrameRate(unsigned int frameRate)
{
	this->_frameRate = frameRate;
}

void	Animation::setLooping(bool isLooping)
{
	this->_isLooping = isLooping;
}

void	Animation::setPlaying(bool isPlaying)
{
	this->_isPlaying = isPlaying;
}


// Getters
Texture2D		Animation::getCurrentFrame()
{
	return (_frameManager.getCurrentFrame());
}

Texture2D		Animation::getFrame(unsigned int index)
{
	return (_frameManager.getFrame(index));
}

unsigned int	Animation::getSize()
{
	return (_frameManager.getSize());
}

unsigned int	Animation::getFrameRate()
{
	return (_frameRate);
}

bool			Animation::isLooping()
{
	return (_isLooping);
}

bool			Animation::isPlaying()
{
	return (_isPlaying);
}


// member functions
void	Animation::addFrame(const std::string &texture, bool alpha)
{
	this->_frameManager.addFrame(texture, alpha);
}

void	Animation::addFrame(Texture2D texture)
{
	this->_frameManager.addFrame(texture);
}

void	Animation::removeFrame(unsigned int index)
{
	this->_frameManager.removeFrame(index);
}

void	Animation::update()
{

}

void	Animation::play()
{
}

void	Animation::stop()
{

}

void	Animation::pause()
{

}

