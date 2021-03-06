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
 *  Menu to show the spells.
 *
 */

#include "MenuSpells.h"
#include "../Error/InitializationException.h"
#include "../Error/ValueException.h"
#include "../constants.h"

MenuSpells::MenuSpells(ManageRessources& ress, ManageSurfaces& surf,
                       int lastEventLayer)
    : Menu(ress, surf, lastEventLayer),
      m_dialogBox(ress, surf, lastEventLayer),
      m_choices(ress, surf, lastEventLayer) {
  surf.deleteSurface(m_background);
}

MenuSpells::~MenuSpells() {}

// Return the spells
std::vector<Spell> MenuSpells::getSpells() const { return *m_spells; }

// Return the dialog box with modifying possibilities
MenuDialogBox& MenuSpells::getRealDialogBox() { return m_dialogBox; }

// Return the menu choice with modifying possibilities
MenuChoice& MenuSpells::getRealMenuChoices() { return m_choices; }

// Return the spells with modifying possibilities
std::vector<Spell>& MenuSpells::getRealSpells() { return *m_spells; }

// Load the menu
int MenuSpells::load(ManageRessources& ress, ManageSurfaces& surf,
                     const int& xcam, const int& ycam,
                     std::vector<Spell>& spells) {
  if (m_initialized) THROW_GAME("Already initiate");
  if (spells.empty()) THROW_VALUE("No spells");

  m_dialogBox.load(ress, surf, "Menu des sorts et techniques", xcam, ycam,
                   MENU_SPELLS_DIALOG_BOX_X, MENU_SPELLS_DIALOG_BOX_Y,
                   MENU_SPELLS_DIALOG_BOX_WIDTH, MENU_SPELLS_DIALOG_BOX_HEIGHT);

  std::stringstream spellsStringStream(makeChoicesSS(spells));
  m_choices.loadFromStream(ress, surf, spellsStringStream, xcam, ycam,
                           MENU_SPELLS_CHOICES_WIDTH - (2 * MENUS_BORDER_X),
                           MENUS_GAP_BETWEEN_LINES);

  m_spells = std::make_unique<std::vector<Spell>>(spells);

  for (unsigned int i(0); i < spells.size(); i++) {
    m_choices.getChoices()
        .at(i)
        ->getRealRenderTextureManager()
        .getRealRenderTextureSurface()
        ->second->setWidth(MENU_SPELLS_CHOICES_WIDTH -
                           (2 * MENUS_GAP_BETWEEN_LINES));
    std::dynamic_pointer_cast<SurfaceText>(m_choices.getChoices()
                                               .at(i)
                                               ->getRealRenderTextureManager()
                                               .getRealSurfaces()
                                               .at(0)
                                               ->second)
        ->setPosition(std::dynamic_pointer_cast<SurfaceText>(
                          m_choices.getChoices()
                              .at(i)
                              ->getRealRenderTextureManager()
                              .getRealSurfaces()
                              .at(0)
                              ->second)
                              ->getPosition()
                              .x +
                          ICON_WIDTH,
                      std::dynamic_pointer_cast<SurfaceText>(
                          m_choices.getChoices()
                              .at(i)
                              ->getRealRenderTextureManager()
                              .getRealSurfaces()
                              .at(0)
                              ->second)
                          ->getPosition()
                          .y);

    // Add icon
    auto icon = surf.addSurface(ManageSurfaces::e_thing::SPRITE,
                                std::make_shared<SurfaceSprite>());
    icon->second->setDimensions(0, 0, ICON_WIDTH, ICON_HEIGHT);
    std::dynamic_pointer_cast<SurfaceSprite>(icon->second)
        ->setTexture(ress.getTheTexture(2));
    std::dynamic_pointer_cast<SurfaceSprite>(icon->second)
        ->setTextureRect(sf::IntRect(
            (m_spells->at(i).getIconId() % ICONS_SURFACE_BY_LINE) * ICON_WIDTH,
            (m_spells->at(i).getIconId() / ICONS_SURFACE_BY_LINE) * ICON_HEIGHT,
            ICON_WIDTH, ICON_HEIGHT));
    m_choices.getChoices().at(i)->getRealRenderTextureManager().add(icon, -4,
                                                                    -4);

    // Add TP cost
    auto costtp = surf.addSurface(ManageSurfaces::e_thing::TEXT,
                                  std::make_shared<SurfaceText>());
    std::dynamic_pointer_cast<SurfaceText>(costtp->second)
        ->setFont(ress.getTheFont(0));
    std::dynamic_pointer_cast<SurfaceText>(costtp->second)
        ->setCharacterSize(MENU_SPELLS_FONTSIZE);
    std::dynamic_pointer_cast<SurfaceText>(costtp->second)
        ->setFillColor(MENU_SPELLS_COLOR_TP);
    std::dynamic_pointer_cast<SurfaceText>(costtp->second)
        ->setString(std::to_string(spells.at(i).getCostTP()));
    m_choices.getChoices().at(i)->getRealRenderTextureManager().add(
        costtp, MENU_SPELLS_CHOICES_WIDTH - (3 * MENU_SPELLS_FONTSIZE), 0);

    // Add MP cost
    auto costmp = surf.addSurface(ManageSurfaces::e_thing::TEXT,
                                  std::make_shared<SurfaceText>());
    std::dynamic_pointer_cast<SurfaceText>(costmp->second)
        ->setFont(ress.getTheFont(0));
    std::dynamic_pointer_cast<SurfaceText>(costmp->second)
        ->setCharacterSize(MENU_SPELLS_FONTSIZE);
    std::dynamic_pointer_cast<SurfaceText>(costmp->second)
        ->setFillColor(MENU_SPELLS_COLOR_MP);
    std::dynamic_pointer_cast<SurfaceText>(costmp->second)
        ->setString(std::to_string(spells.at(i).getCostMP()));
    m_choices.getChoices().at(i)->getRealRenderTextureManager().add(
        costmp, MENU_SPELLS_CHOICES_WIDTH - (8 * MENU_SPELLS_FONTSIZE), 0);

    // Add HP cost
    auto costhp = surf.addSurface(ManageSurfaces::e_thing::TEXT,
                                  std::make_shared<SurfaceText>());
    std::dynamic_pointer_cast<SurfaceText>(costhp->second)
        ->setFont(ress.getTheFont(0));
    std::dynamic_pointer_cast<SurfaceText>(costhp->second)
        ->setCharacterSize(MENU_SPELLS_FONTSIZE);
    std::dynamic_pointer_cast<SurfaceText>(costhp->second)
        ->setFillColor(MENU_SPELLS_COLOR_HP);
    std::dynamic_pointer_cast<SurfaceText>(costhp->second)
        ->setString(std::to_string(spells.at(i).getCostHP()));
    m_choices.getChoices().at(i)->getRealRenderTextureManager().add(
        costhp, MENU_SPELLS_CHOICES_WIDTH - (13 * MENU_SPELLS_FONTSIZE), 0);

    m_choices.getChoices().at(i)->getRealRenderTextureManager().update();
  }

  m_initialized = true;

  return 0;
}

// Update surfaces
int MenuSpells::update(Game& g) {
  m_dialogBox.update(g);
  m_choices.update(g);

  return 0;
}

// Close the menu
int MenuSpells::close(ManageSurfaces& surf) {
  if (!m_initialized) THROW_INIT("MenuSpells not initiate");

  m_dialogBox.close(surf);
  m_choices.close(surf);

  return m_lastEventLayer;
}

// Make a stringstream
std::stringstream MenuSpells::makeChoicesSS(std::vector<Spell>& spells) {
  std::stringstream ss;

  ss << "AUTO\n"
     << MIN((signed)spells.size(),
            (MENU_SPELLS_CHOICES_HEIGHT - (2 * MENUS_BORDER_Y)) /
                (MENUS_GAP_BETWEEN_LINES))
     << " " << MENU_SPELLS_CHOICES_X << " " << MENU_SPELLS_CHOICES_Y << " "
     << MENU_SPELLS_CHOICES_WIDTH << " " << MENU_SPELLS_CHOICES_HEIGHT << "\n";

  for (unsigned int i(0); i < spells.size(); i++) {
    ss << "NOTHING\n" << spells.at(i).getName();

    if ((unsigned)(i + 1) < spells.size()) ss << "\n";
  }

  ss.seekg(0, ss.beg);
  return ss;
}