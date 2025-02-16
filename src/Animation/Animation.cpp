/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:16 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/15 01:48:48 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animation/Animation.hpp>
#include <iostream>
// Constructors

Animation::Animation()
{

}

Animation::Animation(
	std::vector<std::string> textures,
	bool alpha,
	unsigned int frameRate,
	bool isLooping)
{
	(void)alpha;
	_textures = textures;
	_isLooping = isLooping;
	_frameRate = frameRate;
	_isPlaying = false;
	_frameCount = 0;
	_currentFrame = 0;
}

Animation::Animation(const Animation &animation)
{
	*this = animation;
}

Animation &Animation::operator=(const Animation &animation)
{
	_textures = animation._textures;
	_isLooping = animation._isLooping;
	_frameRate = animation._frameRate;
	_isPlaying = animation._isPlaying;
	_frameCount = animation._frameCount;
	_currentFrame = animation._currentFrame;
	return (*this);
}

// Destructor
Animation::~Animation()
{
}


// Setters
void	Animation::setCurrentFrame(unsigned int index)
{
	this->_currentFrame = index;
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

unsigned int Animation::getCurrentFrameIndex() const
{
	return (_currentFrame);
}

unsigned int Animation::getFrameRate() const
{
	return (_frameRate);
}

unsigned int Animation::getFrameCount() const
{
	return (_frameCount);
}

bool Animation::isPlaying() const
{
	return (_isPlaying);
}

bool Animation::isLooping() const
{
	return (_isLooping);
}

std::string Animation::getCurrentFrame() {
	return _textures[_currentFrame];
}

std::string Animation::getFrame(unsigned int index) {
	// Add bounds checking if needed
	return _textures[index];
}
std::string	Animation::getNextFrame()
{
	if(_currentFrame == _textures.size() - 1)
		_currentFrame = 0;
	else
		_currentFrame++;
	return (_textures[_currentFrame]);
}

bool Animation::getLoop()
{
	return (_isLooping);
}

unsigned int	Animation::getSize()
{
	return (_textures.size());
}

// member functions
void	Animation::addFrame(const std::string &texture, bool alpha)
{
	_textures.emplace_back(texture.c_str(), alpha);
}

void	Animation::removeFrame(unsigned int index)
{
	if (index >= _textures.size())
		return;
	_textures.erase(_textures.begin() + index);
}

std::string Animation::update(float deltaTime) {
	if (_isPlaying) {
		_frameCount += deltaTime;
		float frameDuration = 1.0f / _frameRate; // Use frame rate
		if (_frameCount >= frameDuration) {
			_frameCount -= frameDuration; // Subtract to preserve residual time
			if(_isLooping)
			{
				_currentFrame = (_currentFrame + 1) % _textures.size();
			}
			else if (_currentFrame + 1 <  _textures.size())
				_currentFrame++;
			else
			{
				std::cout << "GIRDI" << std::endl;
				_currentFrame = 0;
				_isPlaying =false;
				return "1";
			}
		}
		return _textures[_currentFrame];
	}
	return "1";
}
void	Animation::play()
{
	_isPlaying = true;
}

void	Animation::stop()
{
	_isPlaying = false;
	_currentFrame = 0;
}

void	Animation::pause()
{
	_isPlaying = false;
}

