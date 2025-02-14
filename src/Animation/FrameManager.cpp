/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FrameManager.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:38:21 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/12 20:35:01 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FrameManager.hpp"

FrameManager::FrameManager(std::vector<std::string> textures, bool alpha)
	:	_head(nullptr), _current(nullptr), _size(0), _currentIndex(0)
{
	std::vector<std::string>::iterator it = textures.begin();
	while (it != textures.end())
	{
		addFrame(*it, alpha);
		it++;
	}
}

FrameManager::FrameManager(std::vector<Texture2D> textures)
{
	std::vector<Texture2D>::iterator it = textures.begin();
	while (it != textures.end())
	{
		addFrame(*it);
		it++;
	}
}

FrameManager::FrameManager(const std::string &path, bool alpha)
{
	addFrame(path, alpha);
}

FrameManager::FrameManager(Texture2D texture)
{
	addFrame(texture);
}

// Destructor
FrameManager::~FrameManager()
{
	frame *tmp = _head;
	while (tmp)
	{
		frame *next = tmp->next;
		delete tmp;
		tmp = next;
	}
}

// member functions
void	FrameManager::addFrame(const std::string &texture, bool alpha)
{
	frame *newFrame = new frame(texture, alpha);
	if (!_head)
	{
		_head = newFrame;
		_current = newFrame;
	}
	else
	{
		_current->addNextframe(newFrame);
		_current = newFrame;
	}
	_size++;
}

void	FrameManager::addFrame(Texture2D texture)
{
	frame *newFrame = new frame(texture);
	if (!_head)
	{
		_head = newFrame;
		_current = newFrame;
	}
	else
	{
		_current->addNextframe(newFrame);
		_current = newFrame;
	}
	_size++;
}

void	FrameManager::removeFrame(unsigned int index)
{
	if (index >= _size)
		return;
	frame *tmp = _head;
	for (unsigned int i = 0; i < index; i++)
		tmp = tmp->next;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (tmp == _head)
		_head = tmp->next;
	if (tmp == _current)
		_current = tmp->prev;
	delete tmp;
	_size--;
}

void	FrameManager::setCurrentFrame(unsigned int index)
{
	if (index >= _size)
		return;
	frame *tmp = _head;
	for (unsigned int i = 0; i < index; i++)
		tmp = tmp->next;
	_current = tmp;
}

Texture2D		FrameManager::getCurrentFrame()
{
	return (_current->texture);
}

Texture2D		FrameManager::getFrame(unsigned int index)
{
	if (index >= _size)
		return (Texture2D());
	frame *tmp = _head;
	for (unsigned int i = 0; i < index; i++)
		tmp = tmp->next;
	return (tmp->texture);
}

unsigned int	FrameManager::getSize()
{
	return (_size);
}

