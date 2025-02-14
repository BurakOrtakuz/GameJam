/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TagManager.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:41:31 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 14:43:59 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "TagManager.hpp"

std::map<e_tag, std::vector<GameObject *> >	TagManager::_tags;

void	TagManager::addTag(e_tag tag, GameObject *object)
{
	_tags[tag].push_back(object);
}

std::vector<GameObject *>	TagManager::getTags(e_tag tag)
{
	return (_tags[tag]);
}

