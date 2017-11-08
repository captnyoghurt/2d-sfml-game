#include <fstream>
#include "DatabaseJson.h"
#include "../constants.h"
#include "../Error/RessourceException.h"
#include "../Error/InitializationException.h"
#include "../Error/ValueException.h"
#include "../Battle/BattleEffects.h"
#include "../Battle/Spell.h"
#include "../Battle/Fighter.h"
#include "../Items/Item.h"
#include "../Battle/CharCourb.h"
#include "../Battle/TeamMate.h"



DatabaseJson::DatabaseJson()
{
	m_roots.resize(DatabaseJson::e_JsonDatabase::JD_TOTAL);
	m_readers.resize(DatabaseJson::e_JsonDatabase::JD_TOTAL);
	m_matching.resize(DatabaseJson::e_JsonMatching::JD_MATCH_TOTAL);

	loadDatabase(DatabaseJson::e_JsonDatabase::JD_MONSTERS, DATABASE_JSON_NAME_MONSTERS);
	loadDatabase(DatabaseJson::e_JsonDatabase::JD_SPELLS, DATABASE_JSON_NAME_SPELLS);
	loadDatabase(DatabaseJson::e_JsonDatabase::JD_EFFECTS, DATABASE_JSON_NAME_EFFECTS);
	loadDatabase(DatabaseJson::e_JsonDatabase::JD_ITEMS, DATABASE_JSON_NAME_ITEMS);
	loadDatabase(DatabaseJson::e_JsonDatabase::JD_CHARCOURB, DATABASE_JSON_NAME_CHARCOURB);
	loadDatabase(DatabaseJson::e_JsonDatabase::JD_TEAMMATE, DATABASE_JSON_NAME_TEAMMATE);

	loadMatching(m_matching.at(JD_MATCH_SPELLS_EFFECTS), DATABASE_JSON_NAME_SPELLS_EFFECTS, "id_spells", "id_effects");
	loadMatching(m_matching.at(JD_MATCH_MONSTERS_SPELLS), DATABASE_JSON_NAME_MONSTERS_SPELLS, "id_monsters", "id_spells");
	loadMatching(m_matching.at(JD_MATCH_ITEMS_EFFECTS), DATABASE_JSON_NAME_ITEMS_EFFECTS, "id_items", "id_effects");

	loadMatching(m_matchingLevelSpells, DATABASE_JSON_NAME_TEAMMATE_SPELLS, "id_team_mate", "id_spell", "level_able");
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

	if (id < 0)
		THROW_VALUE("Wrong id " + strId);

	be.setId(id);
	be.setCharacteristic(Characteristic::e_characteristics(m_roots.at(JD_EFFECTS)[id].get("type", 0).asInt()));
	be.setChance(m_roots.at(JD_EFFECTS)[id].get("chance", 0).asInt());
	be.setPower(m_roots.at(JD_EFFECTS)[id].get("quantity", 0).asInt());
	be.setTargetType(BattleEffects::e_EffectsTarget(m_roots.at(JD_EFFECTS)[id].get("target", 0).asInt()));
	be.setNumberOfPeople(m_roots.at(JD_EFFECTS)[id].get("numberOfPeople", 0).asInt());

	return be;
}


// Return the spell
Spell DatabaseJson::getSpell(int id)
{
	std::string strId(std::to_string(id));

	if (id < 0)
		THROW_VALUE("Wrong id " + strId);

	Spell sp(
		id,
		m_roots.at(JD_SPELLS)[id].get("name", "ASCII").asString(),
		m_roots.at(JD_SPELLS)[id].get("damage", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("ally_destination", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("enemi_destination", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("cost_hp", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("cost_mp", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("cost_tp", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("chance_sleep", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("chance_poison", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("chance_paralysis", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("chance_mute", 0).asInt(),
		m_roots.at(JD_SPELLS)[id].get("description", 0).asString()
	);

	return sp;
}


// Return the monster
Fighter DatabaseJson::getFighter(int id)
{
	Fighter f;
	std::string strId(std::to_string(id));

	if (id < 0)
		THROW_VALUE("Wrong id " + strId);

	f.setName(m_roots.at(JD_MONSTERS)[id].get("name", 0).asString());
	f.setHealth(Health((int)(m_roots.at(JD_MONSTERS)[id].get("health", 0).asInt())));
	f.setMana(Mana((int)(m_roots.at(JD_MONSTERS)[id].get("mana", 0).asInt())));
	f.getRealCharacteristics().at(Characteristic::e_characteristics::STRENGH) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("strengh", 0).asInt(), CHARACTERISTIC_STRENGH_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::AGILITY) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("agility", 0).asInt(), CHARACTERISTIC_AGILITY_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::INTELLIGENCE) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("intelligence", 0).asInt(), CHARACTERISTIC_INTELLIGENCE_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::VITALITY) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("vitality", 0).asInt(), CHARACTERISTIC_VITALITY_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::REGEN_MP) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("regen_mp", 0).asInt(), CHARACTERISTIC_REGEN_MP_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::ATTACK_PHYSIC) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("attack_physic", 0).asInt(), CHARACTERISTIC_ATTACK_PHYSIC_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::ATTACK_MAGIC) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("attack_magic", 0).asInt(), CHARACTERISTIC_ATTACK_MAGIC_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::DEFENSE_PHYSIC) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("defense_physic", 0).asInt(), CHARACTERISTIC_DEFENSE_PHYSIC_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::DEFENSE_MAGIC) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("defense_magic", 0).asInt(), CHARACTERISTIC_DEFENSE_MAGIC_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::RESISTANCE_SLEEP) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("resistance_sleep", 0).asInt(), CHARACTERISTIC_RESISTANCE_SLEEP_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::RESISTANCE_PARALYSIS) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("resistance_paralysis", 0).asInt(), CHARACTERISTIC_RESISTANCE_PARALYSIS_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::RESISTANCE_POISON) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("resistance_poison", 0).asInt(), CHARACTERISTIC_RESISTANCE_POISON_MAX);
	f.getRealCharacteristics().at(Characteristic::e_characteristics::RESISTANCE_MUTE) = Characteristic(m_roots.at(JD_MONSTERS)[id].get("resistance_mute", 0).asInt(), CHARACTERISTIC_RESISTANCE_MUTE_MAX);

	return f;
}


// Return the item
Item DatabaseJson::getItem(int id)
{
	Item item;

	std::string strId(std::to_string(id));

	if (id < 0)
		THROW_VALUE("Wrong id " + strId);

	item.setId(id);
	item.setName(m_roots.at(JD_ITEMS)[id].get("name", "Unknown").asString());
	item.setDescription(m_roots.at(JD_ITEMS)[id].get("description", "Unknown").asString());
	item.setPriceBuy(m_roots.at(JD_ITEMS)[id].get("price_buy", 0).asInt());
	item.setPriceSell(m_roots.at(JD_ITEMS)[id].get("price_sell", 0).asInt());
	item.setType(Item::e_ItemType(m_roots.at(JD_ITEMS)[id].get("type", 0).asInt()));

	return item;
}


// Return the courb
CharCourb DatabaseJson::getCourb(int id)
{
	CharCourb courb;

	std::string strId(std::to_string(id));

	if (id < 0)
		THROW_VALUE("Wrong id " + strId);

	courb.setId(id);
	courb.setCube(m_roots.at(JD_CHARCOURB)[id].get("cube", -1).asDouble());
	courb.setSquare(m_roots.at(JD_CHARCOURB)[id].get("square", -1).asDouble());
	courb.setSimple(m_roots.at(JD_CHARCOURB)[id].get("simple", 1).asDouble());
	courb.setBrut(m_roots.at(JD_CHARCOURB)[id].get("brut", -1).asDouble());

	return courb;
}


// Return the team mate
TeamMate DatabaseJson::getTeamMate(int id)
{
	TeamMate tm;

	std::string strId(std::to_string(id));

	if (id < 0)
		THROW_VALUE("Wrong id " + strId);

	tm.setName(m_roots.at(JD_TEAMMATE)[id].get("name", "No name").asString());
	tm.setExpCourb(getCourb(m_roots.at(JD_TEAMMATE)[id].get("exp_courb_id", 0).asInt()));
	tm.setHealthCourb(getCourb(m_roots.at(JD_TEAMMATE)[id].get("health_courb_id", 0).asInt()));
	tm.setManaCourb(getCourb(m_roots.at(JD_TEAMMATE)[id].get("mana_courb_id", 0).asInt()));
	tm.getRealCourb().at(Characteristic::e_characteristics::STRENGH) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("strengh_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::INTELLIGENCE) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("intelligence_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::VITALITY) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("vitality_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::AGILITY) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("agility_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::SPEED) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("speed_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::REGEN_MP) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("regen_mp_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::ATTACK_PHYSIC) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("attack_physic_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::ATTACK_MAGIC) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("attack_magic_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::DEFENSE_PHYSIC) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("defense_physic_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::DEFENSE_MAGIC) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("defense_magic_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::RESISTANCE_SLEEP) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("resistance_sleep_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::RESISTANCE_POISON) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("resistance_poison_courb_id", 0).asInt());
	tm.getRealCourb().at(Characteristic::e_characteristics::RESISTANCE_PARALYSIS) = getCourb(m_roots.at(JD_TEAMMATE)[id].get("resistance_paralysis_courb_id", 0).asInt());

	return tm;
};


// Return the spell with the effects
Spell DatabaseJson::getFullSpell(int id)
{
	Spell sp(getSpell(id));

	if ((unsigned)id >= m_matching.at(JD_MATCH_SPELLS_EFFECTS).size())
		return sp;

	for (unsigned int i(0); i < m_matching.at(JD_MATCH_SPELLS_EFFECTS).at(id).size(); i++)
		sp.addEffect(getBattleEffects(m_matching.at(JD_MATCH_SPELLS_EFFECTS).at(id).at(i)));

	return sp;
}


// Return the monster with the full spells
Fighter DatabaseJson::getFullFighter(int id)
{
	Fighter f(getFighter(id));

	if ((unsigned)id >= m_matching.at(JD_MATCH_MONSTERS_SPELLS).size())
		return f;

	for (unsigned int i(0); i < m_matching.at(JD_MATCH_MONSTERS_SPELLS).at(id).size(); i++)
		f.getRealSpells().push_back(getFullSpell(m_matching.at(JD_MATCH_MONSTERS_SPELLS).at(id).at(i)));

	return f;
}


// Return the item with the effects
Item DatabaseJson::getFullItem(int id)
{
	Item item(getItem(id));

	if ((unsigned)id >= m_matching.at(JD_MATCH_ITEMS_EFFECTS).size())
		return item;

	for (unsigned int i(0); i < m_matching.at(JD_MATCH_ITEMS_EFFECTS).at(id).size(); i++)
		item.getRealEffects().push_back(getBattleEffects(m_matching.at(JD_MATCH_ITEMS_EFFECTS).at(id).at(i)));

	return item;
}


// Return the team mate with the spells
TeamMate DatabaseJson::getFullTeamMate(int id)
{
	TeamMate tm(getTeamMate(id));

	if ((unsigned)id >= m_matchingLevelSpells.size())
		return tm;

	for (unsigned int i(0); i < m_matchingLevelSpells.at(id).size(); i++)
	{
		std::pair<int, Spell> p;
		p.first = m_matchingLevelSpells.at(id).at(i).second;
		p.second = getFullSpell(m_matchingLevelSpells.at(id).at(i).first);
		tm.getRealBasicSpells().push_back(p);
	}

	return tm;
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


int DatabaseJson::loadMatching(std::vector< std::vector<int> > &v, const std::string &filename, const std::string &key1, const std::string &key2)
{
	Json::Value root;
	Json::Reader reader;
	std::ifstream file(filename);
	if (!file.is_open())
		THROW_RESSOURCE("JDB", filename);

	if (!reader.parse(file, root, false))
		THROW_INIT("Couldn't parse JDB");

	for (Json::ValueConstIterator it = root.begin(); it != root.end(); ++it)
	{
		const Json::Value& val = *it;
		
		if ((unsigned)val.get(key1, 0).asInt() > v.size())
			v.resize(val.get(key1, 0).asInt() + 1);
			
		v.at(val.get(key1, 0).asInt()).push_back(val.get(key2, 0).asInt());
	}

	return 0;
}


int DatabaseJson::loadMatching(std::vector< std::vector< std::pair<int, int> > > &v, const std::string &filename, const std::string &key1, const std::string &key2, const std::string &key3)
{
	Json::Value root;
	Json::Reader reader;
	std::ifstream file(filename);
	if (!file.is_open())
		THROW_RESSOURCE("JDB", filename);

	if (!reader.parse(file, root, false))
		THROW_INIT("Couldn't parse JDB");

	for (Json::ValueConstIterator it = root.begin(); it != root.end(); ++it)
	{
		const Json::Value& val = *it;

		if ((unsigned)val.get(key1, 0).asInt() > v.size())
			v.resize(val.get(key1, 0).asInt() + 1);

		std::pair<int, int> m = std::make_pair(val.get(key2, 0).asInt(), val.get(key3, 0).asInt());

		v.at(val.get(key1, 0).asInt()).push_back(m);
	}

	return 0;
}