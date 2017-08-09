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

	// Modify the id
	int setId(const int &id);
	// Modify the name
	int setName(const std::string &name);

public:
	int m_id;
	std::string m_name;
};

