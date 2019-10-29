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

#include "BattleEventManager.h"
#include <iostream>
#include <memory>
#include "../Error/InitializationException.h"
#include "../Error/ValueException.h"
#include "../Event/actionFunctions.h"
#include "../Game.h"
#include "../Menu/MenuBattle.h"
#include "../Menu/MenuDialogBox.h"
#include "../constants.h"

BattleEventManager::BattleEventManager() : m_eventInConstruction(nullptr) {
  m_waiting = false;
  m_executeStarted = false;
}

BattleEventManager::~BattleEventManager() {}

// Return the list of battle events
std::list<std::shared_ptr<B_Event>> BattleEventManager::getBattleEvents()
    const {
  return m_battleEvents;
}

// Return if the battle event manager is waiting
bool BattleEventManager::getWaiting() const { return m_waiting; }

// Return if the execute has started
bool BattleEventManager::getExecuteStarted() const { return m_executeStarted; }

// Return the list of battle events with modifying possibilities
std::list<std::shared_ptr<B_Event>> &BattleEventManager::getRealBattleEvents() {
  return m_battleEvents;
}

// Modify if the battle event manager is waiting
int BattleEventManager::setWaiting(const bool &b) {
  m_waiting = b;

  return 0;
}

// Modify if the execute has started
int BattleEventManager::setExecuteStarted(const bool &b) {
  m_executeStarted = b;

  return 0;
}

// Add an event to the top of the list
int BattleEventManager::addToFront(std::shared_ptr<B_Event> b) {
  m_battleEvents.push_front(b);

  return 0;
}

// Create an event
int BattleEventManager::createEvent(std::shared_ptr<Fighter> source,
                                    std::shared_ptr<B_Event> type, Game &g) {
  if (m_eventInConstruction) THROW_INIT("BattleEvent already in construction");

  m_eventInConstruction = type;

  type->getRealSource() = source;

  askDestination(g);

  return 0;
}

// Add a destination for the event in construction
int BattleEventManager::addDestinationForEvent(std::shared_ptr<Fighter> f,
                                               Game &g) {
  if (!m_eventInConstruction) THROW_INIT("No in construction");

  if (!m_eventInConstruction->isAllyDestinationFull())
    m_eventInConstruction->getRealAllyDestination().push_back(f);
  else if (!m_eventInConstruction->isEnemyDestinationFull())
    m_eventInConstruction->getRealEnemyDestination().push_back(f);
  else
    THROW_VALUE("Too much destination ofr BattleEvent");

  askDestination(g);

  return 0;
}

// Return if the manager is creating an event
bool BattleEventManager::isCreating() const {
  return !(!m_eventInConstruction);
}

// Clear the entire list
int BattleEventManager::clear() {
  m_battleEvents.clear();
  m_eventInConstruction = nullptr;
  m_executeStarted = false;

  return 0;
}

// Execute the header event
int BattleEventManager::execute(Game &g) {
  // [TODO]
  if (m_battleEvents.empty()) THROW_VALUE("Empty queue for BattleEvent");

  if (m_waiting) return 0;

  if (m_executeStarted)
    m_battleEvents.pop_front();
  else
    m_executeStarted = true;

  if (m_battleEvents.empty()) return 0;

  std::shared_ptr<B_Event> it = m_battleEvents.front();

  g.getRealBattle().getRealBattleMenu().setActiveMenu(MenuBattle::BM_DIALOG);
  std::dynamic_pointer_cast<MenuDialogBox>(
      g.getRealBattle().getRealBattleMenu().getRealMenus().at(
          MenuBattle::BM_DIALOG))
      ->addText(it->getDescription());
  std::dynamic_pointer_cast<MenuDialogBox>(
      g.getRealBattle().getRealBattleMenu().getRealMenus().at(
          MenuBattle::BM_DIALOG))
      ->continueText(
          g.getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_MENU),
          g.getRealSurfaceManager(LAYER_MENU));

  g.getRealBattle().getRealBattleMenu().setIsBlocking(true);

  return it->execute(&g.getRealBattle(), g.getRealSoundManager());
}

// Tell the battle menu to ask a destination
int BattleEventManager::askDestination(Game &g) {
  if (!isCreating()) THROW_INIT("Not creating a BattleEvent");

  if (m_eventInConstruction->getRealSource()->isTeamMate()) {
    g.getRealBattle().getRealBattleMenu().setIsBlocking(true);
    if (!m_eventInConstruction->isAllyDestinationFull())
      af_menuBattleUseRight(g);
    else if (!m_eventInConstruction->isEnemyDestinationFull())
      af_menuBattleUseLeft(g);
    else {
      m_battleEvents.push_back(m_eventInConstruction);
      m_eventInConstruction = nullptr;
      g.getRealBattle().getRealBattleMenu().setIsBlocking(false);

      return 1;
    }
  } else {
    addDestinationForEvent(
        g.getRealBattle().getRealAllies().getRealTeam().at(0), g);
    return 1;
  }

  return 0;
}