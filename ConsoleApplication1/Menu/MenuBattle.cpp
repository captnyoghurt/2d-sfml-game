#include "MenuBattle.h"
#include "../Game.h"


MenuBattle::MenuBattle(Battle *b)
{
	m_updated = true;
}


MenuBattle::~MenuBattle()
{
}


// Return if the MenuBattle is updated
bool MenuBattle::getUpdated() const
{
	return m_updated;
}


// Return the current active menu
int MenuBattle::getActiveMenu() const
{
	return m_activeMenu;
}


// Return the menus with modifying possibilities
std::vector<Menu*>& MenuBattle::getRealMenus()
{
	return m_menus;
}


// Modify the current menu
int MenuBattle::setActiveMenu(const int &am)
{
	if (!((unsigned)am < MenuBattle::BM_TOTAL))
		return -1;

	m_activeMenu = am;

	gotUpdated();

	return 0;
}


// Tell the MenuBattle that it's updated
int MenuBattle::gotUpdated()
{
	m_updated = true;

	return 0;
}


// All the action functions for the menus
int MenuBattle::af_MenuBattleDown(Game &g)
{
	gotUpdated();

	return 0;
}


int MenuBattle::af_MenuBattleUp(Game &g)
{
	gotUpdated();

	return 0;
}


int MenuBattle::af_MenuBattleEnter(Game &g)
{
	return 0;
}