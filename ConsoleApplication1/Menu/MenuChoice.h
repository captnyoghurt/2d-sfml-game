#pragma once

#include "M_choice.h"
#include "Menu.h"

class Game;

class MenuChoice :
	public Menu
{
public:
	MenuChoice(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~MenuChoice();

public:
	// Return the choices surfaces with modifying possibilities
	std::vector< std::shared_ptr<M_choice> > getChoices();
	// Return the down cursor surfaces with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getCursorSurfaceDown();
	// Return the up cursor surfaces with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getCursorSurfaceUp();
	// Return the selected choice surface with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getSelectedChoiceSurface();
	// Return the selected choice
	int getSelectedChoice() const;
	// Return the first choice actually shown
	int getFirstChoiceShown() const;
	// Return the last choice actually shown
	int getLastChoiceShown() const;

	// Modify the selected choice
	int setSelectedChoice(const int &ch);

	// Resize the ChoiceSurface according to the selected choice
	int resizeChoiceSurface();

	// Load the menu
	virtual int load(ManageRessources& ress, ManageSurfaces& surf, const std::string &filename, const int &xcam, const int &ycam);
	// Update surfaces
	virtual int update(Game &g);
	// Close the menu
	virtual int close(ManageSurfaces& surf);

private:
	std::vector < std::shared_ptr<M_choice> > m_choices;
	std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator m_cursorSurfaceUp;
	std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator m_cursorSurfaceDown;
	std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator m_selectedChoiceSurface;
	int m_selectedChoice;
	int m_firstChoiceShown;
	int m_lastChoiceShown;
};
