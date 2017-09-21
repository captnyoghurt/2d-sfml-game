#include "TeamMate.h"
#include "B_Event.h"
#include "../Error/GameException.h"
#include "../Game.h"
#include "Characteristic.h"



TeamMate::TeamMate() :
	m_courbs(Characteristic::e_characteristics::CHARACTERISTICS_TOTAL + 1)
{
}


TeamMate::TeamMate(const TeamMate &tm) :
	Fighter(tm),
	m_courbs(Characteristic::e_characteristics::CHARACTERISTICS_TOTAL + 1)
{

}


TeamMate::~TeamMate()
{
}


// Return the courbs
std::vector<CharCourb> TeamMate::getCourbs() const
{
	return m_courbs;
}


// Return the courbs with modifying possibilities
std::vector<CharCourb>& TeamMate::getRealCourb()
{
	return m_courbs;
}


// Take a decision for the next battle action
std::shared_ptr<B_Event> TeamMate::chooseEvent(Game *g)
{
	THROW_GAME("Shouldn't be ever called");

	return std::make_shared<B_Event>(B_Event());
}


// True if the fighter is in reality a TeamMate
bool TeamMate::isTeamMate() const
{
	return true;
}