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
 *  Sprite type of surface.
 *
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "Surface.h"

class SurfaceSprite : public Surface, public sf::Sprite {
 public:
  SurfaceSprite();
  ~SurfaceSprite();
};
