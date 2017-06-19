#include "B_EventDefense.h"



B_EventDefense::B_EventDefense()
{
}


B_EventDefense::B_EventDefense(std::shared_ptr<Fighter> dest, const std::string &description)
{
	m_destination = dest;
	m_description = description;
}


B_EventDefense::~B_EventDefense()
{
}


// Return if the fighter destination of the defense
std::shared_ptr<Fighter> B_EventDefense::getDestination()
{
	return m_destination;
}


// Modify if the fighter destination of the defense
int B_EventDefense::setDestination(std::shared_ptr<Fighter> dest)
{
	m_destination = dest;
	return 0;
}


// Do the event
int B_EventDefense::execute(Battle &bat)
{
	// [TODO]
	// Effet de +50%

	return 0;
}