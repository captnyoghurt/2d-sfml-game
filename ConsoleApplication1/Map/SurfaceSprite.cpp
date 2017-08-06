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
