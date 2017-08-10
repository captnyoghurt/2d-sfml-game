#include "MenuSpells.h"



MenuSpells::MenuSpells(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer) :
	m_dialogBox(ress, surf, lastEventLayer),
	m_choices(ress, surf, lastEventLayer)
{
}


MenuSpells::~MenuSpells()
{
}


// Return the dialog box with modifying possibilities
MenuDialogBox& MenuSpells::getRealDialogBox()
{
	return m_dialogBox;
}


// Return the menu choice with modifying possibilities
MenuChoice& MenuSpells::getRealMenuChoices()
{
	return m_choices;
}