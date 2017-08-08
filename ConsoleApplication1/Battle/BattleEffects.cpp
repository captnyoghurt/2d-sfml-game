#include "BattleEffects.h"
#include "../Error/ValueException.h"



BattleEffects::BattleEffects()
{
}


BattleEffects::~BattleEffects()
{
}


// Return the id
int BattleEffects::getId() const
{
	return m_id;
}


// Return the characteristic
Characteristic::e_characteristics BattleEffects::getCharacteristic() const
{
	return m_characteristic;
}


// Modify the characteristic
int BattleEffects::setCharacteristic(const Characteristic::e_characteristics &c)
{
	if (c < 0 || c >= Characteristic::e_characteristics::CHARACTERISTICS_TOTAL)
		THROW_VALUE("Impossible characteristic value " + std::to_string(c));

	m_characteristic = c;

	return 0;
}