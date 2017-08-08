#pragma once

#include <vector>
#include "json/json.h"

class DatabaseJson
{
public:
	enum e_JsonDatabase {JD_MONSTERS, JD_MONSTERS_SPELLS, JD_SPELLS, JD_SPELLS_EFFECTS, JD_EFFECTS, JD_TOTAL};

public:
	DatabaseJson();
	~DatabaseJson();

public:
	// Return the roots with modifying possibilities
	std::vector<Json::Value>& getRealRoots();
	// Return the readers with modifying possibilities
	std::vector<Json::Reader>& getRealReaders();

private:
	std::vector<Json::Value> m_roots;
	std::vector<Json::Reader> m_readers;
};

