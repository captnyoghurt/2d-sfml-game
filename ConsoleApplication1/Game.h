#pragma once

#include "Map/Map.h"
#include "Animation/ManageAnimation.h"
#include "Event/ManageEvent.h"
#include "Map/ManageRessources.h"
#include "Map/ManageSurfaces.h"
#include "Menu/Menu.h"
#include "Team/Team.h"

using namespace sf;

class Game
{
public:
	enum e_ressourcesLayer {RESSOURCES_MAP=0, RESSOURCES_CHARACTERS, RESSOURCES_MENU, RESSOURCES_TOTAL};

public:
	Game(VideoMode mode, const String &title, Uint32 style = Style::Default, const ContextSettings &settings = ContextSettings());
	~Game();

public:
	// Return the actual map
	Map getMap() const;
	// Return the event manager
	ManageEvent getEventManager() const;
	// Return the surfaces manager
	std::vector<ManageSurfaces> getSurfaceManager() const;
	// Return the ressource manager
	std::vector<ManageRessources> getRessourceManager() const;
	// Return the animation manager
	ManageAnimation getAnimationManager() const;
	// Return the team
	Team getTeam() const;

	// Return the event manager with modifying possibilities
	ManageEvent& getRealEventManager();
	// Return the map with modifying possibilities
	Map& getRealMap();
	// Return the window with modifying possibilities
	RenderWindow& getRealWindow();
	// Return the surfaces manager with modifying possibilities
	std::vector<ManageSurfaces>& getRealSurfaceManager();
	ManageSurfaces& getRealSurfaceManager(int n);
	// Return the ressource manager with modifying possibilities
	std::vector<ManageRessources>& getRealRessourceManager();
	ManageRessources& getRealRessourcesManager(int n);
	// Return the animation manager with modifying possibilities
	ManageAnimation& getRealAnimationManager();
	// Return the team with modifying possibilities
	Team& getRealTeam();
	// Return the menus with modifying possibilities
	std::list< std::shared_ptr<Menu> >& getRealMenus();

	// Clear
	void clear();
	// Display
	void display();
	// Start the game
	int start();
	
	// Exit
	int exit();
	// Load a new map
	int loadNewMap(std::string filename);
	// Stop the current menu
	int stopMenu();
	// Print everything on the screen
	int print();
	// Update everything in the game
	int update();

protected:
	// Load the ressources of the game (to be called in the constructor)
	int loadRessources();

private:
	std::vector<ManageSurfaces> m_surfaceManager;
	std::vector<ManageRessources> m_ressourceManager;
	RenderWindow m_window;
	Map m_map;
	ManageEvent m_eventManager;
	ManageAnimation m_animationManager;
	Team m_team;
	std::list< std::shared_ptr<Menu> > m_menus;
};