#pragma once

#include <list>
#include "EffectOnCharacteristic.h"

class Spell;

class Mana
{
public:
	Mana();
	Mana(const Mana &mana);
	Mana(const int &max);
	~Mana();

public:
	// Return the number of mana points
	int getPoints() const;
	// Return the maximum number of mana points
	int getMaxPoints() const;
	// Return all the actual effects
	std::list<EffectOnCharacteristic> getEffects() const;
	// Return all the actual adding effects
	std::list<EffectOnCharacteristic> getAddingEffects() const;

	// Modify the number of mana points
	int setPoints(const int &p);
	// Modify the maximum number of mana
	int setMaxPoints(const int &maxp);

	// Say if a spell can be used
	bool canCastSpell(const Spell &sp);
	// Say if there is enought mana
	bool enoughFor(const int &points);

	// Use some mana points
	int use(const int &points);
	int use(const Spell &sp);
	// Get some mana points
	int recharge(const int &points);
private:
	int m_maxPoints;
	int m_points;
};

