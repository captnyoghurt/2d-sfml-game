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
 *  Manage all the animation to display.
 *
 */

#pragma once

#include "Animation.h"

class Game;

class ManageAnimation {
 public:
  ManageAnimation();
  ~ManageAnimation();

 public:
  /**
   * \brief Return all the curretn animations	.
   *
   * \return std::list<Animation> object.
   */
  std::list<Animation> getAnimations() const;

  /**
   * \brief Return all the curretn animations with modification possibilities
   * .
   *
   * \return std::list<Animation>& object.
   */
  std::list<Animation>& getRealAnimations();

  /**
   * \brief Add an animation	.
   *
   * \return std::list<Animation>::iterator object.
   */
  std::list<Animation>::iterator addAnimation(Animation a);

  /**
   * \brief Update all the animations	.
   *
   * \return int object.
   */
  int update(Game& g);

 private:
  std::list<Animation> m_animations;
  sf::Clock m_clock;
};
