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
 *  Menu to select choices.
 *
 */

#pragma once

#include "M_choice.h"
#include "Menu.h"

class Game;

class MenuChoice : public Menu {
 public:
  MenuChoice(ManageRessources &ress, ManageSurfaces &surf, int lastEventLayer);
  ~MenuChoice();

 public:
  /**
   * \brief Return the choices surfaces with modifying possibilities	.
   *
   * \return std::vector< object.
   */
  std::vector<std::shared_ptr<M_choice>> getChoices();
  /**
   * \brief Return the down cursor surfaces with modifying possibilities
   * .
   *
   * \return std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
  getCursorSurfaceDown();
  /**
   * \brief Return the up cursor surfaces with modifying possibilities	.
   *
   * \return std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
  getCursorSurfaceUp();
  /**
   * \brief Return the selected choice surface with modifying possibilities
   * .
   *
   * \return std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
  getSelectedChoiceSurface();
  /**
   * \brief Return the selected choice	.
   *
   * \return int object.
   */
  int getSelectedChoice() const;
  /**
   * \brief Return the first choice actually shown	.
   *
   * \return int object.
   */
  int getFirstChoiceShown() const;
  /**
   * \brief Return the last choice actually shown	.
   *
   * \return int object.
   */
  int getLastChoiceShown() const;

  /**
   * \brief Modify if the menu should be shown or not	.
   *
   * \param b The new value.
   * \return virtual object.
   */
  virtual int setShown(const bool &b);
  /**
   * \brief Modify the selected choice	.
   *
   * \param ch The new value.
   * \return int object.
   */
  int setSelectedChoice(const int &ch);

  /**
   * \brief Resize the ChoiceSurface according to the selected choice	.
   *
   * \return int object.
   */
  int resizeChoiceSurface();

  /**
   * \brief Load the menu	.
   *
   * \return virtual object.
   */
  virtual int loadFromStream(ManageRessources &ress, ManageSurfaces &surf,
                             std::stringstream &ss, const int &xcam,
                             const int &ycam, const int &wchoice = 0,
                             const int &hchoice = 0);
  virtual int loadFromFile(ManageRessources &ress, ManageSurfaces &surf,
                           const std::string &filename, const int &xcam,
                           const int &ycam, const int &wchoice = 0,
                           const int &hchoice = 0);
  /**
   * \brief Update surfaces	.
   *
   * \return virtual object.
   */
  virtual int update(Game &g);
  /**
   * \brief Close the menu	.
   *
   * \return virtual object.
   */
  virtual int close(ManageSurfaces &surf);

 private:
  std::vector<std::shared_ptr<M_choice>> m_choices;
  std::list<std::pair<ManageSurfaces::e_thing,
                      std::shared_ptr<Surface>>>::iterator m_cursorSurfaceUp;
  std::list<std::pair<ManageSurfaces::e_thing,
                      std::shared_ptr<Surface>>>::iterator m_cursorSurfaceDown;
  std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::
      iterator m_selectedChoiceSurface;
  int m_selectedChoice;
  int m_firstChoiceShown;
  int m_lastChoiceShown;
};