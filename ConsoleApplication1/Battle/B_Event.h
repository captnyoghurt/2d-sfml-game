#pragma once

#include <memory>
#include <string>
#include "Fighter.h"

class Battle;

class B_Event
{
public:
	B_Event();
	~B_Event();

public:
	// Return the description of the event in the fight
	std::string getDescription() const;
	// Return the number of destination for "ally" team
	int getNumberAllyDestination() const;
	// Return the number of destination for "enemy" team
	int getNumberEnemyDestination() const;

	// Modify the description of the event in the fight
	int setDescription(const std::string &description);
	// Modify the number of destination for "ally" team
	int setNumberAllyDestination(const int &n);
	// Modify the number of destination for "enemy" team
	int setNumberEnemyDestination(const int &n);

	// Do the event
	virtual int execute(Battle *bat);
protected:
	std::string  m_description;
	int m_numberAllyDestination;
	int m_numberEnemyDestination;
};

