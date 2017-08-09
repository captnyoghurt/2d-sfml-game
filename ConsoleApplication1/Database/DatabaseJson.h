#pragma once

#include <vector>
#include "json/json.h"

class BattleEffects;
class Spell;
class Fighter;

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
	// Return the monster
	Fighter getFighter(int id);

	// Return the spell with the effects
	Spell getFullSpell(int id);

protected:
	int loadDatabase(int i, const std::string &filename);
	int loadMatching(std::vector< std::vector<int> > &v, const std::string &filename, const std::string &key1, const std::string &key2);

private:
	std::vector<Json::Value> m_roots;
	std::vector<Json::Reader> m_readers;
	std::vector< std::vector<int> > m_matchSpellsEffects;
	std::vector< std::vector<int> > m_matchMonstersSpells;
};

