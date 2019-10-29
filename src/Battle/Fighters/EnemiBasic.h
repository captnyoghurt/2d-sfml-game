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
 *  A simple enemi to fight.
 *
 */

#pragma once

#include <random>
#include "Fighter.h"

class Game;

class EnemiBasic : public Fighter {
 public:
  EnemiBasic();
  EnemiBasic(const Fighter &f);
  ~EnemiBasic();

 public:
  /**
   * \brief Take a decision for the next battle action	.
   *
   * \return virtual object.
   */
  virtual std::shared_ptr<B_Event> chooseEvent(Game *g);

 private:
  std::default_random_engine m_generator;
};
