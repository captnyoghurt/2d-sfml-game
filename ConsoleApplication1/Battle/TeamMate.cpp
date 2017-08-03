#include "TeamMate.h"



TeamMate::TeamMate()
{
}


TeamMate::TeamMate(const TeamMate &tm) : Fighter(tm)
{

}


TeamMate::~TeamMate()
{
}


// True if the fighter is in reality a TeamMate
bool TeamMate::isTeamMate() const
{
	return true;
}