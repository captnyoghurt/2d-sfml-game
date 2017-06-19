#pragma once

#include "B_Event.h"
#include "Fighter.h"
#include <memory>

class B_EventAttack : public B_Event
{
public:
	B_EventAttack();
	B_EventAttack(std::shared_ptr<Fighter> source, std::shared_ptr<Fighter> dest, const std::string &decription = "Unknown");
	~B_EventAttack();

public:
	// Return if the fighter source of the attack
	std::shared_ptr<Fighter> getSource();
	// Return if the fighter destination of the attack
	std::shared_ptr<Fighter> getDestination();

	// Modify if the fighter source of the attack
	int setSource(std::shared_ptr<Fighter> src);
	// Modify if the fighter destination of the attack
	int setDestination(std::shared_ptr<Fighter> dest);

	// Do the event
	virtual int execute(Battle *bat);
private:
	std::shared_ptr<Fighter> m_source;
	std::shared_ptr<Fighter> m_destination;
};

