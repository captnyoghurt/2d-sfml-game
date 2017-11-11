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
*  Basic menu.
*
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "../Map/ManageRessources.h"
#include "../Map/ManageSurfaces.h"

class Game;

class Menu
{
public:
	Menu(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~Menu();

public:
	/**
	* \brief Return if the menu is shown	.
	*
	* \return bool object.
	*/
	bool getShown() const;
	/**
	* \brief Return if the menu is initialized	.
	*
	* \return bool object.
	*/
	bool getInitialized() const;
	/**
	* \brief Return the background with modifying possibilities	.
	*
	* \return std::list<std::pair<ManageSurfaces::e_thing, object.
	*/
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getBackground();
	/**
	* \brief Return the position X of the menu	.
	*
	* \return int object.
	*/
	int getX() const;
	/**
	* \brief Return the position Y of the menu	.
	*
	* \return int object.
	*/
	int getY() const;
	/**
	* \brief Return the width of the menu	.
	*
	* \return int object.
	*/
	int getWidth() const;
	/**
	* \brief Return the height of the menu	.
	*
	* \return int object.
	*/
	int getHeight() const;

	/**
	* \brief Modify if the menu should be shown or not	.
	*
	* \param b The new value.
	* \return virtual object.
	*/
	virtual int setShown(const bool &b);

	/**
	* \brief Load the menu	.
	*
	* \return virtual object.
	*/
	virtual int load(ManageRessources& ress, ManageSurfaces& surf, const int &x, const int &y, const int &w = -1, const int &h = -1);
	/**
	* \brief Update surfaces	.
	*
	* \return virtual object.
	*/
	virtual int update(Game &g);
	/**
	* \brief Close the menu	.
	*
	* \return virtual object.
	*/
	virtual int close(ManageSurfaces& surf);
protected:
	bool m_shown;
	bool m_initialized;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_background;
	int m_lastEventLayer;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};
