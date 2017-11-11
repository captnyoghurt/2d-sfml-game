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
*  Menu of the battle.
*
*/

#pragma once

#include <list>
#include "../Battle/Battle.h"
#include "MenuChoice.h"

class MenuBattle
{
public:
	enum { BM_LEFT, BM_RIGHT, BM_DIALOG, BM_CHOICE, BM_TOTAL };

public:
	MenuBattle(Battle *b, ManageRessources &ress, ManageSurfaces &surf, int lastEventLayer);
	~MenuBattle();

public:
	/**
	* \brief Return the current active menu	.
	*
	* \return int object.
	*/
	int getActiveMenu() const;
	/**
	* \brief Return if the MenuBattle is updated	.
	*
	* \return bool object.
	*/
	bool getUpdated() const;
	/**
	* \brief Return if this menu is currently waiting for an action	.
	*
	* \return bool object.
	*/
	bool getIsBlocking() const;

	/**
	* \brief Return the menus with modifying possibilities	.
	*
	* \return std::vector<std::shared_ptr< object.
	*/
	std::vector<std::shared_ptr< Menu >>& getRealMenus();

	/**
	* \brief Modify the current menu	.
	*
	* \param am The new value.
	* \return int object.
	*/
	int setActiveMenu(const int &am);
	/**
	* \brief Modify if this menu is currently waiting for an action	.
	*
	* \param b The new value.
	* \return int object.
	*/
	int setIsBlocking(const bool &b);
	
	/**
	* \brief Tell the MenuBattle that it's updated	.
	*
	* \return int object.
	*/
	int gotUpdated();

	/**
	* \brief All the action functions for the menus	.
	*
	* \return int object.
	*/
	int af_MenuBattleDown(Game &g);
	int af_MenuBattleUp(Game &g);
	int af_MenuBattleRight(Game &g);
	int af_MenuBattleLeft(Game &g);
	int af_MenuBattleEnter(Game &g);

	/**
	* \brief Close all the menus	.
	*
	* \return int object.
	*/
	int close(ManageSurfaces &surf);

protected:
	/**
	* \brief Load the different menus	.
	*
	* \return int object.
	*/
	int load(Battle *b, ManageRessources &ress, ManageSurfaces &surf);

private:
	std::vector < std::shared_ptr< Menu > > m_menus;
	int m_activeMenu;
	bool m_updated;
	bool m_isBlocking;
};
