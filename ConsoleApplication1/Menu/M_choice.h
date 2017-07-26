#pragma once

#include <list>
#include <memory>
#include "../Event/IG_Action.h"
#include "../Map/ManageRenderTexture.h"
#include "../Map/ManageSurfaces.h"


class M_choice
{
public:
	M_choice();
	M_choice(const M_choice & ch);
	~M_choice();

public:
	// Return if the choice has been initialized
	bool getInitialized() const;
	// Return if the choice should be shown
	bool getShown() const;
	// Return the surface of the choice
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getSurface();
	// Return the action made by the choice
	IG_Action getAction() const;
	// Return the position X of the choice on the screen
	int getX() const;
	// Return the position Y of the choice on the screen
	int getY() const;

	// Return the surface of the choice with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealSurface();
	// Return the render texture manager with modifying possibilities
	ManageRenderTexture& getRealRenderTextureManager();

	// Modify if the choice should be shown
	int setShown(const bool &b, const int &dx, const int &dy);
	// Modify the action made by the choice
	int setAction(IG_Action act);
	// Modify the position X of the choice on the screen
	int setX(const int &x);
	// Modify the position Y of the choice on the screen
	int setY(const int &y);

	// Load the choice
	int load(ManageSurfaces& surf, const std::string &str, sf::Font &f, const int &x, const int &y, const bool &sh, IG_Action act, const int &w = 0, const int &h = 0);
	// Clear the surfaces of the choice
	int clear(ManageSurfaces &surf);
private:
	bool m_initialized;
	bool m_shown;
	ManageRenderTexture m_textureManager;
	IG_Action m_action;
	int m_x;
	int m_y;

};

