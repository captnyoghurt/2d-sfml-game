#pragma once

#include "MenuDialogBox.h"
#include "MenuChoice.h"
#include "../Battle/Spell.h"

class MenuSpells
{
public:
	MenuSpells(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~MenuSpells();

public:
	// Return the dialog box with modifying possibilities
	MenuDialogBox& getRealDialogBox();
	// Return the menu choice with modifying possibilities
	MenuChoice& getRealMenuChoices();

public:
	MenuDialogBox m_dialogBox;
	MenuChoice m_choices;
};

