#include "Enemies.h"



Enemies::Enemies()
{
}


Enemies::Enemies(const Enemies &enemie, int number)
{

}


Enemies::~Enemies()
{
}


// Return the number of team mate alive
int Enemies::getNumberFighterAlive() const
{
	return m_numberFighterAlive;
}


// Return the team mate vector
std::vector<std::shared_ptr<Fighter>> Enemies::getTeam()
{
	return m_fighters;
}


// Return the team mate vector with modifying possibilities
std::vector<std::shared_ptr<Fighter>>& Enemies::getRealTeam()
{
	return m_fighters;
}


// Add a new member
int Enemies::addMember(Fighter m)
{
	m_fighters.push_back(std::make_shared<Fighter>(m));

	return 0;
}


// Update the team batttle
int Enemies::update()
{
	// [TODO]

	return 0;
}


// Clear the enemy team
int Enemies::clear()
{
	m_fighters.clear();

	return 0;
}