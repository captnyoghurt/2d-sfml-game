#pragma once

#include "Enemies.h"
#include "Fighter.h"
#include "TeamBattle.h"
#include "BattleEventManager.h"

class MenuBattle;
class ManageRessources;
class ManageSurfaces;
class Game;

class Battle
{
public:
	enum e_BattleExit {BATTLE_EXIT_WIN = 10, BATTLE_EXIT_LOSE, BATTLE_EXIT_RUN, BATTLE_EXIT_TOTAL};

public:
	explicit Battle(TeamBattle &tb);
	~Battle();

public:
	// Return if the battle has started
	bool getStarted() const;
	// Return if the turn has begun
	bool getInTurn() const;
	// Return if the choices for the turn has been made
	bool getChoicesFinished() const;
	// Return the number of turn since the begining of the battle
	int getBattleTurn() const;
	// Return the enemie team
	Enemies getEnemies() const;
	// Return the allie team
	TeamBattle getAllies() const;
	// Return the last key event layer
	int getLastKeyEventLayer() const;
	// Return the number of battle event created
	int getBattleEventCreated() const;
	// Return the battle exit
	e_BattleExit getBattleExit() const;

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
	// Return the real battle order
	std::vector< std::shared_ptr<Fighter> >& getRealBattleOrder();

	// Modify the battle exit
	int setBattleExit(const Battle::e_BattleExit &be);

	// Tell the battle it's updated
	int gotUpdated();
	
	// Start a new battle turn
	int startTurn(Game *g);

	// Start a battle according to the arguments
	int start(const std::string &backgroundFilename, TeamBattle team, std::string enemies, Game *g);
	// Update the battle
	int update(Game *g);
	// End the battle
	int end(Game *g);

protected:
	// Set m_battleOrder to make the right order
	int definedOrder(Game *g);
	// Choose battle event for the next player
	int chooseBattleEvent(Game *g);
	// Clear the battle attribute from last battle
	int clear();

private:
	bool m_updated;
	bool m_started;
	bool m_inTurn;
	bool m_choicesFinished;
	int m_battleTurn;
	int m_lastKeyEventLayer;
	int m_battleEventCreated;
	e_BattleExit m_battleExit;
	Enemies m_enemieTeam;
	TeamBattle *m_alliesTeam;
	std::shared_ptr<MenuBattle> m_battleMenu;
	BattleEventManager m_battleEventManager;
	std::list<sf::Texture>::iterator m_texture;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_background;
	std::vector< std::shared_ptr<Fighter> > m_battleOrder;
};

