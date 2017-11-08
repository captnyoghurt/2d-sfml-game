#include "TeamMate.h"
#include "B_Event.h"
#include "../Error/GameException.h"
#include "../Game.h"
#include "Characteristic.h"
#include "../constants.h"
#include "../Error/ValueException.h"


TeamMate::TeamMate() :
	Fighter(),
	m_courbs(Characteristic::e_characteristics::CHARACTERISTICS_TOTAL),
	m_experience(0),
	m_level(0)
{
}


TeamMate::TeamMate(const TeamMate &tm) :
	Fighter(tm),
	m_courbs(tm.getCourbs()),
	m_basicSpells(tm.getBasicSpells()),
	m_expCourb(tm.getExpCourb()),
	m_healthCourb(tm.getHealthCourb()),
	m_manaCourb(tm.getManaCourb()),
	m_experience(0),
	m_level(0)
{

}


TeamMate::~TeamMate()
{
}


TeamMate& TeamMate::operator=(const TeamMate &tm)
{
	m_name = tm.getName();
	m_characteristics = tm.getCharacteristics();
	m_health = tm.getHealth();
	m_mana = tm.getMana();
	m_skillPoints = tm.getSkillPoints();
	m_spells = tm.getSpells();
	m_characteristics.resize(Characteristic::e_characteristics::CHARACTERISTICS_TOTAL, Characteristic(0, 0));

	m_courbs = tm.getCourbs();
	m_expCourb = tm.getExpCourb();
	m_experience = 0;
	m_level = 0;

	return *this;
}


// Return the courbs
std::vector<CharCourb> TeamMate::getCourbs() const
{
	return m_courbs;
}


// Return the basic spells
std::vector<std::pair<int, Spell> > TeamMate::getBasicSpells() const
{
	return m_basicSpells;
}


// Return the experience courb
CharCourb TeamMate::getExpCourb() const
{
	return m_expCourb;
}


// Return the health courb
CharCourb TeamMate::getHealthCourb() const
{
	return m_healthCourb;
}


// Return the mana courb
CharCourb TeamMate::getManaCourb() const
{
	return m_manaCourb;
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


// Return the basic spells with modifying possibilities
std::vector<std::pair<int, Spell> >& TeamMate::getRealBasicSpells()
{
	return m_basicSpells;
}


// Modify the experience courb
int TeamMate::setExpCourb(const CharCourb &exp)
{
	m_expCourb = exp;

	return 0;
}


// Modify the health courb
int TeamMate::setHealthCourb(const CharCourb &h)
{
	m_healthCourb = h;

	return 0;
}


// Modify the mana courb
int TeamMate::setManaCourb(const CharCourb &m)
{
	m_manaCourb = m;

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


// Reload the TeamMate with the new courbs
int TeamMate::reload(const bool &healing)
{
	for (unsigned int i(0); i < m_characteristics.size(); i++)
	{
		//m_characteristics.at(i).setMaxPoints(m_courbs.at(i).result(m_level));
		m_characteristics.at(i).setPoints(m_courbs.at(i).result(m_level));
	}

	m_health.setMaxPoints(m_healthCourb.result(m_level));
	if (healing)
		m_health.setPoints(m_health.getMaxPoints());
	m_mana.setMaxPoints(m_manaCourb.result(m_level));
	if (healing)
		m_mana.setPoints(m_mana.getMaxPoints());

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