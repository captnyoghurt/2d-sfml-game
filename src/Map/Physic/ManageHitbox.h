/**
*  @file
*  @author  Paul Coignet
*  @date    11 / 11 / 2017
*  @version 0.1
*
*  @brief Class header.
*
*  @section DESCRIPTION
*
*  Manage hitbox to see collision.
*
*/

#pragma once

#include <map>
#include <memory>
#include <deque>
#include "Hitbox.h"

class ManageHitbox
{
public:
	enum e_CollisionType { COLLISION_NONE, COLLISION_WATER, COLLISION_HARD };

public:
	ManageHitbox();
	~ManageHitbox();

public:
	/**
	* \brief Return the id counter	.
	*
	* \return int object.
	*/
	int getIdCount() const;
	/**
	* \brief Return the tile hitbox	.
	*
	* \return std::map< object.
	*/
	std::map< std::pair<int, int>, Hitbox > getTileHitbox() const;
	/**
	* \brief Return the normal hitbox	.
	*
	* \return std::deque< object.
	*/
	std::deque< Hitbox > getHitbox() const;

	/**
	* \brief Return the tile hitbox with modifying possibilities	.
	*
	* \return std::map< object.
	*/
	std::map< std::pair<int, int>, Hitbox >& getRealTileHitbox();
	/**
	* \brief Return the normal hitbox with modifying possibilities	.
	*
	* \return std::deque< object.
	*/
	std::deque< Hitbox >& getRealHitbox();

	/**
	* \brief Add a tile hitbox with checking the other layer	.
	*
	* \return Hitbox& object.
	*/
	Hitbox& addTopTileHitbox(const int &tx, const int &ty, const Hitbox& hb);
	/**
	* \brief Add a tile hitbox	.
	*
	* \return Hitbox& object.
	*/
	Hitbox& addTileHitbox(const int &tx, const int &ty, const Hitbox& hb);
	/**
	* \brief Add a hitbox	.
	*
	* \return Hitbox& object.
	*/
	Hitbox& addHitbox(const Hitbox& hb, const int &id = -1);

	/**
	* \brief Give the tile hitbox	.
	*
	* \return Hitbox& object.
	*/
	Hitbox& at(const int &tx, const int &ty);

	/**
	* \brief Return the rect of tile where the hitbox is	.
	*
	* \return sf::Rect<int> object.
	*/
	sf::Rect<int> rectTilePosition(const Hitbox &hb);

	/**
	* \brief Return if the hitbox will collide	.
	*
	* \return e_CollisionType object.
	*/
	e_CollisionType willCollide(const Hitbox &hb, const int &dx, const int &dy);
	/**
	* \brief Return if the hitbox is colliding	.
	*
	* \return e_CollisionType object.
	*/
	e_CollisionType collision(const Hitbox &hb);
	/**
	* \brief Return if the two hitbox are colliding	.
	*
	* \return e_CollisionType object.
	*/
	e_CollisionType areColliding(const Hitbox &hb1, const Hitbox &hb2);

private:
	int m_idCount;
	std::map< std::pair<int, int>, Hitbox > m_tileHitbox;
	std::deque< Hitbox > m_hitbox;
};
