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
 *  Save and manage the different surfaces.
 *
 */

#pragma once

#include <list>
#include <memory>
#include "Camera.h"
#include "Surface.h"
#include "SurfaceSprite.h"
#include "SurfaceText.h"

class ManageSurfaces {
 public:
  enum e_thing { VOID, TEXT, SPRITE };

 public:
  ManageSurfaces();
  ~ManageSurfaces();

 public:
  /**
   * \brief Return all the surfaces	.
   *
   * \return std::list<std::pair<e_thing, object.
   */
  std::list<std::pair<e_thing, std::shared_ptr<Surface>>> getSurfaces() const;

  /**
   * \brief Return modifying element	.
   *
   * \return std::pair<e_thing, object.
   */
  std::pair<e_thing, std::shared_ptr<Surface>> &getModifyingSurface(int n);

  /**
   * \brief Add an element	.
   *
   * \return std::list<std::pair<e_thing, object.
   */
  std::list<std::pair<e_thing, std::shared_ptr<Surface>>>::iterator addSurface(
      e_thing type, std::shared_ptr<Surface> surf);
  /**
   * \brief Delete an element	.
   *
   * \return int object.
   */
  int deleteSurface(
      std::list<std::pair<e_thing, std::shared_ptr<Surface>>>::iterator it);
  /**
   * \brief Print the element	.
   *
   * \return int object.
   */
  int print(sf::RenderWindow &win, const Camera &cam);

 private:
  std::list<std::pair<e_thing, std::shared_ptr<Surface>>> m_surfaces;
};
