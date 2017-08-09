#pragma once

#include "Characteristic.h"

class BattleEffects
{
public:
	enum e_EffectsTarget {ET_ALLY, ET_ENEMI, ET_ALL};

public:
	BattleEffects();
	~BattleEffects();

public:
	// Return the id
	int getId() const;
	// Return the characteristic
	Characteristic::e_characteristics getCharacteristic() const;
	// Return the chance
	int getChance() const;
	// Return the power
	int getPower() const;
	// Return the target type
	e_EffectsTarget getTargetType() const;
	// Return the number of people
	int getNumberOfPeople() const;

	// Modify the id
	int setId(const int &id);
	// Modify the characteristic
	int setCharacteristic(const Characteristic::e_characteristics &c);
	// Modify the chance
	int setChance(const int &ch);
	// Modify the power
	int setPower(const int &po);
	// Modify the target type
	int setTargetType(const e_EffectsTarget &et);
	// Modify the number of people
	int setNumberOfPeople(const int &n);

private:
	int m_id;
	Characteristic::e_characteristics m_characteristic;
	int m_chance;
	int m_power;
	e_EffectsTarget m_targetType;
	int m_numberOfPeople;
};

