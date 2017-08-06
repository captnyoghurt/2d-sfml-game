#include "debugFunctions.h"

#ifdef DEBUG_MODE_ON

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int DEB_ALLOCATED_SURFACE(0);
int DEB_ALLOCATED_TEXT(0);
int DEB_ALLOCATED_SPRITE(0);


void deb_start()
{
	freopen("err.txt", "w", stderr);
}


void deb_end()
{
	std::cerr << "\n\n\n##############################################\n"
		<< "###            END OF DEBUGING             ###\n"
		<< "##############################################\n"
		<< "\n\tLeak allocated surface :" << DEB_ALLOCATED_SURFACE
		<< "\n\tLeak allocated text :" << DEB_ALLOCATED_TEXT
		<< "\n\tLeak allocated sprite :" << DEB_ALLOCATED_SPRITE;
}

#endif // DEBUG_MODE_ON