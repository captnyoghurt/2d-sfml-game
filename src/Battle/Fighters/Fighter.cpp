/**
 *  @file
 *  @author  Paul Coignet
 *  @date    11 / 11 / 2017
 *  @version 0.1
 *
 *  @brief Class header.
 *
 *  @section DESCRIPTION
 *
 *  Mother class for enemi or ally.
 *
 */

#include "Fighter.h"
#include "../../Error/ValueException.h"
#include "../../Game.h"
#include "../../constants.h"
#include "../B_Event/B_Event.h"
#include "../B_Event/B_EventAttack.h"
#include "../B_Event/B_EventDefense.h"
#include "../B_Event/B_EventEscape.h"
#include "../B_Event/B_EventSpell.h"
#include "../Battle.h"

Fighter::Fighter()
    : m_health(0), m_mana(0), m_skillPoints(0), m_name("Unknown") {
  m_characteristics.resize(
      Characteristic::e_characteristics::CHARACTERISTICS_TOTAL,
      Characteristic(0, 0));
  m_characteristics.at(0).setMaxPoints(CHARACTERISTIC_STRENGH_MAX);
  m_characteristics.at(1).setMaxPoints(CHARACTERISTIC_INTELLIGENCE_MAX);
  m_characteristics.at(2).setMaxPoints(CHARACTERISTIC_VITALITY_MAX);
  m_characteristics.at(3).setMaxPoints(CHARACTERISTIC_AGILITY_MAX);
  m_characteristics.at(4).setMaxPoints(CHARACTERISTIC_SPEED_MAX);
  m_characteristics.at(5).setMaxPoints(CHARACTERISTIC_REGEN_MP_MAX);
  m_characteristics.at(6).setMaxPoints(CHARACTERISTIC_ATTACK_PHYSIC_MAX);
  m_characteristics.at(7).setMaxPoints(CHARACTERISTIC_ATTACK_MAGIC_MAX);
  m_characteristics.at(8).setMaxPoints(CHARACTERISTIC_DEFENSE_PHYSIC_MAX);
  m_characteristics.at(9).setMaxPoints(CHARACTERISTIC_DEFENSE_MAGIC_MAX);
  m_characteristics.at(10).setMaxPoints(CHARACTERISTIC_RESISTANCE_SLEEP_MAX);
  m_characteristics.at(11).setMaxPoints(CHARACTERISTIC_RESISTANCE_POISON_MAX);
  m_characteristics.at(12).setMaxPoints(
      CHARACTERISTIC_RESISTANCE_PARALYSIS_MAX);
  m_characteristics.at(13).setMaxPoints(CHARACTERISTIC_RESISTANCE_MUTE_MAX);
}

Fighter::Fighter(const Fighter &f)
    : m_characteristics(f.getCharacteristics()),
      m_name(f.getName()),
      m_health(f.getHealth()),
      m_mana(f.getMana()),
      m_skillPoints(f.getSkillPoints()),
      m_spells(f.getSpells()) {
  m_characteristics.resize(
      Characteristic::e_characteristics::CHARACTERISTICS_TOTAL,
      Characteristic(0, 0));
}

Fighter::~Fighter() {}

Fighter &Fighter::operator=(const Fighter &f) {
  m_name = f.getName();
  m_characteristics = f.getCharacteristics();
  m_health = f.getHealth();
  m_mana = f.getMana();
  m_skillPoints = f.getSkillPoints();
  m_spells = f.getSpells();
  m_characteristics.resize(
      Characteristic::e_characteristics::CHARACTERISTICS_TOTAL,
      Characteristic(0, 0));

  return *this;
}

// Return the name
std::string Fighter::getName() const { return m_name; }

// Return health
Health Fighter::getHealth() const { return m_health; }

// Return mana
Mana Fighter::getMana() const { return m_mana; }

// Return skill points
SkillPoints Fighter::getSkillPoints() const { return m_skillPoints; }

// Return all the characteristics
std::vector<Characteristic> Fighter::getCharacteristics() const {
  return m_characteristics;
}

// Return all the spells
std::vector<Spell> Fighter::getSpells() const { return m_spells; }

// Return the surface
std::list<
    std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
Fighter::getSurface() {
  return m_surface;
}

// Return health with modifying possibilities
Health &Fighter::getRealHealth() { return m_health; }

// Return mana with modifying possibilities
Mana &Fighter::getRealMana() { return m_mana; }

// Return skill points with modifying possibilities
SkillPoints &Fighter::getRealSkillPoints() { return m_skillPoints; }

// Return all the characteristics with modifying possibilities
std::vector<Characteristic> &Fighter::getRealCharacteristics() {
  return m_characteristics;
}

// Return the spells with modifying possibilities
std::vector<Spell> &Fighter::getRealSpells() { return m_spells; }

// Return the surface with modifying possibilities
std::list<
    std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator &
Fighter::getRealSurface() {
  return m_surface;
}

// Modify the name
int Fighter::setName(const std::string &name) {
  m_name = name;

  return 0;
}

// Modify health
int Fighter::setHealth(const Health &h) {
  m_health.setMaxPoints(h.getMaxPoints());
  m_health.setPoints(h.getPoints());

  return 0;
}

// Modify mana
int Fighter::setMana(const Mana &m) {
  m_mana.setMaxPoints(m.getMaxPoints());
  m_mana.setPoints(m.getPoints());

  return 0;
}

// Modify skill points
int Fighter::setSkillPoints(const SkillPoints &skp) {
  m_skillPoints.setMaxPoints(skp.getMaxPoints());
  m_skillPoints.setPoints(skp.getPoints());

  return 0;
}

// Modify a characteristic
int Fighter::setCharacteristic(const Characteristic &ch, int n) {
  if (n < 0 || (unsigned)n >= m_characteristics.size()) return -1;

  m_characteristics.at(n).setMaxPoints(ch.getMaxPoints());
  m_characteristics.at(n).setPoints(ch.getPoints());

  return 0;
}

// Modify the surface
int Fighter::setSurface(
    std::list<std::pair<ManageSurfaces::e_thing,
                        std::shared_ptr<Surface>>>::iterator it) {
  m_surface = it;

  return 0;
}

// Take a decision for the next battle action
std::shared_ptr<B_Event> Fighter::chooseEvent(Game *g) {
  THROW_VALUE("Simple B_Event");

  return std::make_shared<B_Event>(B_Event());
}

// Make the fighter do an action for the next turn
int Fighter::doAction(std::shared_ptr<B_Event> evt) {
  // [TODO]
  // Add the event to the battle historic

  return 0;
}

// True if the fighter is in reality a TeamMate
bool Fighter::isTeamMate() const { return false; }

// True if the fighter is dead (== 0 HP)
bool Fighter::isDead() const { return (m_health.getPoints() <= 0); }

// Change stance & possibilities
int Fighter::switchToDead() {
  m_surface->second->setEnable(false);

  return 0;
}
int Fighter::switchToAlive() {
  m_surface->second->setEnable(true);

  return 0;
}