#pragma once

#include "Characteristic.h"

class BattleEffects
{
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

	// Modify the characteristic
	int setCharacteristic(const Characteristic::e_characteristics &c);
	// Modify the chance
	int setChance(const int &ch);

private:
	int m_id;
	Characteristic::e_characteristics m_characteristic;
	int m_chance;
};

