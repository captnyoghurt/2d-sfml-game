#include "B_EventAttack.h"



B_EventAttack::B_EventAttack()
{
}


B_EventAttack::B_EventAttack(std::shared_ptr<Fighter> source, std::shared_ptr<Fighter> dest, const std::string &description)
{
	m_source = source;
	m_destination = dest;
	m_description = description;
}


B_EventAttack::~B_EventAttack()
{
}


// Return if the fighter source of the attack
std::shared_ptr<Fighter> B_EventAttack::getSource()
{
	return m_source;
}


// Return if the fighter destination of the attack
std::shared_ptr<Fighter> B_EventAttack::getDestination()
{
	return m_destination;
}


// Modify if the fighter source of the attack
int B_EventAttack::setSource(std::shared_ptr<Fighter> src)
{
	m_source = src;
	return 0;
}


// Modify if the fighter destination of the attack
int B_EventAttack::setDestination(std::shared_ptr<Fighter> dest)
{
	m_destination = dest;
	return 0;
}


// Do the event
int B_EventAttack::execute(Battle &bat)
{
	// [TODO]
	// L'attaque
	// /!\ S'il y a un effet miroir sur le receveur

	return 0;
}