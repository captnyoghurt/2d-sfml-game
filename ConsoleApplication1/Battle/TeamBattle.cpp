#include "TeamBattle.h"
#include "../Game.h"
#include "../constants.h"


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
	if (m_team.size() < 2)
		return -1;

	auto texture = g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_BATTLE).addTexture();
	if(!texture->loadFromFile(TEAM_BATTLE_CHAR1_NAME))
		return -1;

	auto texture2 = g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_BATTLE).addTexture();
	if (!texture2->loadFromFile(TEAM_BATTLE_CHAR1_NAME))
		return -1;

	m_team.at(0).setSurface(g->getRealSurfaceManager(BATTLE_MIN_LAYER + 1).addSurface(ManageSurfaces::e_thing::SPRITE, std::make_shared<SurfaceSprite>()));
	std::dynamic_pointer_cast<SurfaceSprite>(m_team.at(0).getRealSurface()->second)->setTexture(*texture);
	m_team.at(0).getRealSurface()->second->setDimensions(TEAM_BATTLE_CHAR1_X,
		TEAM_BATTLE_CHAR1_Y,
		(int)std::dynamic_pointer_cast<SurfaceSprite>(m_team.at(0).getRealSurface()->second)->getGlobalBounds().width,
		(int)std::dynamic_pointer_cast<SurfaceSprite>(m_team.at(0).getRealSurface()->second)->getGlobalBounds().height
	);

	m_team.at(1).setSurface(g->getRealSurfaceManager(BATTLE_MIN_LAYER + 1).addSurface(ManageSurfaces::e_thing::SPRITE, std::make_shared<SurfaceSprite>()));
	std::dynamic_pointer_cast<SurfaceSprite>(m_team.at(1).getRealSurface()->second)->setTexture(*texture2);
	m_team.at(1).getRealSurface()->second->setDimensions(TEAM_BATTLE_CHAR2_X,
		TEAM_BATTLE_CHAR2_Y,
		(int)std::dynamic_pointer_cast<SurfaceSprite>(m_team.at(1).getRealSurface()->second)->getGlobalBounds().width,
		(int)std::dynamic_pointer_cast<SurfaceSprite>(m_team.at(1).getRealSurface()->second)->getGlobalBounds().height
	);

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