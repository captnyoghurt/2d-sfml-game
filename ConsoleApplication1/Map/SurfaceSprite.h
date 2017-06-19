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

