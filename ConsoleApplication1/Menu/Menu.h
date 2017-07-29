#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "../Map/ManageRessources.h"
#include "../Map/ManageSurfaces.h"

class Game;

class Menu
{
public:
	Menu(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~Menu();

public:
	// Return if the menu is shown
	bool getShown() const;
	// Return if the menu is initialized
	bool getInitialized() const;
	// Return the background with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getBackground();
	// Return the position X of the menu
	int getX() const;
	// Return the position Y of the menu
	int getY() const;
	// Return the width of the menu
	int getWidth() const;
	// Return the height of the menu
	int getHeight() const;

	// Modify if the menu should be shown or not
	virtual int setShown(const bool &b);

	// Load the menu
	virtual int load(ManageRessources& ress, ManageSurfaces& surf, const int &x, const int &y, const int &w = -1, const int &h = -1);
	// Update surfaces
	virtual int update(Game &g);
	// Close the menu
	virtual int close(ManageSurfaces& surf);
protected:
	bool m_shown;
	bool m_initialized;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_background;
	int m_lastEventLayer;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};

