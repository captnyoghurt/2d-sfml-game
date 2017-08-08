#include "TeamMate.h"
#include "B_Event.h"
#include "../Error/GameException.h"
#include "../Game.h"



TeamMate::TeamMate()
{
}


TeamMate::TeamMate(const TeamMate &tm) : Fighter(tm)
{

}


TeamMate::~TeamMate()
{
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