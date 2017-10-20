#include "../constants.h"
#include "Health.h"
#include "Spell.h"


Health::Health()
{
}


Health::Health(const Health &h)
{
	setMaxPoints(h.getMaxPoints());
	setPoints(h.getPoints());
	m_continuousEffects = h.getContinuousEffects();
	m_effects = h.getEffects();
	m_bonus = h.getBonus();
}


Health::Health(const int &max)
{
	setMaxPoints(max);
	setPoints(max);
	m_bonus = 0;
}

Health::~Health()
{
}


Health& Health::operator=(const Health& h)
{
	setMaxPoints(h.getMaxPoints());
	setPoints(h.getPoints());
	m_continuousEffects = h.getContinuousEffects();
	m_effects = h.getEffects();
	m_bonus = h.getBonus();

	return *this;
}


// Return the number of health points
int Health::getPoints() const
{
	return m_points;
}


// Return the maximum number of health points
int Health::getMaxPoints() const
{
	return m_maxPoints;
}


// Return the actual health bonus
int Health::getBonus() const
{
	return m_bonus;
}


// Return all the actual effects
std::list<EffectOnCharacteristic> Health::getEffects() const
{
	return m_effects;
}


// Return all the actual adding effects
std::list<EffectOnCharacteristic> Health::getContinuousEffects() const
{
	return m_continuousEffects;
}


// Return all the actual effects with modifying possibilities
std::list<EffectOnCharacteristic>& Health::getRealEffects()
{
	return m_effects;
}


// Return all the actual adding effects with modifying possibilities
std::list<EffectOnCharacteristic>& Health::getRealContinuousEffects()
{
	return m_continuousEffects;
}


// Modify the number of health points
int Health::setPoints(const int &p)
{
	if (p >= 0 && p <= m_maxPoints)
	{
		m_points = p;
		return 0;
	}

	return -1;
}


// Modify the maximum number of mana points
int Health::setMaxPoints(const int &maxp)
{
	if (maxp < 0)
		return -1;

	m_maxPoints = maxp;

	if (m_points > m_maxPoints)
		m_points = m_maxPoints;

	return 0;
}


// Say if a spell can be used
bool Health::canCastSpell(const Spell &sp)
{
	//[TODO]

	return true;
}


// Say if there is enought health point
bool Health::enoughFor(const int &points)
{
	return (m_points >= points);
}


// Use some health points
int Health::use(const int &points)
{
	if (!enoughFor(points))
	{
		m_points = 0;
		return 1;
	}

	m_points -= points;

	return 0;
}
int Health::use(const Spell &sp)
{
	if (!canCastSpell(sp))
		return -1;

	//[TODO]

	return 0;
}


// Get some health
int Health::recharge(const int &points)
{
	m_points = MIN(m_points + points, m_maxPoints);

	return 0;
}

// Update effects
int Health::updateEffects()
{
	int contBonus(0);
	m_bonus = 0;

	for (auto it(m_effects.begin()) ; it != m_effects.end(); it++)
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

	for (auto it(m_continuousEffects.begin()); it != m_effects.end(); it++)
	{
		int ret = it->update();
		if (ret == 1)
		{
			it = m_continuousEffects.erase(it);
			it--;
		}
		else
		{
			contBonus += it->getBrut();
			contBonus += int(m_maxPoints * it->getRatio());
		}
	}

	return ((contBonus > 0) ? recharge(contBonus) : use(contBonus));
}