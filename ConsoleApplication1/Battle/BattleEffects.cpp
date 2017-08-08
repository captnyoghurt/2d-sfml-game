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


// Return the chance
int BattleEffects::getChance() const
{
	return m_chance;
}


// Modify the chance
int BattleEffects::setChance(const int &ch)
{
	if (ch < 0 || ch > 100)
		THROW_VALUE("Impossible value of chance " + std::to_string(ch));

	m_chance = ch;

	return 0;
}