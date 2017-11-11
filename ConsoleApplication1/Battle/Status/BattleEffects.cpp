#include "BattleEffects.h"
#include "../../Error/ValueException.h"



BattleEffects::BattleEffects()
{
}


BattleEffects::BattleEffects(const int id, const Characteristic::e_characteristics &c, const int &chance, const int &power, const e_EffectsTarget &et, const int &people) :
	m_id(id),
	m_characteristic(c),
	m_chance(chance),
	m_power(power),
	m_targetType(et),
	m_numberOfPeople(people)
{
}


BattleEffects::BattleEffects(const BattleEffects &be)
{
	m_id = be.getId();
	m_characteristic = be.getCharacteristic();
	m_chance = be.getChance();
	m_power = be.getPower();
	m_targetType = be.getTargetType();
	m_numberOfPeople = be.getNumberOfPeople();
}


BattleEffects::~BattleEffects()
{
}


BattleEffects& BattleEffects::operator=(const BattleEffects &be)
{
	m_id = be.getId();
	m_characteristic = be.getCharacteristic();
	m_chance = be.getChance();
	m_power = be.getPower();
	m_targetType = be.getTargetType();
	m_numberOfPeople = be.getNumberOfPeople();

	return *this;
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


// Return the power
int BattleEffects::getPower() const
{
	return m_power;
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
	if (id < 0)
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


// Modify the power
int BattleEffects::setPower(const int &po)
{
	m_power = po;

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