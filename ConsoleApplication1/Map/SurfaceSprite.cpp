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

#include "SurfaceSprite.h"
#include "../Error/debugFunctions.h"


SurfaceSprite::SurfaceSprite()
{
#ifdef DEBUG_MODE_ON
	DEB_ALLOCATED_SPRITE++;
#endif // DEBUG_MODE_ON
}


SurfaceSprite::~SurfaceSprite()
{
#ifdef DEBUG_MODE_ON
	DEB_ALLOCATED_SPRITE--;
#endif // DEBUG_MODE_ON
}