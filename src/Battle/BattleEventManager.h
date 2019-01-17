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
 *  Execute the different event of a fight.
 *
 */

#pragma once

#include <list>
#include <memory>
#include "B_Event/B_Event.h"

class Battle;
class Game;

class BattleEventManager {
 public:
  BattleEventManager();
  ~BattleEventManager();

 public:
  /**
   * \brief Return the list of battle events	.
   *
   * \return std::list<std::shared_ptr<B_Event>> object.
   */
  std::list<std::shared_ptr<B_Event>> getBattleEvents() const;
  /**
   * \brief Return if the battle event manager is waiting	.
   *
   * \return bool object.
   */
  bool getWaiting() const;
  /**
   * \brief Return if the execute has started	.
   *
   * \return bool object.
   */
  bool getExecuteStarted() const;

  /**
   * \brief Return the list of battle events with modifying possibilities
   * .
   *
   * \return std::list<std::shared_ptr<B_Event>>& object.
   */
  std::list<std::shared_ptr<B_Event>> &getRealBattleEvents();

  /**
   * \brief Modify if the battle event manager is waiting	.
   *
   * \param b The new value.
   * \return int object.
   */
  int setWaiting(const bool &b);
  /**
   * \brief Modify if the execute has started	.
   *
   * \param b The new value.
   * \return int object.
   */
  int setExecuteStarted(const bool &b);

  /**
   * \brief Add an event to the top of the list	.
   *
   * \return int object.
   */
  int addToFront(std::shared_ptr<B_Event> b);
  /**
   * \brief Create an event	.
   *
   * \return int object.
   */
  int createEvent(std::shared_ptr<Fighter> source,
                  std::shared_ptr<B_Event> type, Game &g);
  /**
   * \brief Add a destination for the event in construction	.
   *
   * \return int object.
   */
  int addDestinationForEvent(std::shared_ptr<Fighter> f, Game &g);

  /**
   * \brief Return if the manager is creating an event	.
   *
   * \return bool object.
   */
  bool isCreating() const;
  /**
   * \brief Clear the entire list	.
   *
   * \return int object.
   */
  int clear();

  /**
   * \brief Execute the header event	.
   *
   * \return int object.
   */
  int execute(Game &g);

 protected:
  /**
   * \brief Tell the battle menu to ask a destination	.
   *
   * \return int object.
   */
  int askDestination(Game &g);

 private:
  bool m_waiting;
  bool m_executeStarted;
  std::list<std::shared_ptr<B_Event>> m_battleEvents;
  std::shared_ptr<B_Event> m_eventInConstruction;
};
