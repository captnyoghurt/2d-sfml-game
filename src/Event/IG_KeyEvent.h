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
 *  Can trigger an IG_Action.
 *
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "IG_Action.h"

// Break cyclic inclusions
class Game;

class IG_KeyEvent {
 public:
  IG_KeyEvent();
  ~IG_KeyEvent();

 public:
  /**
   * \brief Return the key of this in game key event	.
   *
   * \return sf::Keyboard::Key object.
   */
  sf::Keyboard::Key getKey() const;
  /**
   * \brief Return the action done by this in game key event	.
   *
   * \return IG_Action object.
   */
  IG_Action getIGAction() const;

  /**
   * \brief Modify the key of this in game key event	.
   *
   * \param k The new value.
   * \return int object.
   */
  int setKey(sf::Keyboard::Key k);
  /**
   * \brief Modify the action done by this in game key event	.
   *
   * \param act The new value.
   * \return int object.
   */
  int setIGAction(IG_Action act);

  /**
   * \brief Call the function this event is supposed to do	.
   *
   * \return int object.
   */
  int doAction(Game &game);

 private:
  sf::Keyboard::Key m_key;
  IG_Action m_action;
};