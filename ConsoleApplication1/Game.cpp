#include <iostream>
#include <memory>
#include "constants.h"
#include "Game.h"



Game::Game(VideoMode mode, const String &title, Uint32 style, const ContextSettings &settings) :
	m_window(mode, title, style, settings),
	m_surfaceManager(BATTLE_MAX_LAYER + 1),
	m_ressourceManager(Game::e_ressourcesLayer::RESSOURCES_TOTAL),
	m_team(*this),
	m_map(*this)
{
	loadRessources();
}


Game::~Game()
{
}


// Return the actual map
Map Game::getMap() const
{
	return m_map;
}


// Return the event manager
ManageEvent Game::getEventManager() const
{
	return m_eventManager;
}


// Return the surfaces manager
std::vector<ManageSurfaces> Game::getSurfaceManager() const
{
	return m_surfaceManager;
}


// Return the ressource manager
std::vector<ManageRessources> Game::getRessourceManager() const
{
	return m_ressourceManager;
}


// Return the animation manager
ManageAnimation Game::getAnimationManager() const
{
	return m_animationManager;
}


// Return the team
Team Game::getTeam() const
{
	return m_team;
}


// Return the event manager with modifying possibilities
ManageEvent& Game::getRealEventManager()
{
	return m_eventManager;
}


// Return the map with modifying possibilities
Map& Game::getRealMap()
{
	return m_map;
}


// Return the window with modifying possibilities
RenderWindow& Game::getRealWindow()
{
	return m_window;
}


// Return the surfaces manager with modifying possibilities
std::vector<ManageSurfaces>& Game::getRealSurfaceManager()
{
	return m_surfaceManager;
}
ManageSurfaces& Game::getRealSurfaceManager(int n)
{
	return m_surfaceManager.at(n);
}

// Return the ressource manager with modifying possibilities
std::vector<ManageRessources>& Game::getRealRessourceManager()
{
	return m_ressourceManager;
}
ManageRessources& Game::getRealRessourceManager(int n)
{
	return m_ressourceManager.at(n);
}


// Return the animation manager with modifying possibilities
ManageAnimation& Game::getRealAnimationManager()
{
	return m_animationManager;
}


// Return the team with modifying possibilities
Team& Game::getRealTeam()
{
	return m_team;
}


// Return the menus with modifying possibilities
std::list< std::shared_ptr<Menu> >& Game::getRealMenus()
{
	return m_menus;
}


// Return the battle with modifying possibilities
Battle& Game::getRealBattle()
{
	return m_battle;
}


// Clear
void Game::clear()
{
	m_window.clear();
}


// Display
void Game::display()
{
	m_window.display();
}


// Start the game
int Game::start()
{
	m_window.setFramerateLimit(WINDOW_FRAMERATES);

	if (loadNewMap(std::string("bite")) == -1)
		std::cout << "Crotte";
	
	int nb(0);
	Clock clk1, clk2;

	while (m_window.isOpen())
	{
		clk2.restart();
		update();
		if (m_map.getUpdated())
			nb++;
		print();

		if (nb >= 30)
		{
			m_window.setTitle("Framerates : " + std::to_string(float(nb)/clk1.getElapsedTime().asSeconds()));
			nb = 0;
			clk1.restart();
		}

		if (clk2.getElapsedTime().asMilliseconds() < 5)
			sf::sleep(sf::milliseconds(WINDOW_SLEEPTIME) - clk2.getElapsedTime());
	}

	return 0;
}


// Exit
int Game::exit()
{
	m_window.close();
	return 0;
}


// Load a new map
int Game::loadNewMap(std::string filename)
{
	int ret = m_map.load(filename, *this);
	m_team.setMaxX(m_map.getWitdth()*TILE_WIDTH);
	m_team.setMaxY(m_map.getHeight()*TILE_HEIGHT);

	return ret;
}


// Stop the current menu
int Game::stopMenu()
{
	if (m_menus.size())
	{
		m_eventManager.setKeyEventLayer(m_menus.back()->close(m_surfaceManager.at(MENU_SIMPLE_LAYER)));
		m_menus.pop_back();
	}

	return 0;
}


// Print everything on the screen
int Game::print()
{
	int ret(0);

	if (!m_map.getUpdated() && !m_battle.getStarted())
		return 1;

	clear();

	if (m_battle.getStarted())
	{
		ret = m_surfaceManager.at(BATTLE_MIN_LAYER).print(m_window, Camera(0, 0, CAMERA_WIDTH, CAMERA_HEIGHT, CAMERA_WIDTH, CAMERA_HEIGHT));
	}
	else
	{
		ret = m_map.print(m_window, m_surfaceManager);
		ret += (m_surfaceManager.at(MENU_SIMPLE_LAYER).print(m_window, m_map.getRealCamera()) << 1);
	}

	display();

	return ret;
}


// Update everything in the game
int Game::update()
{
	Clock clk;
	int ret = m_eventManager.updateEvent(*this);

	ret += (m_map.update() << 1);

	ret += (m_team.update(m_map.getRealCamera()) << 2);
	if (ret >> 2 == 1)
		m_map.gotUpdated();

	if(m_menus.size() > 0)
		ret += (m_menus.front()->update(*this) << 3);

	ret += (m_animationManager.update(*this) << 4);

	if (m_battle.getStarted())
		ret += (m_battle.update(this) << 5);

	return ret;
}


/// Protected

// Load the ressources of the game (to be called in the constructor)
int Game::loadRessources()
{
	std::list<sf::Texture>::iterator it;
	std::list<sf::Font>::iterator it2;


	if (!(it = (m_ressourceManager.at(Game::e_ressourcesLayer::RESSOURCES_MENU).addTexture()))->loadFromFile(MENU_SURFACE_NAME))
		std::cout << "Cacaaa\n";

	if (!(it2 = (m_ressourceManager.at(Game::e_ressourcesLayer::RESSOURCES_MENU).addFont()))->loadFromFile(MENU_FONT_NAME))
		std::cout << "Gros caca\n";

	if (!(it = (m_ressourceManager.at(Game::e_ressourcesLayer::RESSOURCES_MENU).addTexture()))->loadFromFile(MENU_BATTLE_SURFACE_BAR))
		std::cout << "Problème\n";

	return 0;
}