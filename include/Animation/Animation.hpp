/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:16 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/15 00:53:01 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_HPP
# define ANIMATION_HPP

#include <vector>
#include <iostream>
#include <Texture2D.hpp>
#include <string>
class Animation
{
public:
	std::vector<std::string>	_textures;
	unsigned int	_currentFrame;
	unsigned int	_frameRate;
	float			_frameCount;
	bool			_isPlaying;
	bool			_isLooping;

public:
// Constructors	
	Animation();
	Animation(
		std::vector<std::string> textures,
		bool alpha = false,
		unsigned int frameRate = 1,
		bool isLooping = false
	);
	Animation(const Animation &animation);
	Animation &operator=(const Animation &animation);
	// Destructor
	~Animation();

	// Setters
	void	setCurrentFrame(unsigned int index);
	void	setFrameRate(unsigned int frameRate);
	void	setLooping(bool isLooping);
	void	setPlaying(bool isPlaying);

	// Getters
	unsigned int	getCurrentFrameIndex() const;
	unsigned int	getFrameRate() const;
	unsigned int	getFrameCount() const;
	bool			isPlaying() const;
	bool			isLooping() const;
	std::string		getCurrentFrame();
	std::string		getFrame(unsigned int index);
	std::string		getNextFrame();
	unsigned int	getSize();

	// member functions
	void			addFrame(const std::string &texture, bool alpha = false);
	void			removeFrame(unsigned int index);
	std::string		update(float deltaTime);
	void			play();
	void			stop();
	void			pause();
};

#endif // ANIMATION_HPP
