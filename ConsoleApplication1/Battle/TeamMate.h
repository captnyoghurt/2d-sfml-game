#pragma once

#include "Fighter.h"

class TeamMate : public Fighter
{
public:
	TeamMate();
	TeamMate(const TeamMate &tm);
	~TeamMate();

public:
	// Take a decision for the next battle action
	virtual std::shared_ptr<B_Event> chooseEvent(Game *g);
	// True if the fighter is in reality a TeamMate
	virtual bool isTeamMate() const;
};

