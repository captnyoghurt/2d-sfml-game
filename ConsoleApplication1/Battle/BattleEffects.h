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

	// Modify the characteristic
	int setCharacteristic(const Characteristic::e_characteristics &c);

private:
	int m_id;
	Characteristic::e_characteristics m_characteristic;
};

