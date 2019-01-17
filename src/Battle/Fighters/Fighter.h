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

#pragma once

#include <vector>
#include "../../Map/ManageSurfaces.h"
#include "../Status/Characteristic.h"
#include "../Status/Health.h"
#include "../Status/Mana.h"
#include "../Status/SkillPoints.h"
#include "../Status/Spell.h"

class Battle;
class Game;
class B_Event;

class Fighter {
 public:
  Fighter();
  Fighter(const Fighter &f);
  ~Fighter();

  Fighter &operator=(const Fighter &f);

 public:
  /**
   * \brief Return the name	.
   *
   * \return std::string object.
   */
  std::string getName() const;
  /**
   * \brief Return health	.
   *
   * \return Health object.
   */
  Health getHealth() const;
  /**
   * \brief Return mana	.
   *
   * \return Mana object.
   */
  Mana getMana() const;
  /**
   * \brief Return skill points	.
   *
   * \return SkillPoints object.
   */
  SkillPoints getSkillPoints() const;
  /**
   * \brief Return all the characteristics	.
   *
   * \return std::vector<Characteristic> object.
   */
  std::vector<Characteristic> getCharacteristics() const;
  /**
   * \brief Return all the spells	.
   *
   * \return std::vector<Spell> object.
   */
  std::vector<Spell> getSpells() const;
  /**
   * \brief Return the surface	.
   *
   * \return std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
  getSurface();

  /**
   * \brief Return health with modifying possibilities	.
   *
   * \return Health& object.
   */
  Health &getRealHealth();
  /**
   * \brief Return mana with modifying possibilities	.
   *
   * \return Mana& object.
   */
  Mana &getRealMana();
  /**
   * \brief Return skill points with modifying possibilities	.
   *
   * \return SkillPoints& object.
   */
  SkillPoints &getRealSkillPoints();
  /**
   * \brief Return all the characteristics with modifying possibilities	.
   *
   * \return std::vector<Characteristic>& object.
   */
  std::vector<Characteristic> &getRealCharacteristics();
  /**
   * \brief Return the spells with modifying possibilities	.
   *
   * \return std::vector<Spell>& object.
   */
  std::vector<Spell> &getRealSpells();
  /**
   * \brief Return the surface with modifying possibilities	.
   *
   * \return std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator &
  getRealSurface();

  /**
   * \brief Modify the name	.
   *
   * \param name The new value.
   * \return int object.
   */
  int setName(const std::string &name);
  /**
   * \brief Modify health	.
   *
   * \param h The new value.
   * \return int object.
   */
  int setHealth(const Health &h);
  /**
   * \brief Modify mana	.
   *
   * \param m The new value.
   * \return int object.
   */
  int setMana(const Mana &m);
  /**
   * \brief Modify skill points	.
   *
   * \param skp The new value.
   * \return int object.
   */
  int setSkillPoints(const SkillPoints &skp);
  /**
   * \brief Modify a characteristic	.
   *
   * \param n The new value.
   * \return int object.
   */
  int setCharacteristic(const Characteristic &ch, int n);
  /**
   * \brief Modify the surface	.
   *
   * \param it The new value.
   * \return int object.
   */
  int setSurface(std::list<std::pair<ManageSurfaces::e_thing,
                                     std::shared_ptr<Surface>>>::iterator it);

  /**
   * \brief Take a decision for the next battle action	.
   *
   * \return virtual object.
   */
  virtual std::shared_ptr<B_Event> chooseEvent(Game *g);
  /**
   * \brief Make the fighter do an action for the next turn	.
   *
   * \return int object.
   */
  int doAction(std::shared_ptr<B_Event> evt);
  /**
   * \brief True if the fighter is in reality a TeamMate	.
   *
   * \return virtual object.
   */
  virtual bool isTeamMate() const;
  /**
   * \brief True if the fighter is dead (== 0 HP)	.
   *
   * \return bool object.
   */
  bool isDead() const;
  /**
   * \brief Change stance & possibilities	.
   *
   * \return int object.
   */
  int switchToDead();
  int switchToAlive();

 protected:
  std::string m_name;
  Health m_health;
  Mana m_mana;
  SkillPoints m_skillPoints;
  std::vector<Characteristic> m_characteristics;
  std::vector<Spell> m_spells;
  std::list<std::pair<ManageSurfaces::e_thing,
                      std::shared_ptr<Surface>>>::iterator m_surface;
};
