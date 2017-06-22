#include "MenuBattleSide.h"



MenuBattleSide::MenuBattleSide(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer) : Menu(ress, surf, lastEventLayer)
{
}


MenuBattleSide::~MenuBattleSide()
{
}


// Return the cursor for the right surface
std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator MenuBattleSide::getCursor()
{
	return m_cursorSurfaceRight;
}


// Return the current selected choice
int MenuBattleSide::getSelectedChoice() const
{
	return m_selectedChoice;
}


// Return the maximum number of choices
int MenuBattleSide::getNumberMaxChoices() const
{
	return m_numberMaxChoices;
}


// Return all the choices with modifying possibilities
std::vector< std::shared_ptr<M_choice> >& MenuBattleSide::getChoices()
{
	return m_choices;
}


// Modify the current selected choice
int MenuBattleSide::getSelectedChoice(const int &s)
{

}


// Modify the maximum number of choices
int MenuBattleSide::getNumberMaxChoices(const int &c)
{

}


// Load the menu
int MenuBattleSide::load(ManageRessources& ress, ManageSurfaces& surf, const int &x, const int &y, const int &w, const int &h)
{
	// [TODO]
	return 0;
}


// Update surfaces
int MenuBattleSide::update(Game &g)
{
	// [TODO]
	return 0;
}


// Close the menu
int MenuBattleSide::close(ManageSurfaces& surf)
{
	// [TODO]
	return 0;
}