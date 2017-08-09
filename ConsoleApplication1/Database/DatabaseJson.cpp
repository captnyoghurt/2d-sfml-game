#include <fstream>
#include "DatabaseJson.h"
#include "../constants.h"
#include "../Error/RessourceException.h"
#include "../Error/InitializationException.h"
#include "../Error/ValueException.h"
#include "../Battle/BattleEffects.h"



DatabaseJson::DatabaseJson()
{
	m_roots.resize(DatabaseJson::e_JsonDatabase::JD_TOTAL);
	m_readers.resize(DatabaseJson::e_JsonDatabase::JD_TOTAL);

	loadDatabase(DatabaseJson::e_JsonDatabase::JD_MONSTERS, DATABASE_JSON_NAME_MONSTERS);
	loadDatabase(DatabaseJson::e_JsonDatabase::JD_MONSTERS_SPELLS, DATABASE_JSON_NAME_MONSTERS_SPELLS);
	loadDatabase(DatabaseJson::e_JsonDatabase::JD_SPELLS, DATABASE_JSON_NAME_SPELLS);
	loadDatabase(DatabaseJson::e_JsonDatabase::JD_SPELLS_EFFECTS, DATABASE_JSON_NAME_SPELLS_EFFECTS);
	loadDatabase(DatabaseJson::e_JsonDatabase::JD_EFFECTS, DATABASE_JSON_NAME_EFFECTS);
}


DatabaseJson::~DatabaseJson()
{
}


// Return the roots with modifying possibilities
std::vector<Json::Value>& DatabaseJson::getRealRoots()
{
	return m_roots;
}


// Return the readers with modifying possibilities
std::vector<Json::Reader>& DatabaseJson::getRealReaders()
{
	return m_readers;
}


// Return the battle effect
BattleEffects DatabaseJson::getBattleEffects(int id)
{
	BattleEffects be;
	std::string strId(std::to_string(id));

	if (id <= 0)
		THROW_VALUE("Wrong id " + strId);

	//be.setId(id);
	be.setCharacteristic(Characteristic::e_characteristics(m_roots.at(JD_EFFECTS)[id].get("type", "ASCII").asInt()));
	be.setChance(m_roots.at(JD_EFFECTS)[id].get("chance", "ASCII").asInt());
	//be.setPower(m_roots.at(JD_EFFECTS)[id].get("quantity", "ASCII").asInt());
	be.setTargetType(BattleEffects::e_EffectsTarget(m_roots.at(JD_EFFECTS)[id].get("target", "ASCII").asInt()));
	be.setNumberOfPeople(m_roots.at(JD_EFFECTS)[id].get("numberOfPeople", "ASCII").asInt());

	return be;
}


int DatabaseJson::loadDatabase(int i, const std::string &filename)
{
	if (i < 0 || i >= DatabaseJson::e_JsonDatabase::JD_TOTAL)
		THROW_GAME("Impossible JDB " + std::to_string(i));

	std::ifstream file(filename);
	if (!file.is_open())
		THROW_RESSOURCE("JDB", filename);

	if (!m_readers.at(i).parse(file, m_roots.at(i), false))
		THROW_INIT("Couldn't parse JDB");

	return 0;
}