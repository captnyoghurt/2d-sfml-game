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


// Return the chance
int BattleEffects::getChance() const
{
	return m_chance;
}


// Return the target type
BattleEffects::e_EffectsTarget BattleEffects::getTargetType() const
{
	return m_targetType;
}


// Return the number of people
int BattleEffects::getNumberOfPeople() const
{
	return m_numberOfPeople;
}


// Modify the id
int BattleEffects::setId(const int &id)
{
	if (id <= 0)
		THROW_VALUE(std::to_string(id));

	m_id = id;

	return 0;
}


// Modify the characteristic
int BattleEffects::setCharacteristic(const Characteristic::e_characteristics &c)
{
	if (c < 0 || c >= Characteristic::e_characteristics::CHARACTERISTICS_TOTAL)
		THROW_VALUE("Impossible characteristic value " + std::to_string(c));

	m_characteristic = c;

	return 0;
}


// Modify the chance
int BattleEffects::setChance(const int &ch)
{
	if (ch < 0 || ch > 100)
		THROW_VALUE("Impossible value of chance " + std::to_string(ch));

	m_chance = ch;

	return 0;
}


// Modify the target type
int BattleEffects::setTargetType(const BattleEffects::e_EffectsTarget &et)
{
	if (et < 0 || et > BattleEffects::e_EffectsTarget::ET_ALL)
		THROW_VALUE("Impossible value of effects target" + std::to_string(et));

	m_targetType = et;

	return 0;
}


// Modify the number of people
int BattleEffects::setNumberOfPeople(const int &n)
{
	m_numberOfPeople = n;

	return 0;
}