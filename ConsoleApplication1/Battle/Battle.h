#pragma once

#include "Enemies.h"
#include "Fighter.h"
#include "TeamBattle.h"

class Battle
{
public:
	Battle();
	~Battle();

public:

private:
	Enemies m_enemieTeam;
	TeamBattle m_alliesTeam;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_background;
};

