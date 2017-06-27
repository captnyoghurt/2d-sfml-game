#include "../constants.h"
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
int MenuBattleSide::setSelectedChoice(const int &s)
{
	if ((unsigned)s < (unsigned)m_numberMaxChoices)
	{
		m_selectedChoice = s;
		return 0;
	}

	return -1;
}


// Modify the maximum number of choices
int MenuBattleSide::setNumberMaxChoices(const int &c)
{
	if ((unsigned)c < (unsigned)TEAM_BATTLE_MAX_NUMBER)
	{
		m_numberMaxChoices = c;

		if (m_selectedChoice >= m_numberMaxChoices)
			m_selectedChoice = c - 1;

		return 0;
	}

	return -1;
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