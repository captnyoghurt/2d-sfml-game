#pragma once

#include <list>
#include "../Event/IG_Action.h"
#include "../Map/ManageSurfaces.h"

class M_choice
{
public:
	M_choice();
	~M_choice();

public:
	// Return if the choice has been initialized
	bool getInitialized() const;
	// Return if the choice should be shown
	bool getShown() const;
	// Return the surface of the choice
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getSurfaceText() const;
	// Return the action made by the choice
	IG_Action getAction() const;
	// Return the position X of the choice on the screen
	int getX() const;
	// Return the position Y of the choice on the screen
	int getY() const;

	// Return the surface of the choice with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealSurfaceText();

	// Modify if the choice should be shown
	int setShown(const bool &b, const int &dx, const int &dy);
	// Modify the action made by the choice
	int setAction(IG_Action act);
	// Modify the position X of the choice on the screen
	int setX(const int &x);
	// Modify the position Y of the choice on the screen
	int setY(const int &y);

	// Load the choice
	int load(ManageSurfaces& surf, const std::string &str, sf::Font &f, const int &x, const int &y, const bool &sh, IG_Action act);
private:
	bool m_initialized;
	bool m_shown;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_surfaceText;
	IG_Action m_action;
	int m_x;
	int m_y;

};

