#pragma once

#include <vector>
#include "TeamMate.h"

class Game;

class TeamBattle
{
public:
	TeamBattle();
	~TeamBattle();

public:
	// Return the number of team mate alive
	int getNumberTeamMateAlive() const;
	// Return the team mate vector
	std::vector< std::shared_ptr<TeamMate> > getTeam() const;

	// Return the team mate vector with modifying possibilities
	std::vector< std::shared_ptr<TeamMate> >& getRealTeam();

	// Add a new member
	int addMember(TeamMate m);

	// Load the team battle
	int load(Game *g);
	// Update the team batttle
	int update();
private:
	int m_numberTeamMateAlive;
	std::vector< std::shared_ptr<TeamMate> > m_team;
};

