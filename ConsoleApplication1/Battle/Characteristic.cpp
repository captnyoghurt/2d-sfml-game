#include "Characteristic.h"
#include "../constants.h"
#include "Spell.h"


Characteristic::Characteristic()
{
	m_points = 0;
	m_maxPoints = 0;
	m_bonus = 0;
}


Characteristic::Characteristic(int points, int maxPoints)
{
	m_points = points;
	m_maxPoints = maxPoints;
	m_bonus = 0;
}


Characteristic::Characteristic(const Characteristic& c)
{
	m_points = c.getPoints();
	m_maxPoints = c.getMaxPoints();
	m_bonus = c.getBonus();
	m_effects = c.getEffects();
}


Characteristic::~Characteristic()
{
}


Characteristic& Characteristic::operator=(const Characteristic &c)
{
	m_points = c.getPoints();
	m_maxPoints = c.getMaxPoints();
	m_bonus = c.getBonus();
	m_effects = c.getEffects();
	return *this;
}


// Return the number of health points
int Characteristic::getPoints() const
{
	return m_points;
}


// Return the maximum number of health points
int Characteristic::getMaxPoints() const
{
	return m_maxPoints;
}


// Return the actual health bonus
int Characteristic::getBonus() const
{
	return m_bonus;
}


// Return the total amount of points
int Characteristic::getValue() const
{
	return m_points + m_bonus;
}


// Return all the actual effects
std::list<EffectOnCharacteristic> Characteristic::getEffects() const
{
	return m_effects;
}


// Return all the actual effects with modifying possibilities
std::list<EffectOnCharacteristic>& Characteristic::getRealEffects()
{
	return m_effects;
}


// Modify the number of health points
int Characteristic::setPoints(const int &p)
{
	if (p >= 0 && p <= m_maxPoints)
	{
		m_points = p;
		return 0;
	}

	return -1;
}


// Modify the maximum number of mana points
int Characteristic::setMaxPoints(const int &maxp)
{
	if (maxp < 0)
		return -1;

	m_maxPoints = maxp;

	if (m_points > m_maxPoints)
		m_points = m_maxPoints;

	return 0;
}


// Say if a spell can be used
bool Characteristic::canCastSpell(const Spell &sp)
{
	//[TODO]

	return true;
}


// Say if there is enought health point
bool Characteristic::enoughFor(const int &points)
{
	return (m_points >= points);
}


// Use some health points
int Characteristic::use(const int &points)
{
	if (!enoughFor(points))
		return -1;

	m_points -= points;

	return 0;
}
int Characteristic::use(const Spell &sp)
{
	if (!canCastSpell(sp))
		return -1;

	//[TODO]

	return 0;
}


// Get some health
int Characteristic::recharge(const int &points)
{
	m_points = MIN(m_points + points, m_maxPoints);

	return 0;
}

// Update effects
int Characteristic::updateEffects()
{
	m_bonus = 0;

	for (auto it(m_effects.begin()); it != m_effects.end(); it++)
	{
		int ret = it->update();
		if (ret == 1)
		{
			it = m_effects.erase(it);
			it--;
		}
		else
		{
			m_bonus += it->getBrut();
			m_bonus += int(m_maxPoints * it->getRatio());
		}
	}

	return 0;
}