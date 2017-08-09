#pragma once

#include "BattleEffects.h"

class Spell
{
public:
	Spell();
	~Spell();

public:
	// Return the id
	int getId() const;
	// Return the name
	std::string getName() const;
	// Return the damage
	int getDamage() const;
	// Return ally destination
	int getAllyDestination() const;
	// Return the enemi destination
	int getEnemiDestination() const;
	// Return the hp cost
	int getCostHP() const;
	// Return the mp cost
	int getCostMP() const;
	// Return the tp cost
	int getCostTP() const;

	// Modify the id
	int setId(const int &id);
	// Modify the name
	int setName(const std::string &name);
	// Modify the damage
	int setDamage(const int &d);
	// Modify ally destination
	int setAllyDestination(const int &ad);
	// Modify enemi destination
	int setEnemiDestination(const int &ed);
	// Modify the hp cost
	int setCostHP(const int &cost);
	// Modify the mp cost
	int setCostMP(const int &cost);
	// Modify the tp cost
	int setCostTP(const int &cost);

public:
	int m_id;
	std::string m_name;
	int m_damage;
	int m_allyDestination;
	int m_enemiDestination;
	int m_costHP;
	int m_costMP;
	int m_costTP;
};

