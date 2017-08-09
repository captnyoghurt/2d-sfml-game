#pragma once

#include "BattleEffects.h"

class Spell
{
public:
	Spell();
	Spell(int id, std::string name, int damage, int allyDestination, int enemiDestination, int costHP, int costMP, int costTP, int chanceSleep, int chancePoison, int chanceParalysis, int chanceMute);
	Spell(const Spell &sp);
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
	// Return the chance of sleep
	int getChanceSleep() const;
	// Return the chance of poison
	int getChancePoison() const;
	// Return the chance of paralysis
	int getChanceParalysis() const;
	// Return the chance of mute
	int getChanceMute() const;

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
	// Modify the chance of sleep
	int setChanceSleep(const int &chance);
	// Modify the chance of poison
	int setChancePoison(const int &chance);
	// Modify the chance of paralysis
	int setChanceParalysis(const int &chance);
	// Modify the chance of mute
	int setChanceMute(const int &chance);

public:
	int m_id;
	std::string m_name;
	int m_damage;
	int m_allyDestination;
	int m_enemiDestination;
	int m_costHP;
	int m_costMP;
	int m_costTP;
	int m_chanceSleep;
	int m_chancePoison;
	int m_chanceParalysis;
	int m_chanceMute;
};

