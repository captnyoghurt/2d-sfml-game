#include "SurfaceSprite.h"

#include <iostream>

SurfaceSprite::SurfaceSprite()
{
	std::cout << "Create surface Sprite " << this << std::endl;
}


SurfaceSprite::~SurfaceSprite()
{
	std::cout << "Destroying a surfacesprite " << this << std::endl;
}
