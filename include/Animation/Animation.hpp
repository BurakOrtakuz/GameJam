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

#include "FrameManager.hpp"

class Animation
{
	private:
		FrameManager	_frameManager;
		unsigned int	_currentFrame;
		unsigned int	_frameRate;
		unsigned int	_frameCount;
		bool			_isPlaying;
		bool			_isLooping;

		// Private constructor
		Animation() = delete;
		Animation(Animation const &) = delete;
		Animation &operator=(Animation const &) = delete;


	public:

		// Constructors
		Animation(std::vector<std::string> textures, bool alpha = false, unsigned int frameRate = 1, bool isLooping = true);
		Animation(std::vector<Texture2D> textures, unsigned int frameRate = 1, bool isLooping = true);
		Animation(const std::string &path, bool alpha = false, unsigned int frameRate = 1, bool isLooping = true);
		Animation(Texture2D texture, unsigned int frameRate = 1, bool isLooping = true);

		// Destructor
		~Animation();

		// Setters
		void	setCurrentFrame(unsigned int index);
		void	setFrameRate(unsigned int frameRate);
		void	setLooping(bool isLooping);
		void	setPlaying(bool isPlaying);

		// Getters
		Texture2D		getCurrentFrame();
		Texture2D		getFrame(unsigned int index);
		unsigned int	getSize();
		unsigned int	getFrameRate();
		bool			isLooping();
		bool			isPlaying();

		// member functions
		void	addFrame(const std::string &texture, bool alpha = false);
		void	addFrame(Texture2D texture);
		void	removeFrame(unsigned int index);
		void	update();
		void	play();
		void	stop();
		void	pause();
};

