/**
*  @file
*  @author  Paul Coignet
*  @date    17/04/2017
*  @version 0.1
*
*  @brief Game class header.
*
*  @section DESCRIPTION
*
*  This is the main file where the main function is called.
*  This is the object used to play the game. After calling
*  Game.start, the game is running unitil the user leave.
*
*/

#pragma once

#include "Map/Map.h"
#include "Animation/ManageAnimation.h"
#include "Event/ManageEvent.h"
#include "Map/ManageRessources.h"
#include "Map/ManageSurfaces.h"
#include "Menu/Menu.h"
#include "Team/Team.h"
#include "Battle/Battle.h"
#include "Sound/ManageSound.h"
#include "Database/DatabaseJson.h"


using namespace sf;

class Game
{
public:
	/**
	* \enum e_ressourcesLayer
	* \brief Id of the different ressources layer.
	*/
	enum e_ressourcesLayer {RESSOURCES_MAP=0, RESSOURCES_CHARACTERS, RESSOURCES_MENU, RESSOURCES_BATTLE, RESSOURCES_TOTAL};

public:
	/**
	* \brief Game constructor.
	*
	* \param mode The VideoMode used for the SFML window
	* \param title The name of the window showed
	* \param style The Uint32 style of the SFML window
	* \param settings The ContextSettings used for the SFML window
	*/
	Game(VideoMode mode, const String &title, Uint32 style = Style::Default, const ContextSettings &settings = ContextSettings());
	~Game();

public:
	/**
	* \brief Return the actual map.
	*
	* \return Map object.
	*/
	Map getMap() const;
	/**
	* \brief Return the event manager.
	*
	* \return ManageEvent object.
	*/
	ManageEvent getEventManager() const;
	/**
	* \brief Return the surfaces manager.
	*
	* \return std::vector<ManageSurfaces> object.
	*/
	std::vector<ManageSurfaces> getSurfaceManager() const;
	/**
	* \brief Return the ressource manager.
	*
	* \return std::vector<ManageRessources> object.
	*/
	std::vector<ManageRessources> getRessourceManager() const;
	/**
	* \brief Return the animation manager.
	*
	* \return ManageAnimation object.
	*/
	ManageAnimation getAnimationManager() const;
	/**
	* \brief Return the sound manager.
	*
	* \return ManageSound object.
	*/
	ManageSound getSoundManager() const;
	/**
	* \brief Return the team.
	*
	* \return Team object.
	*/
	Team getTeam() const;

	/**
	* \brief Return the event manager with modifying possibilities.
	*
	* \return ManageEvent& object. Can be modified.
	*/
	ManageEvent& getRealEventManager();
	/**
	* \brief Return the map with modifying possibilities.
	*
	* \return Map& object. Can be modified.
	*/
	Map& getRealMap();
	/**
	* \brief Return the window with modifying possibilities.
	*
	* \return RenderWindow& object. Can be modified.
	*/
	RenderWindow& getRealWindow();
	/**
	* \brief Return the surfaces manager with modifying possibilities.
	*
	* \return std::vector<ManageSurfaces>& object. Can be modified.
	*/
	std::vector<ManageSurfaces>& getRealSurfaceManager();
	/**
	* \brief Return a surface manager with modifying possibilities.
	*
	* \param n The number of the ManageSurface wanted.
	* \return ManageSurfaces& object. Can be modified.
	*/
	ManageSurfaces& getRealSurfaceManager(int n);
	/**
	* \brief Return the ressource manager with modifying possibilities.
	*
	* \return std::vector<ManageRessources>& object. Can be modified.
	*/
	std::vector<ManageRessources>& getRealRessourceManager();
	/**
	* \brief Return a ressource manager with modifying possibilities.
	*
	* \param n The number of the ManageRessources wanted.
	* \return ManageRessources& object. Can be modified.
	*/
	ManageRessources& getRealRessourceManager(int n);
	/**
	* \brief Return the animation manager with modifying possibilities.
	*
	* \return ManageAnimation& object. Can be modified.
	*/
	ManageAnimation& getRealAnimationManager();
	/**
	* \brief Return the sound manager with modifying possibilities.
	*
	* \return ManageSound& object. Can be modified.
	*/
	ManageSound& getRealSoundManager();
	/**
	* \brief Return the team with modifying possibilities.
	*
	* \return Team& object. Can be modified.
	*/
	Team& getRealTeam();
	/**
	* \brief Return the menus with modifying possibilities.
	*
	* \return std::list< std::shared_ptr<Menu> >& object. Can be modified.
	*/
	std::list< std::shared_ptr<Menu> >& getRealMenus();
	/**
	* \brief Return the battle with modifying possibilities.
	*
	* \return Battle& object. Can be modified.
	*/
	Battle& getRealBattle();
	/**
	* \brief Return the json database with modifying possibilities.
	*
	* \return DatabaseJson& object. Can be modified.
	*/
	DatabaseJson& getRealDatabaseJson();

	/**
	* \brief Clear the window.
	*/
	void clear();
	/**
	* \brief Display the window.
	*/
	void display();
	/**
	* \brief Start the game.
	*
	* \return int The error code of the game.
	*/
	int start();

	/**
	* \brief Exit the game.
	*
	* \return int The error code of the game.
	*/
	int exit();
	/**
	* \brief Load a new map.
	*
	* \param filename Name of the map file.
	* \return int The error code of the loading.
	*/
	int loadNewMap(std::string filename);
	/**
	* \brief Stop the current menu.
	*
	* \return int The error code of the method.
	*/
	int stopMenu();
	/**
	* \brief Print everything on the screen.
	*
	* \return int The error code of the method.
	*/
	int print();
	/**
	* \brief Update the game.
	*
	* \return int The error code of the method.
	*/
	int update();

protected:
	/**
	* \brief  Load the ressources of the game (to be called in the constructor).
	*
	* \return int The error code of the method.
	*/
	int loadRessources();

private:
	DatabaseJson m_jdb;
	std::vector<ManageSurfaces> m_surfaceManager;
	std::vector<ManageRessources> m_ressourceManager;
	RenderWindow m_window;
	Map m_map;
	ManageEvent m_eventManager;
	ManageAnimation m_animationManager;
	ManageSound m_soundManager;
	Team m_team;
	std::list< std::shared_ptr<Menu> > m_menus;
	Battle m_battle;
};