#include "ManageRenderTexture.h"



ManageRenderTexture::ManageRenderTexture()
{
}


ManageRenderTexture::~ManageRenderTexture()
{
}


// Return if the render texture need to be updated
bool ManageRenderTexture::getUpdated() const
{
	return m_updated;
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


// Tell the object to be updated
int ManageRenderTexture::gotUpdated()
{
	m_updated = true;

	return 0;
}


// Add a surface to the render texture
int ManageRenderTexture::add(std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator it)
{
	it->second->setEnable(false);
	m_surfaces.push_back(it);
	return 0;
}