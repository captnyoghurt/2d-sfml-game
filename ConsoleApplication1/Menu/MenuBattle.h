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
	// Return the current active menu
	int getActiveMenu() const;
	// Return if the MenuBattle is updated
	bool getUpdated() const;
	// Return if this menu is currently waiting for an action
	bool getIsBlocking() const;

	// Return the menus with modifying possibilities
	std::vector<std::shared_ptr< Menu >>& getRealMenus();

	// Modify the current menu
	int setActiveMenu(const int &am);
	// Modify if this menu is currently waiting for an action
	int setIsBlocking(const bool &b);
	
	// Tell the MenuBattle that it's updated
	int gotUpdated();

	// All the action functions for the menus
	int af_MenuBattleDown(Game &g);
	int af_MenuBattleUp(Game &g);
	int af_MenuBattleRight(Game &g);
	int af_MenuBattleLeft(Game &g);
	int af_MenuBattleEnter(Game &g);

	// Close all the menus
	int close(ManageSurfaces &surf);

protected:
	// Load the different menus
	int load(Battle *b, ManageRessources &ress, ManageSurfaces &surf);

private:
	std::vector < std::shared_ptr< Menu > > m_menus;
	int m_activeMenu;
	bool m_updated;
	bool m_isBlocking;
};

