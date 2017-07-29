#include "TeamBattle.h"
#include "../Game.h"


TeamBattle::TeamBattle()
{
	m_numberTeamMateAlive = 0;
}


TeamBattle::~TeamBattle()
{
}


// Return the number of team mate alive
int TeamBattle::getNumberTeamMateAlive() const
{
	return m_numberTeamMateAlive;
}


// Return the team mate vector
std::vector<TeamMate> TeamBattle::getTeam() const
{
	return m_team;
}


// Return the team mate vector with modifying possibilities
std::vector<TeamMate>& TeamBattle::getRealTeam()
{
	return m_team;
}


// Add a new member
int TeamBattle::addMember(TeamMate m)
{
	m_team.push_back(m);

	return 0;
}


// Load the team battle
int TeamBattle::load(Game *g)
{


	return 0;
}


// Update the team battle
int TeamBattle::update()
{
	m_numberTeamMateAlive = m_team.size();

	for (unsigned int i(0); i < m_team.size(); ++i)
	{
		if (m_team.at(i).isDead())
		{
			m_numberTeamMateAlive--;
			m_team.at(i).switchToDead();
		}
	}

	return 0;
}