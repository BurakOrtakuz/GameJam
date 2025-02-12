/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:16:19 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/12 20:16:24 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Texture2D.hpp>
#include <string>

struct frame
{
	Texture2D		texture;
	struct frame	*next;
	struct frame	*prev;

	frame(Texture2D texture);
	frame(std::string texture, bool alpha = false);
	frame();

	void	addNextframe(frame *next);
	void	addPrevframe(frame *next);
};
