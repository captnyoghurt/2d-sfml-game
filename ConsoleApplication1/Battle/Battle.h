/**
*  @file
*  @author  Paul Coignet
*  @date    11 / 11 / 2017
*  @version 0.1
*
*  @brief Class header.
*
*  @section DESCRIPTION
*
*  Describe the battle and execute different turn.
*
*/

#pragma once

#include "Fighters/Enemies.h"
#include "Fighters/Fighter.h"
#include "Fighters/TeamBattle.h"
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
	/**
	* \brief Return if the battle has started	.
	*
	* \return bool object.
	*/
	bool getStarted() const;
	/**
	* \brief Return if the turn has begun	.
	*
	* \return bool object.
	*/
	bool getInTurn() const;
	/**
	* \brief Return if the choices for the turn has been made	.
	*
	* \return bool object.
	*/
	bool getChoicesFinished() const;
	/**
	* \brief Return if the battle is shown	.
	*
	* \return bool object.
	*/
	bool getShown() const;
 	// Return the number of turn since the begining of the battle
	int getBattleTurn() const;
	/**
	* \brief Return the enemie team	.
	*
	* \return Enemies object.
	*/
	Enemies getEnemies() const;
	/**
	* \brief Return the allie team	.
	*
	* \return TeamBattle object.
	*/
	TeamBattle getAllies() const;
	/**
	* \brief Return the selected TeamMate	.
	*
	* \return TeamMate object.
	*/
	TeamMate getSelectedTeamMate() const;
	/**
	* \brief Return the last key event layer	.
	*
	* \return int object.
	*/
	int getLastKeyEventLayer() const;
	/**
	* \brief Return the number of battle event created	.
	*
	* \return int object.
	*/
	int getBattleEventCreated() const;
	/**
	* \brief Return the battle exit	.
	*
	* \return e_BattleExit object.
	*/
	e_BattleExit getBattleExit() const;

	/**
	* \brief Return the enemie team with modifying possibilities	.
	*
	* \return Enemies& object.
	*/
	Enemies& getRealEnemies();
	/**
	* \brief Return the allie team with modifiying possibilities	.
	*
	* \return TeamBattle& object.
	*/
	TeamBattle& getRealAllies();
	/**
	* \brief Return the battleMenu with modifying possibilities	.
	*
	* \return MenuBattle& object.
	*/
	MenuBattle& getRealBattleMenu();
	/**
	* \brief Return the battleEventManager with modifying possibilities	.
	*
	* \return BattleEventManager& object.
	*/
	BattleEventManager& getRealBattleEventManager();
	/**
	* \brief Return the background with modifying possibilities	.
	*
	* \return std::list<std::pair<ManageSurfaces::e_thing, object.
	*/
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealBackground();
	/**
	* \brief Return the real battle order	.
	*
	* \return std::vector< object.
	*/
	std::vector< std::shared_ptr<Fighter> >& getRealBattleOrder();

	/**
	* \brief Modify the battle exit	.
	*
	* \param be The new value.
	* \return int object.
	*/
	int setBattleExit(const Battle::e_BattleExit &be);
	/**
	* \brief Modify if the battle is shown	.
	*
	* \param b The new value.
	* \return int object.
	*/
	int setShown(const bool &b);

	/**
	* \brief Tell the battle it's updated	.
	*
	* \return int object.
	*/
	int gotUpdated();
	
	/**
	* \brief Start a new battle turn	.
	*
	* \return int object.
	*/
	int startTurn(Game *g);

	/**
	* \brief Start a battle according to the arguments	.
	*
	* \return int object.
	*/
	int start(const std::string &backgroundFilename, TeamBattle team, std::string enemies, Game *g);
	/**
	* \brief Update the battle	.
	*
	* \return int object.
	*/
	int update(Game *g);
	/**
	* \brief End the battle	.
	*
	* \return int object.
	*/
	int end(Game *g);

protected:
	/**
	* \brief Set m_battleOrder to make the right order	.
	*
	* \return int object.
	*/
	int definedOrder(Game *g);
	/**
	* \brief Choose battle event for the next player	.
	*
	* \return int object.
	*/
	int chooseBattleEvent(Game *g);
	/**
	* \brief Clear the battle attribute from last battle	.
	*
	* \return int object.
	*/
	int clear();

private:
	bool m_updated;
	bool m_started;
	bool m_inTurn;
	bool m_choicesFinished;
	bool m_shown;
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