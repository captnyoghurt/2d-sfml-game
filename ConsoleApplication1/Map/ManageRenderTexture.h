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
	// Return the RenderTexture where all the surfaces are printed
	sf::RenderTexture getRenderTexture() const;
	// Return the render texture surface
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getRenderTextureSurface();
	// Return the vector of all the surfaces on the render texture
	std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator> getSurfaces() const;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getTheSurface(int n);

	// Return the RenderTexture where all the surfaces are printed with modifying possibilities
	sf::RenderTexture& getRealRenderTexture();
	// Return the render texture surface with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealRenderTextureSurface();
	// Return the vector of all the surfaces on the render texture with modifying possibilities
	std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>& getRealSurfaces();

private:
	sf::RenderTexture m_renderTexture;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_renderTextureSurface;
	std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>  m_surfaces;
};

