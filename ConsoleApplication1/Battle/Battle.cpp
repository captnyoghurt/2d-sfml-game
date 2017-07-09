#include "Battle.h"
#include "../Map/ManageRessources.h"
#include "../Map/ManageSurfaces.h"



Battle::Battle()
{
}


Battle::~Battle()
{
}


// Return if the battle has started
bool Battle::getStarted() const
{
	return m_started;
}


// Return the number of turn since the begining of the battle
int Battle::getBattleTurn() const
{
	if (!m_started)
		return -1;

	return m_battleTurn;
}


// Return the enemie team
Enemies Battle::getEnemies() const
{
	return m_enemieTeam;
}


// Return the allie team
TeamBattle Battle::getAllies() const
{
	return m_alliesTeam;
}


// Return the enemie team with modifying possibilities
Enemies& Battle::getRealEnemies()
{
	return m_enemieTeam;
}


// Return the allie team with modifiying possibilities
TeamBattle& Battle::getRealAllies()
{
	return m_alliesTeam;
}


// Return the battleMenu with modifying possibilities
BattleMenu& Battle::getRealBattleMenu()
{
	return *m_battleMenu;
}


// Return the battleEventManager with modifying possibilities
BattleEventManager& Battle::getRealBattleEventManager()
{
	return m_battleEventManager;
}


// Return the background with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& Battle::getRealBackground()
{
	return m_background;
}


// Start a battle according to the arguments
int Battle::start(std::string backgroundFilename, TeamBattle team, std::string enemies, ManageRessources &ress, ManageSurfaces &surf, int lastEventLayer)
{
	// [TODO]

	return 0;
}


// Update the battle
int Battle::update(ManageRessources &ress, ManageSurfaces& surf)
{
	// [TODO]

	return 0;
}


// End the battle
int Battle::end()
{
	// [TODO]

	return 0;
}