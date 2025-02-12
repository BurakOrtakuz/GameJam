/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <burakortakuz@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:03:21 by bortakuz          #+#    #+#             */
/*   Updated: 2025/02/12 13:14:55 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP 250211L

/* **************************** [v] INCLUDES [v] **************************** */
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <Texture2D.hpp>
#include <SpriteRenderer.hpp>
/* **************************** [^] INCLUDES [^] **************************** */

// Container object for holding all state relevant for a single
// game object entity. Each object in the game likely needs the
// minimal of state as described within GameObject.

class GameObject
{
protected:
/* **************************** [v] VARIABLES [v] *************************** */
// MODERN DEFINES :)
	constexpr static glm::vec2	defaultPosition = glm::vec2(0.0f, 0.0f);
	constexpr static glm::vec2	defaultSize 	= glm::vec2(1.0f, 1.0f);
	constexpr static float		defaultRotation = 0.0f;	
// VARIABLES
	glm::vec2   _position, _size;
	glm::vec3   _color;
	float       _rotation;
	bool        _isSolid;   //__??__ TO-DO WTF
	bool        _destroyed; //__??__ TO-DO WTF
// RENDER STATE
	Texture2D   _sprite;
/* **************************** [^] VARIABLES [^] *************************** */
public:
/* ******************* [v] CONSTRUCTOR AND DESTRUCTOR [v] ******************* */
	GameObject(
		glm::vec2 pos		= defaultPosition,
		glm::vec2 size		= defaultSize,
		Texture2D sprite	= Texture2D(),
		glm::vec3 color		= glm::vec3(1.0f)
	);
	~GameObject();
/* ******************* [^] CONSTRUCTOR AND DESTRUCTOR [^] ******************* */
/* **************************** [v] GETTERS [v] ***************************** */
	glm::vec2	getPosition()	const;
	glm::vec2	getSize()		const;
	bool		isSolid()		const;
	bool		isDestroyed()	const;
/* **************************** [^] GETTERS [^] ***************************** */
/* **************************** [v] SETTERS [v] ***************************** */
	void		setSolid(bool solid);
	void		setPosition(glm::vec2 pos);
/* **************************** [^] SETTERS [^] ***************************** */
/* **************************** [v] FUNCTIONS [v] *************************** */
	virtual void draw(SpriteRenderer &renderer);
/* **************************** [^] FUNCTIONS [^] *************************** */
};

#endif