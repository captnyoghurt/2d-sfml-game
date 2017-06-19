#pragma once

#include <list>
#include "EffectOnCharacteristic.h"

class Spell;

class Health
{
public:
	Health();
	Health(const Health &h);
	~Health();

public:
	// Return the number of health points
	int getPoints() const;
	// Return the maximum number of health points
	int getMaxPoints() const;
	// Return the actual health bonus
	int getBonus() const;
	// Return all the actual effects
	std::list<EffectOnCharacteristic> getEffects() const;
	// Return all the actual adding effects
	std::list<EffectOnCharacteristic> getContinuousEffects() const;

	// Return all the actual effects with modifying possibilities
	std::list<EffectOnCharacteristic>& getRealEffects();
	// Return all the actual adding effects with modifying possibilities
	std::list<EffectOnCharacteristic>& getRealContinuousEffects();

	// Modify the number of health points
	int setPoints(const int &p);
	// Modify the maximum number of health
	int setMaxPoints(const int &maxp);

	// Say if a spell can be used
	bool canCastSpell(const Spell &sp);
	// Say if there is enought health
	bool enoughFor(const int &points);

	// Use some health points
	int use(const int &points);
	int use(const Spell &sp);
	// Get some health points
	int recharge(const int &points);
	// Update effects
	int updateEffects();

private:
	int m_maxPoints;
	int m_points;
	int m_bonus;
	std::list<EffectOnCharacteristic> m_effects;
	std::list<EffectOnCharacteristic> m_continuousEffects;
};

