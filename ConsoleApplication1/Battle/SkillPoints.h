#pragma once

#include <list>
#include "EffectOnCharacteristic.h"

class Spell;

class SkillPoints
{
public:
	SkillPoints();
	SkillPoints(const SkillPoints &skp);
	explicit SkillPoints(const int &max);
	~SkillPoints();

	SkillPoints& operator=(const SkillPoints &skp);
public:
	// Return the number of skill points
	int getPoints() const;
	// Return the maximum number of skill points
	int getMaxPoints() const;
	// Return all the actual effects
	std::list<EffectOnCharacteristic> getEffects() const;
	// Return all the actual adding effects
	std::list<EffectOnCharacteristic> getAddingEffects() const;

	// Modify the number of skill points
	int setPoints(const int &p);
	// Modify the maximum number of skill points
	int setMaxPoints(const int &maxp);

	// Say if a spell can be used
	bool canCastSpell(const Spell &sp);
	// Say if there is enought skill point
	bool enoughFor(const int &points);

	// Use some skill points
	int use(const int &points);
	int use(const Spell &sp);
	// Get some skill points
	int recharge(const int &points);
private:
	int m_maxPoints;
	int m_points;
	std::list<EffectOnCharacteristic> m_effects;
	std::list<EffectOnCharacteristic> m_addingEffects;
};

