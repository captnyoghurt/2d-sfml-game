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
	// Return if the render texture need to be updated
	bool getUpdated() const;
	// Return if the render texture is initialized
	bool getInitialized() const;
 	// Return the render texture surface
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getRenderTextureSurface();
	// Return the vector of all the surfaces on the render texture
	std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator> getSurfaces() const;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getTheSurface(int n);

	// Return the RenderTexture where all the surfaces are printed with modifying possibilities
	sf::RenderTexture& getRealRenderTexture(bool updateIt = true);
	// Return the render texture surface with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealRenderTextureSurface(bool updateIt = true);
	// Return the vector of all the surfaces on the render texture with modifying possibilities
	std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>& getRealSurfaces(bool updateIt = true);

	// Tell the object to be updated
	int gotUpdated();

	// Add a surface to the render texture
	int add(std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator it);
	// Initialize the render texture
	int load(ManageSurfaces& surf, int w, int h, bool depthBuffer = false);
	// Update the render texture if necessary
	int update();
private:
	bool m_updated;
	bool m_initialized;
	sf::RenderTexture m_renderTexture;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_renderTextureSurface;
	std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>  m_surfaces;
};

