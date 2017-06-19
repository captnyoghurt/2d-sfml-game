#include "B_Event.h"
#include "Battle.h"


B_Event::B_Event()
{
	m_description = "Evenement inconnu";
}


B_Event::~B_Event()
{
}


// Return the description of the event in the fight
std::string B_Event::getDescription() const
{
	return m_description;
}


// Modify the description of the event in the fight
int B_Event::setDescription(const std::string &description)
{
	m_description = description;

	return 0;
}


// Do the event
int B_Event::execute(Battle &bat)
{
	return 0;
}