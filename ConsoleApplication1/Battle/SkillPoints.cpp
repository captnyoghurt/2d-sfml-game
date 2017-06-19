#include "../constants.h"
#include "SkillPoints.h"
#include "Spell.h"


SkillPoints::SkillPoints()
{
	m_maxPoints = SKILLPOINTS_MAX_POINTS;
	m_points = 0;
}

SkillPoints::SkillPoints(const SkillPoints &skp)
{
	m_maxPoints = skp.getMaxPoints();
	m_points = skp.getPoints();
}

SkillPoints::~SkillPoints()
{
}


// Return the number of skill points
int SkillPoints::getPoints() const
{
	return m_points;
}


// Return the maximum number of skill points
int SkillPoints::getMaxPoints() const
{
	return m_maxPoints;
}


// Return all the actual effects
std::list<EffectOnCharacteristic> SkillPoints::getEffects() const;
// Return all the actual adding effects
std::list<EffectOnCharacteristic> SkillPoints::getAddingEffects() const;


// Modify the number of skill points
int SkillPoints::setPoints(const int &p)
{
	if (p >= 0 && p <= m_maxPoints)
	{
		m_points = p;
		return 0;
	}
	return -1;
}


// Modify the maximum number of skill points
int SkillPoints::setMaxPoints(const int &maxp)
{
	if (maxp < 0)
		return -1;

	m_maxPoints = maxp;

	if (m_points > m_maxPoints)
		m_points = m_maxPoints;

	return 0;
}


// Say if a spell can be used
bool SkillPoints::canCastSpell(const Spell &sp)
{
	//[TODO]

	return true;
}


// Say if there is enought skill point
bool SkillPoints::enoughFor(const int &points)
{
	return (m_points >= points);
}


// Use some skill points
int SkillPoints::use(const int &points)
{
	if (!enoughFor(points))
		return -1;

	m_points -= points;

	return 0;
}
int SkillPoints::use(const Spell &sp)
{
	if(!canCastSpell(sp))
		return -1;

	//[TODO]

	return 0;
}


// Get some skill points
int SkillPoints::recharge(const int &points)
{
	m_points = MIN(m_points + points, m_maxPoints);

	return 0;
}