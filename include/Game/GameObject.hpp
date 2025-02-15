#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP 250211L

#include <SpriteRenderer.hpp>
#include <Texture2D.hpp>
#include <glm/glm.hpp>

#include "Collision.hpp"
#include "tag.hpp"

class GameObject
{
protected:
/* **************************** [v] VARIABLES [v] *************************** */
// MODERN DEFINES :)
	constexpr static glm::vec2	defaultPosition = glm::vec2(0.0f, 0.0f);
	constexpr static glm::vec2	defaultSize 	= glm::vec2(1.0f, 1.0f);
	constexpr static float		defaultRotation = 0.0f;
// VARIABLES
	glm::vec2	_position, _size;
	glm::vec3	_color;
	Collision	_collision;
	float		_rotation;
	bool		_isSolid;   //__??__ TO-DO WTF
	bool		_destroyed; //__??__ TO-DO WTF
	bool		_isReversed;
// RENDER STATE
	std::string   _sprite;
/* **************************** [^] VARIABLES [^] *************************** */
public:
/* ******************* [v] CONSTRUCTOR AND DESTRUCTOR [v] ******************* */
	GameObject(
		glm::vec2 pos		= defaultPosition,
		glm::vec2 size		= defaultSize,
		std::string sprite	= "",
		glm::vec3 color		= glm::vec3(1.0f)
	);
	~GameObject();
/* ******************* [^] CONSTRUCTOR AND DESTRUCTOR [^] ******************* */
/* **************************** [v] GETTERS [v] ***************************** */
	glm::vec2	getPosition()	const;
	glm::vec2	getSize()		const;
	bool		isSolid()		const;
	bool		isDestroyed()	const;
	Collision	getCollision()	const;
/* **************************** [^] GETTERS [^] ***************************** */
/* **************************** [v] SETTERS [v] ***************************** */
	void	setSolid(bool solid);
	virtual void	setPosition(glm::vec2 pos);
	void	setCollisionSize(glm::vec2 size);
	void	setCollisionPosition(glm::vec2 pos);
	void	setCollision(glm::vec2 pos, glm::vec2 size);
	void	setIsReversed(bool flip);
/* **************************** [^] SETTERS [^] ***************************** */
/* **************************** [v] FUNCTIONS [v] *************************** */
	void draw(SpriteRenderer &renderer);
	void	tagAdd(e_tag tag);
/* **************************** [^] FUNCTIONS [^] *************************** */
};

#endif /* GAMEOBJECT_HPP */
