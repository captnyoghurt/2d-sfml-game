#pragma once

#include "Fighter.h"

class TeamMate : public Fighter
{
public:
	TeamMate();
	TeamMate(const TeamMate &tm);
	~TeamMate();

public:
	// True if the fighter is in reality a TeamMate
	virtual bool isTeamMate() const;
};

