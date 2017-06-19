#include "ManageRenderTexture.h"



ManageRenderTexture::ManageRenderTexture()
{
}


ManageRenderTexture::~ManageRenderTexture()
{
}


// Return the RenderTexture where all the surfaces are printed
sf::RenderTexture ManageRenderTexture::getRenderTexture() const
{
	return m_renderTexture;
}


// Return the render texture surface
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator ManageRenderTexture::getRenderTextureSurface()
{
	return m_renderTextureSurface;
}


// Return the vector of all the surfaces on the render texture
std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator> ManageRenderTexture::getSurfaces() const
{
	return m_surfaces;
}
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator ManageRenderTexture::getTheSurface(int n)
{
	if ((unsigned)n < m_surfaces.size())
		return m_surfaces.at(n);

	/// Error
	return m_renderTextureSurface;
}


// Return the RenderTexture where all the surfaces are printed with modifying possibilities
sf::RenderTexture& ManageRenderTexture::getRealRenderTexture()
{
	return m_renderTexture;
}


// Return the render texture surface with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& ManageRenderTexture::getRealRenderTextureSurface()
{
	return m_renderTextureSurface;
}


// Return the vector of all the surfaces on the render texture with modifying possibilities
std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator>& ManageRenderTexture::getRealSurfaces()
{
	return m_surfaces;
}