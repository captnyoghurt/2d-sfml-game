#include "TeamMate.h"
#include "B_Event.h"
#include "../Error/GameException.h"
#include "../Game.h"
#include "Characteristic.h"
#include "../constants.h"
#include "../Error/ValueException.h"


TeamMate::TeamMate() :
	m_courbs(Characteristic::e_characteristics::CHARACTERISTICS_TOTAL),
	m_experience(0),
	m_level(0)
{
}


TeamMate::TeamMate(const TeamMate &tm) :
	Fighter(tm),
	m_courbs(tm.getCourbs()),
	m_expCourb(tm.getExpCourb()),
	m_experience(0),
	m_level(0)
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


// Return the experience courb
CharCourb TeamMate::getExpCourb() const
{
	return m_expCourb;
}


// Return the current experience
int TeamMate::getExperience() const
{
	return m_experience;
}


// Return the current level
int TeamMate::getLevel() const
{
	return m_level;
}


// Return the courbs with modifying possibilities
std::vector<CharCourb>& TeamMate::getRealCourb()
{
	return m_courbs;
}


// Modify the experience courb
int TeamMate::setExpCourb(const CharCourb &exp)
{
	m_expCourb = exp;

	return 0;
}


// Modify the current experience
int TeamMate::setExperience(const int &experience)
{
	int exp(experience);
	while (!((int)m_expCourb.result(m_level) < experience))
	{
		exp -= (int)m_expCourb.result(m_level);
		m_level += 1;
		if (m_level > CHARACTER_LEVEL_MAX)
			THROW_VALUE("Too much experience : " + std::to_string(m_level));
	}
		
	return 0;
}


// Modify the current level
int TeamMate::setLevel(const int &lvl)
{
	if (lvl < 1 || lvl > CHARACTER_LEVEL_MAX)
		THROW_VALUE("Wrong value of level : " + std::to_string(lvl));

	m_level = lvl;

	return 0;
}


// Add some XP
int TeamMate::addExperience(const int &exp)
{
	int px(exp);

	if (exp < 0)
		THROW_VALUE("Wrong value of exp : " + std::to_string(exp));

	while (m_experience + px >= (int)m_expCourb.result(m_level))
	{
		px -= ((int)m_expCourb.result(m_level) - m_experience);
		m_experience = 0;
		m_level++;
	}
	m_experience += px;

	return 0;
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