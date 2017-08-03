#pragma once

#include <list>
#include <memory>
#include "B_Event.h"

class Battle;
class Game;

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
	// Create an event
	int createEvent(std::shared_ptr<Fighter> source, std::shared_ptr<B_Event> type, Game &g);
	// Add a destination for the event in construction
	int addDestinationForEvent(std::shared_ptr<Fighter> f, Game &g);

	// Return if the manager is creating an event
	bool isCreating() const;

	// Execute the header event
	int execute(Battle *b);

protected:
	// Tell the battle menu to ask a destination
	int askDestination(Game &g);

private:
	std::list<std::shared_ptr<B_Event> > m_battleEvents;
	std::shared_ptr<B_Event> m_eventInConstruction;
};

