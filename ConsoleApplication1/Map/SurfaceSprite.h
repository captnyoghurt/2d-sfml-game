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
*  Sprite type of surface.
*
*/

#pragma once

#include "Surface.h"
#include <SFML\Graphics.hpp>

class SurfaceSprite :
	public Surface,
	public sf::Sprite
{
public:
	SurfaceSprite();
	~SurfaceSprite();
};
