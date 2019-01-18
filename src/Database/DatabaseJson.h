#pragma once

#include <vector>
#include "../third_party/jsoncpp/dist/json/json.h"

class BattleEffects;
class Spell;
class Fighter;
class Item;
class CharCourb;
class TeamMate;

class DatabaseJson {
 public:
  enum e_JsonDatabase {
    JD_MONSTERS,
    JD_SPELLS,
    JD_EFFECTS,
    JD_ITEMS,
    JD_CHARCOURB,
    JD_TEAMMATE,
    JD_TOTAL
  };
  enum e_JsonMatching {
    JD_MATCH_MONSTERS_SPELLS,
    JD_MATCH_SPELLS_EFFECTS,
    JD_MATCH_ITEMS_EFFECTS,
    JD_MATCH_TOTAL
  };

 public:
  DatabaseJson();
  ~DatabaseJson();

 public:
  // Return the roots with modifying possibilities
  std::vector<Json::Value> &getRealRoots();
  // Return the readers with modifying possibilities
  std::vector<Json::Reader> &getRealReaders();

  // Return the battle effect
  BattleEffects getBattleEffects(int id);
  // Return the spell
  Spell getSpell(int id);
  // Return the monster
  Fighter getFighter(int id);
  // Return the item
  Item getItem(int id);
  // Return the courb
  CharCourb getCourb(int id);
  // Return the team mate
  TeamMate getTeamMate(int id);

  // Return the spell with the effects
  Spell getFullSpell(int id);
  // Return the monster with the full spells
  Fighter getFullFighter(int id);
  // Return the item with the effects
  Item getFullItem(int id);
  // Return the team mate with the spells
  TeamMate getFullTeamMate(int id);

 protected:
  int loadDatabase(int i, const std::string &filename);
  int loadMatching(std::vector<std::vector<int> > &v,
                   const std::string &filename, const std::string &key1,
                   const std::string &key2);
  int loadMatching(std::vector<std::vector<std::pair<int, int> > > &v,
                   const std::string &filename, const std::string &key1,
                   const std::string &key2, const std::string &key3);

 private:
  std::vector<Json::Value> m_roots;
  std::vector<Json::Reader> m_readers;
  std::vector<std::vector<std::vector<int> > > m_matching;
  std::vector<std::vector<std::pair<int, int> > > m_matchingLevelSpells;
};
