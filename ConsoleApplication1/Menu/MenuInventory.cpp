#include "MenuInventory.h"



MenuInventory::MenuInventory(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer) :
	Menu(ress, surf, lastEventLayer),
	m_dialogBox(ress, surf, lastEventLayer),
	m_choices(ress, surf, lastEventLayer),
	m_initialized(false)
{
	surf.deleteSurface(m_background);
}


MenuInventory::~MenuInventory()
{
}


// Return the spells
std::vector<Item> MenuInventory::getItems() const
{
	return *m_items;
}


// Return the dialog box with modifying possibilities
MenuDialogBox& MenuInventory::getRealDialogBox()
{
	return m_dialogBox;
}


// Return the menu choice with modifying possibilities
MenuChoice& MenuInventory::getRealMenuChoices()
{
	return m_choices;
}


// Return the spells with modifying possibilities
std::vector<Item>& MenuInventory::getRealItems()
{
	return *m_items;
}


// Load the menu
int MenuInventory::load(ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, std::vector<Item> &spells)
{
	return 0;
}


// Update surfaces
int MenuInventory::update(Game &g)
{
	return 0;
}


// Close the menu
int MenuInventory::close(ManageSurfaces &surf)
{
	return 0;
}