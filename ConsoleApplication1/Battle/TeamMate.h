#pragma once

#include "Fighter.h"

class TeamMate : public Fighter
{
public:
	TeamMate();
	TeamMate(const TeamMate &tm);
	~TeamMate();
};

