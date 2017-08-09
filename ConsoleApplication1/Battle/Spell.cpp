#include "Spell.h"
#include "../Error/ValueException.h"



Spell::Spell()
{
}


Spell::~Spell()
{
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


// Modify the id
int Spell::setId(const int &id)
{
	if (id <= 0)
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