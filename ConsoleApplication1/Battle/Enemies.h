#pragma once

#include <vector>
#include "Fighter.h"

class Enemies
{
public:
	Enemies();
	Enemies(const Enemies &enemie, int number = -1);
	~Enemies();

public:
	// Return the number of team mate alive
	int getNumberFighterAlive() const;
	// Return the team mate vector
	std::vector<std::shared_ptr<Fighter>> getTeam();

	// Return the team mate vector with modifying possibilities
	std::vector<std::shared_ptr<Fighter>>& getRealTeam();

	// Add a new member
	int addMember(Fighter m);

	// Update the team batttle
	int update();
	// Clear the enemy team
	int clear();
private:
	int m_numberFighterAlive;
	std::vector<std::shared_ptr<Fighter>> m_fighters;
};

