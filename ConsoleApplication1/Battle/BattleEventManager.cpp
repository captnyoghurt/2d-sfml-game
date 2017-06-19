#include "BattleEventManager.h"



BattleEventManager::BattleEventManager()
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


// Execute the header event
int BattleEventManager::execute(Battle *b)
{
	// [TODO]
	auto it = m_battleEvents.front();
	m_battleEvents.pop_front();

	return 0;
}