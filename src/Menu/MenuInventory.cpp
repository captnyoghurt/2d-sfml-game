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
 *  Menu to show the bag.
 *
 */

#include "MenuInventory.h"
#include <algorithm>
#include <memory>
#include "../Error/InitializationException.h"
#include "../Error/ValueException.h"
#include "../constants.h"

MenuInventory::MenuInventory(ManageRessources& ress, ManageSurfaces& surf,
                             int lastEventLayer)
    : Menu(ress, surf, lastEventLayer),
      m_dialogBox(ress, surf, lastEventLayer),
      m_choices(ress, surf, lastEventLayer) {
  surf.deleteSurface(m_background);
}

MenuInventory::~MenuInventory() {}

// Return the spells
std::vector<std::pair<Item, int> > MenuInventory::getItems() const {
  return m_items;
}

// Return the dialog box with modifying possibilities
MenuDialogBox& MenuInventory::getRealDialogBox() { return m_dialogBox; }

// Return the menu choice with modifying possibilities
MenuChoice& MenuInventory::getRealMenuChoices() { return m_choices; }

// Return the spells with modifying possibilities
std::vector<std::pair<Item, int> >& MenuInventory::getRealItems() {
  return m_items;
}

// Load the menu
int MenuInventory::load(ManageRessources& ress, ManageSurfaces& surf,
                        const int& xcam, const int& ycam,
                        std::list<std::pair<Item, int> >& items,
                        std::vector<bool> enabledTypes) {
  if (m_initialized) THROW_GAME("Already initiate");
  if (items.empty()) THROW_VALUE("No spells");

  m_dialogBox.load(ress, surf, "Menu des sorts et techniques", xcam, ycam,
                   MENU_SPELLS_DIALOG_BOX_X, MENU_SPELLS_DIALOG_BOX_Y,
                   MENU_SPELLS_DIALOG_BOX_WIDTH, MENU_SPELLS_DIALOG_BOX_HEIGHT);

  std::stringstream inventoryStringStream(makeChoicesSS(items));
  m_choices.loadFromStream(ress, surf, inventoryStringStream, xcam, ycam,
                           MENU_SPELLS_CHOICES_WIDTH - (2 * MENUS_BORDER_X),
                           MENUS_GAP_BETWEEN_LINES);

  m_items.clear();
  m_items.reserve(items.size());
  std::copy(std::begin(items), std::end(items), std::back_inserter(m_items));

  for (unsigned int i(0); i < m_items.size(); i++) {
    sf::Color color((enabledTypes.at(m_items.at(i).first.getType()))
                        ? MENU_FONT_COLOR
                        : MENU_FONT_COLOR_DISABLED_CHOICE);

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
    std::dynamic_pointer_cast<SurfaceText>(m_choices.getChoices()
                                               .at(i)
                                               ->getRealRenderTextureManager()
                                               .getRealSurfaces()
                                               .at(0)
                                               ->second)
        ->setFillColor(color);

    // Add icon
    auto icon = surf.addSurface(ManageSurfaces::e_thing::SPRITE,
                                std::make_shared<SurfaceSprite>());
    icon->second->setDimensions(0, 0, ICON_WIDTH, ICON_HEIGHT);
    std::dynamic_pointer_cast<SurfaceSprite>(icon->second)
        ->setTexture(ress.getTheTexture(2));
    std::dynamic_pointer_cast<SurfaceSprite>(icon->second)
        ->setTextureRect(sf::IntRect(
            (m_items.at(i).first.getIconId() % ICONS_SURFACE_BY_LINE) *
                ICON_WIDTH,
            (m_items.at(i).first.getIconId() / ICONS_SURFACE_BY_LINE) *
                ICON_HEIGHT,
            ICON_WIDTH, ICON_HEIGHT));
    m_choices.getChoices().at(i)->getRealRenderTextureManager().add(icon, -4,
                                                                    -4);

    // Add number of item
    auto number = surf.addSurface(ManageSurfaces::e_thing::TEXT,
                                  std::make_shared<SurfaceText>());
    std::dynamic_pointer_cast<SurfaceText>(number->second)
        ->setFont(ress.getTheFont(0));
    std::dynamic_pointer_cast<SurfaceText>(number->second)
        ->setCharacterSize(MENU_SPELLS_FONTSIZE);
    // std::dynamic_pointer_cast<SurfaceText>(number->second)->setFillColor(color);
    std::dynamic_pointer_cast<SurfaceText>(number->second)
        ->setString(std::to_string(m_items.at(i).second));
    m_choices.getChoices().at(i)->getRealRenderTextureManager().add(
        number, MENU_SPELLS_CHOICES_WIDTH - (3 * MENU_SPELLS_FONTSIZE), 0);

    m_choices.getChoices().at(i)->getRealRenderTextureManager().update();
  }

  m_initialized = true;

  return 0;
}

// Update surfaces
int MenuInventory::update(Game& g) {
  m_dialogBox.update(g);
  m_choices.update(g);

  return 0;
}

// Close the menu
int MenuInventory::close(ManageSurfaces& surf) {
  if (!m_initialized) THROW_INIT("MenuSpells not initiate");

  m_dialogBox.close(surf);
  m_choices.close(surf);

  return m_lastEventLayer;
}

// Make a stringstream
std::stringstream MenuInventory::makeChoicesSS(
    std::list<std::pair<Item, int> >& items) {
  std::stringstream ss;

  ss << "AUTO\n"
     << MIN((signed)items.size(),
            (MENU_SPELLS_CHOICES_HEIGHT - (2 * MENUS_BORDER_Y)) /
                (MENUS_GAP_BETWEEN_LINES))
     << " " << MENU_SPELLS_CHOICES_X << " " << MENU_SPELLS_CHOICES_Y << " "
     << MENU_SPELLS_CHOICES_WIDTH << " " << MENU_SPELLS_CHOICES_HEIGHT;

  for (auto it(items.begin()); it != items.end(); it++) {
    ss << "\nNOTHING\n" << it->first.getName();
  }

  ss.seekg(0, ss.beg);
  return ss;
}