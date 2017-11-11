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
*  A physic hitbox, to see if there is a collision.
*
*/

#pragma once

#include <SFML/Graphics.hpp>

class Hitbox
{
public:
	Hitbox();
	Hitbox(const int &id, const int &x, const int &y, const int &w, const int &h);
	Hitbox(const int &id, const sf::Rect<int> &r);
	Hitbox(const Hitbox &hb);
	~Hitbox();

	Hitbox& operator=(const Hitbox &hb);
public:
	/**
	* \brief Return the id of the Hitbox	.
	*
	* \return int object.
	*/
	int getId() const;
	/**
	* \brief Return the abciss of the Hitbox	.
	*
	* \return int object.
	*/
	int getX() const;
	/**
	* \brief Return the y position of the Hitbox	.
	*
	* \return int object.
	*/
	int getY() const;
	/**
	* \brief Return the width of the Hitbox	.
	*
	* \return int object.
	*/
	int getWidth() const;
	/**
	* \brief Return the height of the Hitbox	.
	*
	* \return int object.
	*/
	int getHeight() const;

	/**
	* \brief Modify the id of the Hitbox	.
	*
	* \param id The new value.
	* \return int object.
	*/
	int setId(const int &id);
	/**
	* \brief Modify the abciss of the Hitbox	.
	*
	* \param x The new value.
	* \return int object.
	*/
	int setX(const int &x);
	/**
	* \brief Modify the y position of the Hitbox	.
	*
	* \param y The new value.
	* \return int object.
	*/
	int setY(const int &y);
	/**
	* \brief Modify the width of the Hitbox	.
	*
	* \param w The new value.
	* \return int object.
	*/
	int setWidth(const int &w);
	/**
	* \brief Modify the height of the Hitbox	.
	*
	* \param h The new value.
	* \return int object.
	*/
	int setHeight(const int &h);

	/**
	* \brief Modify x & y of the Hitbox	.
	*
	* \param dy The new value.
	* \return int object.
	*/
	int move(const int &dx, const int &dy);
	/**
	* \brief Move to a position	.
	*
	* \return int object.
	*/
	int moveTo(const int &x, const int &y);

public:
	int m_id;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};
