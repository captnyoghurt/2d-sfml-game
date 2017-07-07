#pragma once

#include "M_choice.h"
#include "Menu.h"
#include <vector>

class Health;

class MenuBattleSide : public Menu
{
public:
	enum e_menuBattleSideBarType{MENU_BATTLE_ENEMIE, MENU_BATTLE_ALLIE, MENU_BATTLE_TOTAL};
	enum e_menuBattleSideItems{NAME, HP_TEXT, HP_IMAGE, MP_TEXT, MP_IMAGE, TP_TEXT, TP_IMAGE, MENU_BATTLE_ITEM_TOTAL};

public:
	MenuBattleSide(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer, int type);
	~MenuBattleSide();

public:
	// Return the cursor for the right surface
	std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator getCursor();
	// Return the current selected choice
	int getSelectedChoice() const;
	// Return the maximum number of choices
	int getNumberMaxChoices() const;

	// Return all the choices with modifying possibilities
	std::vector< std::shared_ptr<M_choice> >& getChoices();

	// Modify the current selected choice
	int setSelectedChoice(const int &s);
	// Modify the maximum number of choices
	int setNumberMaxChoices(const int &c);


	// Update the surfaces according to the ressource given
	int updateBar(int n, MenuBattleSide::e_menuBattleSideItems type, int act, int max);
	// Update health bar & text
	int updateHealth(int n, const Health& hp);

	// Load the menu
	virtual int load(ManageRessources& ress, ManageSurfaces& surf, const int &x, const int &y, const int &w = -1, const int &h = -1);
	// Update surfaces
	virtual int update(Game &g);
	// Close the menu
	virtual int close(ManageSurfaces& surf);
private:
	std::vector < std::shared_ptr<M_choice> > m_choices;
	std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator m_cursorSurfaceRight;
	int m_selectedChoice;
	int m_numberMaxChoices;
	int m_barType;
};

