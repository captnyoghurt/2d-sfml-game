#include "Spell.h"
#include "../Error/ValueException.h"



Spell::Spell()
{
}

Spell::Spell(int id, const std::string name, int damage, int allyDestination, int enemiDestination, int costHP, int costMP, int costTP, int chanceSleep, int chancePoison, int chanceParalysis, int chanceMute, int iconId, const std::string &desc) :
	m_id(id),
	m_name(name),
	m_damage(damage),
	m_allyDestination(allyDestination),
	m_enemiDestination(enemiDestination),
	m_costHP(costHP),
	m_costMP(costMP),
	m_costTP(costTP),
	m_chanceSleep(chanceSleep),
	m_chancePoison(chancePoison),
	m_chanceParalysis(chanceParalysis),
	m_chanceMute(chanceMute),
	m_iconId(iconId),
	m_description(desc)
{

}


Spell::Spell(const Spell &sp)
{
	m_id = sp.getId();
	m_name = sp.getName();
	m_damage = sp.getDamage();
	m_allyDestination = sp.getAllyDestination();
	m_enemiDestination = sp.getEnemiDestination();
	m_costHP = sp.getCostHP();
	m_costMP = sp.getCostMP();
	m_costTP = sp.getCostTP();
	m_chanceSleep = sp.getChanceSleep();
	m_chancePoison = sp.getChancePoison();
	m_chanceParalysis = sp.getChanceParalysis();
	m_chanceMute = sp.getChanceMute();
	m_description = sp.getDescription();
	m_effects = sp.getEffects();
}


Spell::~Spell()
{
}


Spell& Spell::operator=(const Spell &sp)
{
	m_id = sp.getId();
	m_name = sp.getName();
	m_damage = sp.getDamage();
	m_allyDestination = sp.getAllyDestination();
	m_enemiDestination = sp.getEnemiDestination();
	m_costHP = sp.getCostHP();
	m_costMP = sp.getCostMP();
	m_costTP = sp.getCostTP();
	m_chanceSleep = sp.getChanceSleep();
	m_chancePoison = sp.getChancePoison();
	m_chanceParalysis = sp.getChanceParalysis();
	m_chanceMute = sp.getChanceMute();
	m_description = sp.getDescription();
	m_effects = sp.getEffects();

	return *this;
}


// Return the id
int Spell::getId() const
{
	return m_id;
}


// Return the name
std::string Spell::getName() const
{
	return m_name;
}


// Return the damage
int Spell::getDamage() const
{
	return m_damage;
}


// Return ally destination
int Spell::getAllyDestination() const
{
	return m_allyDestination;
}


// Return the enemi destination
int Spell::getEnemiDestination() const
{
	return m_enemiDestination;
}


// Return the hp cost
int Spell::getCostHP() const
{
	return m_costHP;
}


// Return the mp cost
int Spell::getCostMP() const
{
	return m_costMP;
}


// Return the tp cost
int Spell::getCostTP() const
{
	return m_costTP;
}


// Return the chance of sleep
int Spell::getChanceSleep() const
{
	return m_chanceParalysis;
}


// Return the chance of poison
int Spell::getChancePoison() const
{
	return m_chancePoison;
}


// Return the chance of paralysis
int Spell::getChanceParalysis() const
{
	return m_chanceParalysis;
}


// Return the chance of mute
int Spell::getChanceMute() const
{
	return m_chanceMute;
}


// Return the icon id
int Spell::getIconId() const
{
	return m_iconId;
}


// Return the battle effects
std::deque<BattleEffects> Spell::getEffects() const
{
	return m_effects;
}


// Return the description
std::string Spell::getDescription() const
{
	return m_description;
}


// Return the battle effects with modifying possibilities
std::deque<BattleEffects>& Spell::getRealEffects()
{
	return m_effects;
}


// Modify the id
int Spell::setId(const int &id)
{
	if (id < 0)
		THROW_VALUE(std::to_string(id));

	m_id = id;

	return id;
}


// Modify the name
int Spell::setName(const std::string &name)
{
	m_name = name;

	return 0;
}


// Modify the damage
int Spell::setDamage(const int &d)
{
	if (d < 0)
		THROW_VALUE(std::to_string(d));

	m_damage = d;

	return 0;
}


// Return ally destination
int Spell::setAllyDestination(const int &ad)
{
	if (ad < 0)
		THROW_VALUE(std::to_string(ad));

	m_allyDestination = ad;

	return 0;
}


// Return enemi destination
int Spell::setEnemiDestination(const int &ed)
{
	if (ed < 0)
		THROW_VALUE(std::to_string(ed));

	m_enemiDestination = ed;

	return 0;
}


// Modify the hp cost
int Spell::setCostHP(const int &cost)
{
	m_costHP = cost;

	return 0;
}


// Modify the mp cost
int Spell::setCostMP(const int &cost)
{
	m_costMP = cost;

	return 0;
}


// Modify the tp cost
int Spell::setCostTP(const int &cost)
{
	m_costTP = cost;

	return 0;
}


// Modify the chance of sleep
int Spell::setChanceSleep(const int &chance)
{
	if (chance < 0 || chance > 100)
		THROW_VALUE(std::to_string(chance));

	m_chanceSleep = chance;

	return 0;
}


// Modify the chance of poison
int Spell::setChancePoison(const int &chance)
{
	if (chance < 0 || chance > 100)
		THROW_VALUE(std::to_string(chance));

	m_chancePoison = chance;

	return 0;
}


// Modify the chance of paralysis
int Spell::setChanceParalysis(const int &chance)
{
	if (chance < 0 || chance > 100)
		THROW_VALUE(std::to_string(chance));

	m_chanceParalysis = chance;

	return 0;
}


// Modify the chance of mute
int Spell::setChanceMute(const int &chance)
{
	if (chance < 0 || chance > 100)
		THROW_VALUE(std::to_string(chance));

	m_chanceMute = chance;

	return 0;
}


// Modify the description
int Spell::setDescription(const std::string &des)
{
	m_description = des;

	return 0;
}


// Modify the id icon
int Spell::setIconId(const int &id)
{
	if (id < 0)
		THROW_VALUE("Wrong icon id on spell : " + std::to_string(id));

	m_iconId = id;

	return 0;
}


// Add an effect
int Spell::addEffect(const BattleEffects &be)
{
	m_effects.push_back(be);

	return 0;
}