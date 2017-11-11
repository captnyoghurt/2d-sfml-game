#pragma once

#include "B_Event.h"

class B_EventDefense : public B_Event
{
public:
	B_EventDefense();
	B_EventDefense(std::shared_ptr<Fighter> dest, const std::string &description = "Unknown");
	~B_EventDefense();

public:
	// Return if the fighter destination of the defense
	std::shared_ptr<Fighter> getDestination();

	// Modify if the fighter destination of the defense
	int setDestination(std::shared_ptr<Fighter> dest);

	// Do the event
	virtual int execute(Battle *bat, ManageSound& snd);
private:
	std::shared_ptr<Fighter> m_destination;
};

