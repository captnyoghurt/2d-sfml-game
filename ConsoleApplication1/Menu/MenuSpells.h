#pragma once

#include <memory>
#include "MenuDialogBox.h"
#include "MenuChoice.h"
#include "../Battle/Spell.h"

class MenuSpells :
	public Menu
{
public:
	MenuSpells(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~MenuSpells();

public:
	// Return the spells
	std::vector<Spell> getSpells() const;

	// Return the dialog box with modifying possibilities
	MenuDialogBox& getRealDialogBox();
	// Return the menu choice with modifying possibilities
	MenuChoice& getRealMenuChoices();
	// Return the spells with modifying possibilities
	std::vector<Spell>& getRealSpells();

	// Load the menu
	virtual int load(ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, std::vector<Spell> &spells);
	// Update surfaces
	virtual int update(Game &g);
	// Close the menu
	virtual int close(ManageSurfaces &surf);

protected:
	// Make a stringstream
	std::stringstream makeChoicesSS(std::vector<Spell> &spells);

public:
	MenuDialogBox m_dialogBox;
	MenuChoice m_choices;
	std::unique_ptr<std::vector<Spell>> m_spells;
};

