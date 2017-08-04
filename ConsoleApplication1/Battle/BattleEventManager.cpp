#include "BattleEventManager.h"
#include "../Game.h"
#include "../Event/actionFunctions.h"
#include "../Menu/MenuBattle.h"



BattleEventManager::BattleEventManager() : m_eventInConstruction(nullptr)
{
}


BattleEventManager::~BattleEventManager()
{
}


// Return the list of battle events
std::list<std::shared_ptr<B_Event>> BattleEventManager::getBattleEvents() const
{
	return m_battleEvents;
}


// Return the list of battle events with modifying possibilities
std::list<std::shared_ptr<B_Event>>& BattleEventManager::getRealBattleEvents()
{
	return m_battleEvents;
}


// Add an event to the top of the list
int BattleEventManager::addToFront(std::shared_ptr<B_Event> b)
{
	m_battleEvents.push_front(b);

	return 0;
}


// Create an event
int BattleEventManager::createEvent(std::shared_ptr<Fighter> source, std::shared_ptr<B_Event> type, Game &g)
{
	if (m_eventInConstruction)
		return -1;

	m_eventInConstruction = type;

	type->getRealSource() = source;

	askDestination(g);

	return 0;
}


// Add a destination for the event in construction
int BattleEventManager::addDestinationForEvent(std::shared_ptr<Fighter> f, Game &g)
{
	if (!m_eventInConstruction)
		return -1;

	if (!m_eventInConstruction->isAllyDestinationFull())
		m_eventInConstruction->getRealAllyDestination().push_back(f);
	else if (!m_eventInConstruction->isEnemyDestinationFull())
		m_eventInConstruction->getRealEnemyDestination().push_back(f);
	else
		return -1;

	askDestination(g);

	return 0;
}


// Return if the manager is creating an event
bool BattleEventManager::isCreating() const
{
	return !(!m_eventInConstruction);
}


// Execute the header event
int BattleEventManager::execute(Battle *b)
{
	// [TODO]
	auto it = m_battleEvents.front();
	m_battleEvents.pop_front();

	return 0;
}


// Tell the battle menu to ask a destination
int BattleEventManager::askDestination(Game &g)
{
	if (!isCreating())
		return -1;

	if (m_eventInConstruction->getRealSource()->isTeamMate())
	{
		if (!m_eventInConstruction->isAllyDestinationFull())
			af_menuBattleUseRight(g);
		else if (!m_eventInConstruction->isEnemyDestinationFull())
			af_menuBattleUseLeft(g);
		else
		{
			m_battleEvents.push_back(m_eventInConstruction);
			m_eventInConstruction = nullptr;
			g.getRealBattle().getRealBattleMenu().setIsBlocking(false);

			return 1;
		}
	}
	else
	{
		return 1;
	}

	return 0;
}