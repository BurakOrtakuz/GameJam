/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TagManager.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemirbu <bdemirbu@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:27:48 by bdemirbu          #+#    #+#             */
/*   Updated: 2025/02/14 14:44:47 by bdemirbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAGMANAGER_HPP
# define TAGMANAGER_HPP

#include "tag.hpp"
#include "GameObject.hpp"

# include <map>
# include <vector>
# include <string>

class TagManager
{
	private:
		static	std::map<e_tag, std::vector<GameObject *> >	_tags;

		// private constructor
		TagManager() = delete;
		TagManager(TagManager const &src) = delete;
		~TagManager();
		TagManager &operator=(TagManager const &src) = delete;
	public:

		// member functions
		static void							addTag(e_tag tag, GameObject *object);
		static std::vector<GameObject *>	getTags(e_tag tag);

};

#endif // TAGMANAGER_HPP
