#pragma once

#include <list>
#include <SFML\Graphics.hpp>
#include <vector>
#include "ManageSurfaces.h"
#include "Surface.h"

class ManageRenderTexture
{
public:
	ManageRenderTexture();
	~ManageRenderTexture();

public:

private:
	sf::RenderTexture m_renderTexture;
	std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>  m_surfaces;
};

