#pragma once

#include <list>
#include <memory>
#include "B_Event.h"

class Battle;

class BattleEventManager
{
public:
	BattleEventManager();
	~BattleEventManager();

public:
	// Return the list of battle events
	std::list<std::shared_ptr<B_Event>> getBattleEvents() const;

	// Return the list of battle events with modifying possibilities
	std::list<std::shared_ptr<B_Event>>& getRealBattleEvents();

	// Add an event to the top of the list
	int addToFront(std::shared_ptr<B_Event> b);

	// Execute the header event
	int execute(Battle *b);

private:
	std::list<std::shared_ptr<B_Event> > m_battleEvents;
};

