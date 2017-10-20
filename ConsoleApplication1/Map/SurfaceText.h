#pragma once

#include <SFML\Graphics.hpp>
#include "Surface.h"

class SurfaceText :
	public Surface,
	public sf::Text
{
public:
	using sf::Text::Text;
	SurfaceText();
	explicit SurfaceText(Text t);
	~SurfaceText();
};

