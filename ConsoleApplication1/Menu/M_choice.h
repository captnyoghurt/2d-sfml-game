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
*  A choice in the menu choice.
*
*/

#pragma once

#include <list>
#include <memory>
#include "../Event/IG_Action.h"
#include "../Map/ManageRenderTexture.h"
#include "../Map/ManageSurfaces.h"


class M_choice
{
public:
	M_choice();
	M_choice(const M_choice & ch);
	~M_choice();

	M_choice& operator=(const M_choice &ch);
public:
	/**
	* \brief Return if the choice has been initialized	.
	*
	* \return bool object.
	*/
	bool getInitialized() const;
	/**
	* \brief Return if the choice should be shown	.
	*
	* \return bool object.
	*/
	bool getShown() const;
	/**
	* \brief Return if the choice is enabled	.
	*
	* \return bool object.
	*/
	bool getEnabled() const;
	/**
	* \brief Return the surface of the choice	.
	*
	* \return std::list<std::pair<ManageSurfaces::e_thing, object.
	*/
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getSurface();
	/**
	* \brief Return the action made by the choice	.
	*
	* \return IG_Action object.
	*/
	IG_Action getAction() const;
	/**
	* \brief Return the position X of the choice on the screen	.
	*
	* \return int object.
	*/
	int getX() const;
	/**
	* \brief Return the position Y of the choice on the screen	.
	*
	* \return int object.
	*/
	int getY() const;

	/**
	* \brief Return the surface of the choice with modifying possibilities	.
	*
	* \return std::list<std::pair<ManageSurfaces::e_thing, object.
	*/
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealSurface();
	/**
	* \brief Return the render texture manager with modifying possibilities	.
	*
	* \return ManageRenderTexture& object.
	*/
	ManageRenderTexture& getRealRenderTextureManager();

	/**
	* \brief Modify if the choice should be shown	.
	*
	* \param dy The new value.
	* \return int object.
	*/
	int setShown(const bool &b, const int &dx, const int &dy);
	/**
	* \brief Modify if the choice should be enabled	.
	*
	* \param b The new value.
	* \return int object.
	*/
	int setEnabled(const bool &b);
	/**
	* \brief Modify the action made by the choice	.
	*
	* \param act The new value.
	* \return int object.
	*/
	int setAction(IG_Action &act);
	/**
	* \brief Modify the position X of the choice on the screen	.
	*
	* \param x The new value.
	* \return int object.
	*/
	int setX(const int &x);
	/**
	* \brief Modify the position Y of the choice on the screen	.
	*
	* \param y The new value.
	* \return int object.
	*/
	int setY(const int &y);

	/**
	* \brief Load the choice	.
	*
	* \return int object.
	*/
	int load(ManageSurfaces& surf, const std::string &str, sf::Font &f, const int &x, const int &y, const bool &sh, IG_Action &, const int &w = 0, const int &h = 0);
	/**
	* \brief Clear the surfaces of the choice	.
	*
	* \return int object.
	*/
	int clear(ManageSurfaces &surf);
private:
	bool m_initialized;
	bool m_shown;
	bool m_enabled;
	ManageRenderTexture m_textureManager;
	IG_Action m_action;
	int m_x;
	int m_y;

};
