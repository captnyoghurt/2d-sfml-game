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

	// Modify the description of the event in the fight
	int setDescription(const std::string &description);

	// Do the event
	virtual int execute(Battle &bat);
protected:
	std::string  m_description;
};

