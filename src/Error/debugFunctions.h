#pragma once

// Say if this is in debug mode
#define DEBUG_MODE_ON

#ifdef DEBUG_MODE_ON

extern int DEB_ALLOCATED_SURFACE;
extern int DEB_ALLOCATED_TEXT;
extern int DEB_ALLOCATED_SPRITE;

extern int DEB_ALLOCATED_ANIMATION;

void deb_start();
void deb_end();

#endif // DEBUG_MODE_ON
