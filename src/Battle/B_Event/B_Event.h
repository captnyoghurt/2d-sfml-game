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
 *  Mother class for the different battle event.
 *
 */

#pragma once

#include <SFML/Audio.hpp>
#include <deque>
#include <memory>
#include <string>
#include "../../Sound/ManageSound.h"
#include "../Fighters/Fighter.h"

class Battle;

class B_Event {
 public:
  B_Event();
  ~B_Event();

 public:
  /**
   * \brief Return the description of the event in the fight	.
   *
   * \return std::string object.
   */
  std::string getDescription() const;
  /**
   * \brief Return the number of destination for "ally" team	.
   *
   * \return int object.
   */
  int getNumberAllyDestination() const;
  /**
   * \brief Return the number of destination for "enemy" team	.
   *
   * \return int object.
   */
  int getNumberEnemyDestination() const;

  /**
   * \brief Modify the description of the event in the fight	.
   *
   * \param description The new value.
   * \return int object.
   */
  int setDescription(const std::string& description);
  /**
   * \brief Modify the number of destination for "ally" team	.
   *
   * \param n The new value.
   * \return int object.
   */
  int setNumberAllyDestination(const int& n);
  /**
   * \brief Modify the number of destination for "enemy" team	.
   *
   * \param n The new value.
   * \return int object.
   */
  int setNumberEnemyDestination(const int& n);

  /**
   * \brief Return the ally destination with modifying possibilities	.
   *
   * \return std::deque< object.
   */
  std::deque<std::shared_ptr<Fighter> >& getRealAllyDestination();
  /**
   * \brief Return the enemy destination with modifying possibilities	.
   *
   * \return std::deque< object.
   */
  std::deque<std::shared_ptr<Fighter> >& getRealEnemyDestination();
  /**
   * \brief Return the source of the event with modifying possibilities	.
   *
   * \return std::shared_ptr<Fighter>& object.
   */
  std::shared_ptr<Fighter>& getRealSource();
  /**
   * \brief Return the sound buffer with modifying possitilities	.
   *
   * \return std::shared_ptr<sf::SoundBuffer>& object.
   */
  std::shared_ptr<sf::SoundBuffer>& getRealSound();

  /**
   * \brief Return if the deque for ally is full	.
   *
   * \return bool object.
   */
  bool isAllyDestinationFull() const;
  /**
   * \brief Return if the deque for enemy is full	.
   *
   * \return bool object.
   */
  bool isEnemyDestinationFull() const;

  /**
   * \brief Do the event	.
   *
   * \return virtual object.
   */
  virtual int execute(Battle* bat, ManageSound& snd);

 protected:
  std::string m_description;
  int m_numberAllyDestination;
  int m_numberEnemyDestination;
  std::deque<std::shared_ptr<Fighter> > m_allyDestination;
  std::deque<std::shared_ptr<Fighter> > m_enemyDestination;
  std::shared_ptr<Fighter> m_source;
  std::shared_ptr<sf::SoundBuffer> m_sound;
};
