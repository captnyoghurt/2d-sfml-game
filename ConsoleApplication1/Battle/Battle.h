#pragma once

#include "Enemies.h"
#include "Fighter.h"
#include "TeamBattle.h"
#include "BattleEventManager.h"

class MenuBattle;
class ManageRessources;
class ManageSurfaces;

class Battle
{
public:
	Battle();
	~Battle();

public:
	// Return if the battle has started
	bool getStarted() const;
	// Return the number of turn since the begining of the battle
	int getBattleTurn() const;
	// Return the enemie team
	Enemies getEnemies() const;
	// Return the allie team
	TeamBattle getAllies() const;
	// Return the last key event layer
	int getLastKeyEventLayer() const;

	// Return the enemie team with modifying possibilities
	Enemies& getRealEnemies();
	// Return the allie team with modifiying possibilities
	TeamBattle& getRealAllies();
	// Return the battleMenu with modifying possibilities
	MenuBattle& getRealBattleMenu();
	// Return the battleEventManager with modifying possibilities
	BattleEventManager& getRealBattleEventManager();
	// Return the background with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealBackground();

	// Start a battle according to the arguments
	int start(const std::string &backgroundFilename, TeamBattle team, std::string enemies, ManageRessources &ress, ManageSurfaces &surf, int lastEventLayer);
	// Update the battle
	int update(ManageRessources &ress, ManageSurfaces& surf);
	// End the battle
	int end(ManageRessources &ress, ManageSurfaces& surf);

private:
	bool m_started;
	int m_battleTurn;
	int m_lastKeyEventLayer;
	Enemies m_enemieTeam;
	TeamBattle m_alliesTeam;
	std::shared_ptr<MenuBattle> m_battleMenu;
	BattleEventManager m_battleEventManager;
	std::list<sf::Texture>::iterator m_texture;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_background;
};

