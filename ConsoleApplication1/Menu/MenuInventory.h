#pragma once

#include "../Items/Item.h"
#include "Menu.h"
#include "MenuDialogBox.h"
#include "MenuChoice.h"


class MenuInventory :
	public Menu
{
public:
	MenuInventory(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~MenuInventory();

public:
	// Return the spells
	std::vector< std::pair<Item, int> > getItems() const;

	// Return the dialog box with modifying possibilities
	MenuDialogBox& getRealDialogBox();
	// Return the menu choice with modifying possibilities
	MenuChoice& getRealMenuChoices();
	// Return the spells with modifying possibilities
	std::vector< std::pair<Item, int> >& getRealItems();

	// Load the menu
	virtual int load(ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, std::list< std::pair<Item, int> > &items, std::vector<bool> enabledTypes);
	// Update surfaces
	virtual int update(Game &g);
	// Close the menu
	virtual int close(ManageSurfaces &surf);

protected:
	std::stringstream makeChoicesSS(std::list< std::pair<Item, int> > &items);

private:
	bool m_initialized;
	MenuDialogBox m_dialogBox;
	MenuChoice m_choices;
	std::vector< std::pair<Item, int> > m_items;
};

