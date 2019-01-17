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
*  Menu on the sides of the battle.
*
*/

#pragma once

#include "M_choice.h"
#include "Menu.h"
#include <vector>

class TeamBattle;
class Enemies;
class Health;
class Mana;
class SkillPoints;

class MenuBattleSide : public Menu
{
public:
	enum e_menuBattleSideBarType{MENU_BATTLE_ENEMIE, MENU_BATTLE_ALLIE, MENU_BATTLE_TOTAL};
	enum e_menuBattleSideItems{NAME, HP_TEXT, HP_IMAGE, MP_TEXT, MP_IMAGE, TP_TEXT, TP_IMAGE, MENU_BATTLE_ITEM_TOTAL};

public:
	MenuBattleSide(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer, int type);
	~MenuBattleSide();

public:
	/**
	* \brief Return the cursor for the right surface	.
	*
	* \return std::list object.
	*/
	std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator getCursor();
	/**
	* \brief Return the current selected choice	.
	*
	* \return int object.
	*/
	int getSelectedChoice() const;
	/**
	* \brief Return the maximum number of choices	.
	*
	* \return int object.
	*/
	int getNumberMaxChoices() const;

	/**
	* \brief Return all the choices with modifying possibilities	.
	*
	* \return std::vector< object.
	*/
	std::vector< std::shared_ptr<M_choice> >& getChoices();

	/**
	* \brief Modify if the menu should be shown or not	.
	*
	* \param b The new value.
	* \return virtual object.
	*/
	virtual int setShown(const bool &b);
	/**
	* \brief Modify the current selected choice	.
	*
	* \param s The new value.
	* \return int object.
	*/
	int setSelectedChoice(const int &s);
	/**
	* \brief Modify the maximum number of choices	.
	*
	* \param c The new value.
	* \return int object.
	*/
	int setNumberMaxChoices(const int &c);

	/**
	* \brief Update the surfaces according to the ressource given	.
	*
	* \return int object.
	*/
	int updateBar(int n, MenuBattleSide::e_menuBattleSideItems type, int act, int max);
	/**
	* \brief Update health bar & text	.
	*
	* \return int object.
	*/
	int updateHealth(int n, const Health& hp);
	/**
	* \brief Update mana bar & text	.
	*
	* \return int object.
	*/
	int updateMana(int n, const Mana& mp);
	/**
	* \brief Update skillpoints bar & text	.
	*
	* \return int object.
	*/
	int updateSkillPoints(int n, const SkillPoints& sp);

	/**
	* \brief Load with an allie team	.
	*
	* \return int object.
	*/
	int loadWithEnemies(ManageRessources& ress, ManageSurfaces& surf, Enemies &enemies);
	/**
	* \brief Load with an enemie team	.
	*
	* \return int object.
	*/
	int loadWithAllies(ManageRessources& ress, ManageSurfaces& surf, TeamBattle &allies);

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
	int useCorrectFont(int i, Game &g);

private:
	std::vector < std::shared_ptr<M_choice> > m_choices;
	std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator m_cursorSurfaceRight;
	int m_selectedChoice;
	int m_numberMaxChoices;
	int m_barType;
};

////////////////////////////////////////////////////////////

int af_MenuBattleSideAllyEnter(int n, Game &g);
int af_MenuBattleSideEnemyEnter(int n, Game &g);