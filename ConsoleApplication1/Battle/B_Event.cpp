#include "B_Event.h"
#include "Battle.h"


B_Event::B_Event()
{
	m_description = "Evenement inconnu";
	m_numberAllyDestination = 0;
	m_numberEnemyDestination = 0;
}


B_Event::~B_Event()
{
}


// Return the description of the event in the fight
std::string B_Event::getDescription() const
{
	return m_description;
}


// Return the number of destination for "ally" team
int B_Event::getNumberAllyDestination() const
{
	return m_numberAllyDestination;
}


// Return the number of destination for "enemy" team
int B_Event::getNumberEnemyDestination() const
{
	return m_numberEnemyDestination;
}


// Modify the description of the event in the fight
int B_Event::setDescription(const std::string &description)
{
	m_description = description;

	return 0;
}


// Modify the number of destination for "ally" team
int B_Event::setNumberAllyDestination(const int &n)
{
	if (n < 0)
		return -1;

	m_numberAllyDestination = n;

	return 0;
}


// Modify the number of destination for "enemy" team
int B_Event::setNumberEnemyDestination(const int &n)
{
	if (n < 0)
		return -1;

	m_numberEnemyDestination = n;

	return 0;
}


// Do the event
int B_Event::execute(Battle *bat)
{
	return 0;
}