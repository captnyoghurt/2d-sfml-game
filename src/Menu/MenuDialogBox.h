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
 *  Menu to display a text.
 *
 */

#pragma once
#include <sstream>
#include "Menu.h"

class MenuDialogBox : public Menu {
 public:
  MenuDialogBox(ManageRessources &ress, ManageSurfaces &surf,
                int lastEventLayer);
  ~MenuDialogBox();

 public:
  /**
   * \brief Return the global text in the dialog box	.
   *
   * \return std::string object.
   */
  std::string getText() const;
  /**
   * \brief Return the first shown character	.
   *
   * \return int object.
   */
  int getFirstShownCharacter() const;
  /**
   * \brief Return the last shown character	.
   *
   * \return int object.
   */
  int getLastShownCharacter() const;

  /**
   * \brief Return the down cursor surface with modifying possibilities	.
   *
   * \return std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator &
  getCursorSurfaceDown();

  /**
   * \brief Modify if the menu should be shown or not	.
   *
   * \param b The new value.
   * \return int object.
   */
  int setShown(const bool &b);
  /**
   * \brief Modify the global text in the dialog box	.
   *
   * \param text The new value.
   * \return int object.
   */
  int setText(const std::string &text);
  /**
   * \brief Add text to the stream	.
   *
   * \return int object.
   */
  int addText(const std::string &text);

  /**
   * \brief Keep on reading in the text	.
   *
   * \return int object.
   */
  int continueText(ManageRessources &ress, ManageSurfaces &surf);

  /**
   * \brief Load the menu	.
   *
   * \return virtual object.
   */
  virtual int load(ManageRessources &ress, ManageSurfaces &surf,
                   const std::string &text, const int &xcam, const int &ycam,
                   const int &x = -1, const int &y = -1, const int &w = -1,
                   const int &h = -1);
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

 protected:
  /**
   * \brief Remake the text surface	.
   *
   * \return int object.
   */
  int remakeText(const std::string &str, std::shared_ptr<SurfaceText> text,
                 ManageRessources &ress);

  /**
   * \brief Read an instruction in the text	.
   *
   * \return int object.
   */
  int readInstruction(ManageSurfaces &surf);

  /**
   * \brief Create a new line	.
   *
   * \return int object.
   */
  int newLine(ManageSurfaces &surf);

 private:
  std::list<std::pair<ManageSurfaces::e_thing,
                      std::shared_ptr<Surface>>>::iterator m_cursorSurfaceDown;
  std::vector<std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>
      m_textSurface;
  std::string m_text;
  std::stringstream m_textStream;
  int m_firstShownCharacter;
  int m_lastShownCharacter;
};
