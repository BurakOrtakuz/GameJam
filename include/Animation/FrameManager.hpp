/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FrameManager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:27:54 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/13 16:08:05 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frame.hpp"

#include <vector>
#include <string>

class FrameManager
{
	private:
		frame			*_head;
		frame			*_current;
		unsigned int	_size;
		unsigned int	_currentIndex;


		// Private constructor
		FrameManager() = delete;
		FrameManager(FrameManager const &) = delete;

		// Private operator
		FrameManager &operator=(FrameManager const &) = delete;
	public:
		// Constructors
		FrameManager(std::vector<std::string> textures, bool alpha = false);
		FrameManager(std::vector<Texture2D> textures);
		FrameManager(const std::string &path, bool alpha = false);
		FrameManager(Texture2D texture);

		// Destructor
		~FrameManager();

		// Setters
		void	setCurrentFrame(unsigned int index);

		// Getters
		Texture2D		getCurrentFrame();
		Texture2D		getFrame(unsigned int index);
		unsigned int	getSize();

		// member functions
		void	addFrame(const std::string &texture, bool alpha = false);
		void	addFrame(Texture2D texture);
		void	removeFrame(unsigned int index);
};
