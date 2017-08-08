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
	// Return if the battle event manager is waiting
	bool getWaiting() const;
	// Return if the execute has started
	bool getExecuteStarted() const;

	// Return the list of battle events with modifying possibilities
	std::list<std::shared_ptr<B_Event>>& getRealBattleEvents();

	// Modify if the battle event manager is waiting
	int setWaiting(const bool& b);
	// Modify if the execute has started
	int setExecuteStarted(const bool &b);

	// Add an event to the top of the list
	int addToFront(std::shared_ptr<B_Event> b);
	// Create an event
	int createEvent(std::shared_ptr<Fighter> source, std::shared_ptr<B_Event> type, Game &g);
	// Add a destination for the event in construction
	int addDestinationForEvent(std::shared_ptr<Fighter> f, Game &g);

	// Return if the manager is creating an event
	bool isCreating() const;
	// Clear the entire list
	int clear();

	// Execute the header event
	int execute(Game &g);

protected:
	// Tell the battle menu to ask a destination
	int askDestination(Game &g);

private:
	bool m_waiting;
	bool m_executeStarted;
	std::list<std::shared_ptr<B_Event> > m_battleEvents;
	std::shared_ptr<B_Event> m_eventInConstruction;
};

