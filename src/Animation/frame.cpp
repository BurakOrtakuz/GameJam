/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:16:19 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/13 16:10:32 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frame.hpp"
#include "Game.hpp"

frame::frame(Texture2D texture)
	: texture(texture), next(nullptr), prev(nullptr)
{
}

frame::frame(std::string texture, bool alpha)
	: next(nullptr), prev(nullptr)
{
	// TODO: hata kontrolü yapılacak
	//this->texture = ResourceManager::newTexture(texture.c_str(), alpha, texture);
}

frame::frame()
	: next(nullptr), prev(nullptr)
{

}

void	frame::addNextframe(frame *next)
{
	this->next = next;
	next->prev = this;
}

void	frame::addPrevframe(frame *prev)
{
	this->prev = prev;
	if (prev)
		prev->next = this;
}
