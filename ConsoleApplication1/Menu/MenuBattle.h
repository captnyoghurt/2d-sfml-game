#pragma once

#include <list>
#include "../Battle/Battle.h"
#include "MenuChoice.h"

class MenuBattle
{
public:
	enum { BM_LEFT, BM_RIGHT, BM_DIALOG, BM_CHOICE, BM_TOTAL };

public:
	MenuBattle(Battle *b);
	~MenuBattle();

public:
	// Return the current active menu
	int getActiveMenu() const;
	// Return if the MenuBattle is updated
	bool getUpdated() const;

	// Return the menus with modifying possibilities
	std::vector<Menu*>& getRealMenus();

	// Modify the current menu
	int setActiveMenu(const int &am);
	
	// Tell the MenuBattle that it's updated
	int gotUpdated();

	// All the action functions for the menus
	int af_MenuBattleDown(Game &g);
	int af_MenuBattleUp(Game &g);
	int af_MenuBattleEnter(Game &g);
private:
	std::vector<Menu*> m_menus;
	int m_activeMenu;
	bool m_updated;
};

