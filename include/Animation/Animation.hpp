/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:15:16 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/13 14:29:55 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_HPP
# define ANIMATION_HPP

#include <vector>
#include <Texture2D.hpp>
#include <iostream>
#include <string>
class Animation
{
	private:
		std::vector<std::string>	_textures;
		unsigned int	_currentFrame;
		unsigned int	_frameRate;
		float			_frameCount;
		bool			_isPlaying;
		bool			_isLooping;

		// Private constructor
		
		
		public:
		
		Animation();
		// Constructors
		Animation(std::vector<std::string> textures, unsigned int frameRate = 1, bool isLooping = false);

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
		std::string			getCurrentFrame();
		std::string			getFrame(unsigned int index);
		std::string		getNextFrame();
		unsigned int	getSize();

		// member functions
		void	addFrame(const std::string &texture, bool alpha = false);
		void	removeFrame(unsigned int index);
		Texture2D	&update(float deltaTime);
		void	play();
		void	stop();
		void	pause();
};

#endif // ANIMATION_HPP
