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
 *  Menu of the battle.
 *
 */

#include "MenuBattle.h"
#include <memory>
#include "../Error/InitializationException.h"
#include "../Error/ValueException.h"
#include "../Game.h"
#include "../constants.h"
#include "MenuBattleSide.h"
#include "MenuDialogBox.h"

MenuBattle::MenuBattle(Battle *b, ManageRessources &ress, ManageSurfaces &surf,
                       int lastEventLayer) {
  m_updated = true;
  m_isBlocking = false;
  m_activeMenu = 0;

  // Create sub menus
  m_menus.resize(BM_TOTAL);
  m_menus.at(BM_LEFT) = std::make_shared<MenuBattleSide>(
      ress, surf, lastEventLayer,
      MenuBattleSide::e_menuBattleSideBarType::MENU_BATTLE_ENEMIE);
  m_menus.at(BM_RIGHT) = std::make_shared<MenuBattleSide>(
      ress, surf, lastEventLayer,
      MenuBattleSide::e_menuBattleSideBarType::MENU_BATTLE_ALLIE);
  m_menus.at(BM_DIALOG) =
      std::make_shared<MenuDialogBox>(ress, surf, lastEventLayer);
  m_menus.at(BM_CHOICE) =
      std::make_shared<MenuChoice>(ress, surf, lastEventLayer);

  load(b, ress, surf);
}

MenuBattle::~MenuBattle() {}

// Return if the MenuBattle is updated
bool MenuBattle::getUpdated() const { return m_updated; }

// Return if this menu is currently waiting for an action
bool MenuBattle::getIsBlocking() const { return m_isBlocking; }

// Return the current active menu
int MenuBattle::getActiveMenu() const { return m_activeMenu; }

// Return the menus with modifying possibilities
std::vector<std::shared_ptr<Menu>> &MenuBattle::getRealMenus() {
  return m_menus;
}

// Modify the current menu
int MenuBattle::setActiveMenu(const int &am) {
  if (!((unsigned)am < MenuBattle::BM_TOTAL)) THROW_VALUE(std::to_string(am));

  m_activeMenu = am;

  m_menus.at(MenuBattle::BM_CHOICE)->setShown(am == MenuBattle::BM_CHOICE);
  m_menus.at(MenuBattle::BM_LEFT)->setShown(am == MenuBattle::BM_LEFT);
  m_menus.at(MenuBattle::BM_RIGHT)->setShown(am == MenuBattle::BM_RIGHT);

  gotUpdated();

  return 0;
}

// Modify if this menu is currently waiting for an action
int MenuBattle::setIsBlocking(const bool &b) {
  m_isBlocking = b;

  return 0;
}

// Tell the MenuBattle that it's updated
int MenuBattle::gotUpdated() {
  m_updated = true;

  return 0;
}

// All the action functions for the menus
int MenuBattle::af_MenuBattleDown(Game &g) {
  if ((m_activeMenu != MenuBattle::BM_LEFT &&
       m_activeMenu != MenuBattle::BM_RIGHT) ||
      !m_isBlocking)
    return 1;

  if ((unsigned)std::dynamic_pointer_cast<MenuBattleSide>(
          m_menus.at(m_activeMenu))
          ->getSelectedChoice() <=
      std::dynamic_pointer_cast<MenuBattleSide>(m_menus.at(m_activeMenu))
              ->getChoices()
              .size() -
          1) {
    std::dynamic_pointer_cast<MenuBattleSide>(m_menus.at(m_activeMenu))
        ->setSelectedChoice(
            std::dynamic_pointer_cast<MenuBattleSide>(m_menus.at(m_activeMenu))
                ->getSelectedChoice() +
            1);

    gotUpdated();
    g.getRealSoundManager().addSound(
        g.getRealRessourceManager()
            .at(Game::e_ressourcesLayer::RESSOURCES_MENU)
            .getTheSoundBuffer(0));
  }

  return 0;
}

int MenuBattle::af_MenuBattleUp(Game &g) {
  if ((m_activeMenu != MenuBattle::BM_LEFT &&
       m_activeMenu != MenuBattle::BM_RIGHT) ||
      !m_isBlocking)
    return 1;

  if (std::dynamic_pointer_cast<MenuBattleSide>(m_menus.at(m_activeMenu))
          ->getSelectedChoice() > 0) {
    std::dynamic_pointer_cast<MenuBattleSide>(m_menus.at(m_activeMenu))
        ->setSelectedChoice(
            std::dynamic_pointer_cast<MenuBattleSide>(m_menus.at(m_activeMenu))
                ->getSelectedChoice() -
            1);

    gotUpdated();
    g.getRealSoundManager().addSound(
        g.getRealRessourceManager()
            .at(Game::e_ressourcesLayer::RESSOURCES_MENU)
            .getTheSoundBuffer(0));
  }

  return 0;
}

int MenuBattle::af_MenuBattleRight(Game &g) {
  if (!m_isBlocking || m_activeMenu != MenuBattle::BM_CHOICE) return -1;

  if ((unsigned)std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
          ->getSelectedChoice() <
      std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
          ->getChoices()
          .size()) {
    std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
        ->setSelectedChoice(
            std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
                ->getSelectedChoice() +
            1);
    std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
        ->resizeChoiceSurface();
    g.getRealSoundManager().addSound(
        g.getRealRessourceManager()
            .at(Game::e_ressourcesLayer::RESSOURCES_MENU)
            .getTheSoundBuffer(0));
  }

  return 0;
}

int MenuBattle::af_MenuBattleLeft(Game &g) {
  if (!m_isBlocking || m_activeMenu != MenuBattle::BM_CHOICE) return 1;

  if (std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
          ->getSelectedChoice() > 0) {
    std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
        ->setSelectedChoice(
            std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
                ->getSelectedChoice() -
            1);
    std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
        ->resizeChoiceSurface();
    g.getRealSoundManager().addSound(
        g.getRealRessourceManager()
            .at(Game::e_ressourcesLayer::RESSOURCES_MENU)
            .getTheSoundBuffer(0));
  }

  return 0;
}

int MenuBattle::af_MenuBattleEnter(Game &g) {
  int ret(0);

  if (!m_isBlocking) return 1;

  m_isBlocking = false;
  m_updated = true;

  g.getRealSoundManager().addSound(
      g.getRealRessourceManager()
          .at(Game::e_ressourcesLayer::RESSOURCES_MENU)
          .getTheSoundBuffer(1));

  if (m_activeMenu == MenuBattle::BM_LEFT ||
      m_activeMenu == MenuBattle::BM_RIGHT) {
    ret = std::dynamic_pointer_cast<MenuBattleSide>(m_menus.at(m_activeMenu))
              ->getChoices()
              .at(std::dynamic_pointer_cast<MenuBattleSide>(
                      m_menus.at(m_activeMenu))
                      ->getSelectedChoice())
              ->getAction()
              .getAction()(g);
  } else if (m_activeMenu == MenuBattle::BM_DIALOG) {
    ret = std::dynamic_pointer_cast<MenuDialogBox>(m_menus.at(m_activeMenu))
              ->continueText(
                  g.getRealRessourceManager(RESSOURCE_TEXTURE_NUMBER_MENU),
                  g.getRealSurfaceManager(LAYER_MENU));

    if (ret == 0) {
      m_isBlocking = true;
    }
    /*else
            setActiveMenu(MenuBattle::BM_CHOICE);*/
  } else {
    ret =
        std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
            ->getChoices()
            .at(std::dynamic_pointer_cast<MenuChoice>(m_menus.at(m_activeMenu))
                    ->getSelectedChoice())
            ->getAction()
            .getAction()(g);
    if (ret != 1) m_isBlocking = true;

    // <debuging>
    /*m_menus.at(MenuBattle::BM_CHOICE)->setShown(false);
    m_isBlocking = true;
    m_activeMenu = MenuBattle::BM_DIALOG;*/
    // std::dynamic_pointer_cast<MenuDialogBox>(m_menus.at(BM_DIALOG))->addText("Selected
    // choice.");
    /*std::dynamic_pointer_cast<MenuDialogBox>(m_menus.at(m_activeMenu))->continueText(g.getRealRessourceManager(RESSOURCE_TEXTURE_NUMBER_MENU),
     * g.getRealSurfaceManager(MENU_DIALOG_BOX_LAYER));*/

    // </debuging>
  }

  return ret;
}

// Close all the menus
int MenuBattle::close(ManageSurfaces &surf) {
  for (unsigned int i(0); i < m_menus.size(); i++) {
    m_menus.at(i)->close(surf);
  }

  return 0;
}

// Load the different menus
int MenuBattle::load(Battle *b, ManageRessources &ress, ManageSurfaces &surf) {
  m_menus.at(BM_LEFT)->load(ress, surf, 0, 0, CAMERA_WIDTH / 6, CAMERA_HEIGHT);
  m_menus.at(BM_RIGHT)->load(ress, surf, 5 * CAMERA_WIDTH / 6, 0,
                             CAMERA_WIDTH / 6, CAMERA_HEIGHT);
  m_menus.at(BM_DIALOG)->load(ress, surf, CAMERA_WIDTH / 6,
                              (4 * CAMERA_HEIGHT / 5), 2 * CAMERA_WIDTH / 3,
                              CAMERA_HEIGHT / 5);
  std::dynamic_pointer_cast<MenuChoice>(m_menus.at(BM_CHOICE))
      ->loadFromFile(ress, surf, MENU_BATTLE_CHOICE_TEXT, 0,
                     0); /*CAMERA_WIDTH / 6, (4 * CAMERA_HEIGHT / 5) -
                            (MENU_SIMPLE_FONTSIZE * 2));*/

  std::dynamic_pointer_cast<MenuChoice>(m_menus.at(BM_CHOICE))
      ->resizeChoiceSurface();

  return 0;
}