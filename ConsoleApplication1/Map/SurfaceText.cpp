#include "SurfaceText.h"

#include <iostream>


SurfaceText::SurfaceText()
{
	std::cout << "Create surface Text " << this << std::endl;
}


SurfaceText::SurfaceText(sf::Text t) : Text(t)
{
	std::cout << "Create surface Text " << this << std::endl;
}


SurfaceText::~SurfaceText()
{
	std::cout << "Destroying a surfacetext " << this << std::endl;
}
