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
 *  Text type of surface.
 *
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "Surface.h"

class SurfaceText : public Surface, public sf::Text {
 public:
  using sf::Text::Text;
  SurfaceText();
  explicit SurfaceText(Text t);
  ~SurfaceText();
};
