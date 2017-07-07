#include <memory>
#include "MenuBattle.h"
#include "../Game.h"
#include "MenuBattleSide.h"


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
	if (m_activeMenu != MenuBattle::BM_LEFT && m_activeMenu != MenuBattle::BM_RIGHT)
		return 1;

	if ((unsigned)static_cast<MenuBattleSide*>(m_menus.at(m_activeMenu))->getSelectedChoice() <= static_cast<MenuBattleSide*>(m_menus.at(m_activeMenu))->getChoices().size() - 1)
	{
		static_cast<MenuBattleSide*>(m_menus.at(m_activeMenu))->setSelectedChoice(static_cast<MenuBattleSide*>(m_menus.at(m_activeMenu))->getSelectedChoice() + 1);

		gotUpdated();
	}

	return 0;
}


int MenuBattle::af_MenuBattleUp(Game &g)
{
	if (m_activeMenu != MenuBattle::BM_LEFT && m_activeMenu != MenuBattle::BM_RIGHT)
		return 1;

	if (static_cast<MenuBattleSide*>(m_menus.at(m_activeMenu))->getSelectedChoice() > 0)
	{
		static_cast<MenuBattleSide*>(m_menus.at(m_activeMenu))->setSelectedChoice(static_cast<MenuBattleSide*>(m_menus.at(m_activeMenu))->getSelectedChoice() - 1);

		gotUpdated();
	}

	return 0;
}


int MenuBattle::af_MenuBattleEnter(Game &g)
{
	return 0;
}