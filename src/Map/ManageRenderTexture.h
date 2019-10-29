/** /
 *  @file
 *  @author  Paul Coignet
 *  @date    11 / 11 / 2017
 *  @version 0.1
 *
 *  @brief Class header.
 *
 *  @section DESCRIPTION
 *
 *  Manage render texture.
 *
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include "ManageSurfaces.h"
#include "Surface.h"

class ManageRenderTexture {
 public:
  ManageRenderTexture();
  ~ManageRenderTexture();

 public:
  /**
   * \brief Return if the render texture need to be updated	.
   *
   * \return bool object.
   */
  bool getUpdated() const;
  /**
   * \brief Return if the render texture is initialized	.
   *
   * \return bool object.
   */
  bool getInitialized() const;
  // Return the render texture surface
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
  getRenderTextureSurface();
  /**
   * \brief Return the vector of all the surfaces on the render texture	.
   *
   * \return std::vector<std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::vector<std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>
  getSurfaces() const;
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
  getTheSurface(int n);

  /**
   * \brief Return the RenderTexture where all the surfaces are printed with
   * modifying possibilities	.
   *
   * \return sf::RenderTexture& object.
   */
  sf::RenderTexture& getRealRenderTexture(bool updateIt = true);
  /**
   * \brief Return the render texture surface with modifying possibilities
   * .
   *
   * \return std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator&
  getRealRenderTextureSurface(bool updateIt = true);
  /**
   * \brief Return the vector of all the surfaces on the render texture with
   * modifying possibilities	.
   *
   * \return std::vector<std::list<std::pair<ManageSurfaces::e_thing, object.
   */
  std::vector<std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>&
  getRealSurfaces(bool updateIt = true);

  /**
   * \brief Tell the object to be updated	.
   *
   * \return int object.
   */
  int gotUpdated();

  /**
   * \brief Add a surface to the render texture	.
   *
   * \return int object.
   */
  int add(std::list<std::pair<ManageSurfaces::e_thing,
                              std::shared_ptr<Surface>>>::iterator it,
          int x = -1, int y = -1);
  /**
   * \brief Initialize the render texture	.
   *
   * \return int object.
   */
  int load(ManageSurfaces& surf, int x, int y, int w, int h,
           bool depthBuffer = false);
  /**
   * \brief Update the render texture if necessary	.
   *
   * \return int object.
   */
  int update();
  /**
   * \brief Clear the surfaces	.
   *
   * \return int object.
   */
  int clear(ManageSurfaces& surf);

 private:
  bool m_updated;
  bool m_initialized;
  sf::RenderTexture m_renderTexture;
  std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::
      iterator m_renderTextureSurface;
  std::vector<std::list<
      std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>
      m_surfaces;
};
