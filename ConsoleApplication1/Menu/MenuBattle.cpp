#include "MenuBattle.h"



MenuBattle::MenuBattle(Battle *b)
{
}


MenuBattle::~MenuBattle()
{
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

	return 0;
}