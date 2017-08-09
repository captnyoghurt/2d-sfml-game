#pragma once

#include <vector>
#include "json/json.h"

class BattleEffects;
class Spell;

class DatabaseJson
{
public:
	enum e_JsonDatabase {JD_MONSTERS, JD_SPELLS, JD_EFFECTS, JD_TOTAL};

public:
	DatabaseJson();
	~DatabaseJson();

public:
	// Return the roots with modifying possibilities
	std::vector<Json::Value>& getRealRoots();
	// Return the readers with modifying possibilities
	std::vector<Json::Reader>& getRealReaders();

	// Return the battle effect
	BattleEffects getBattleEffects(int id);
	// Return the spell
	Spell getSpell(int id);

protected:
	int loadDatabase(int i, const std::string &filename);

private:
	std::vector<Json::Value> m_roots;
	std::vector<Json::Reader> m_readers;
};

