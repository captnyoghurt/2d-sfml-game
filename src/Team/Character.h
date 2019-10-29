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
 *  A character of the team.
 *
 */

#pragma once

#include <list>
#include <memory>
#include "../Map/ManageSurfaces.h"
#include "../Map/Surface.h"

class Game;

class Character {
 public:
  Character();
  ~Character();

 public:
  /**
   * \brief Return the abciss of the Character	.
   *
   * \return unsigned object.
   */
  unsigned short getCombatX() const;
  /**
   * \brief Return the y position of the Character	.
   *
   * \return unsigned object.
   */
  unsigned short getCombatY() const;
  /**
   * \brief Return the width of the Character	.
   *
   * \return short object.
   */
  short getCombatWidth() const;
  /**
   * \brief Return the height of the Character	.
   *
   * \return short object.
   */
  short getCombatHeight() const;
  /**
   * \brief Return the iterator of the combat stand surface of the character
   * .
   *
   * \return std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
  getCombatStand();

  /**
   * \brief Return the iterator of the combat stand surface of the character
   * with modifying possibilities	.
   *
   * \return std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator &
  getRealCombatStand();

  /**
   * \brief Modify the abciss of the Character	.
   *
   * \param x The new value.
   * \return int object.
   */
  int setCombatX(const unsigned short &x);
  /**
   * \brief Modify the y position of the Character	.
   *
   * \param y The new value.
   * \return int object.
   */
  int setCombatY(const unsigned short &y);
  /**
   * \brief Modify the width of the Character	.
   *
   * \param w The new value.
   * \return int object.
   */
  int setCombatWidth(const short &w);
  /**
   * \brief Modify the height of the Character	.
   *
   * \param h The new value.
   * \return int object.
   */
  int setCombatHeight(const short &h);

  /**
   * \brief Load the surface of the combat stand	.
   *
   * \return int object.
   */
  int loadComnatStand(sf::Texture &t, Game &g);

 public:
  std::list<std::pair<ManageSurfaces::e_thing,
                      std::shared_ptr<Surface>>>::iterator m_combatStand;
  unsigned short m_combatX;
  unsigned short m_combatY;
  short m_combatW;
  short m_combatH;
};
