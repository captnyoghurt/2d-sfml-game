#pragma once

#include <vector>
#include "TeamMate.h"

class TeamBattle
{
public:
	TeamBattle();
	~TeamBattle();

public:
	// Return the number of team mate alive
	int getNumberTeamMateAlive() const;
	// Return the team mate vector
	std::vector<TeamMate> getTeam() const;

	// Return the team mate vector with modifying possibilities
	std::vector<TeamMate>& getRealTeam();

	// Add a new member
	int addMember(TeamMate m);

	// Update the team batttle
	int update();
private:
	int m_numberTeamMateAlive;
	std::vector<TeamMate> m_team;
};

