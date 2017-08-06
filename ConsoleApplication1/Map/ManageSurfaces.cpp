#include <iostream>
#include "ManageSurfaces.h"
#include "../Error/ValueException.h"


ManageSurfaces::ManageSurfaces()
{
}


ManageSurfaces::~ManageSurfaces()
{
}


// Return all the surfaces
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>> ManageSurfaces::getSurfaces() const
{
	return m_surfaces;
}


// Return modifying element
std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>& ManageSurfaces::getModifyingSurface(int n)
{
	int i(0);
	if (m_surfaces.size() >= (unsigned)n)
		return *m_surfaces.begin();

	for (auto it(m_surfaces.begin()); it != m_surfaces.end() ; ++it, ++i)
	{
		if (i == n)
			return *it;
	}

	return *m_surfaces.begin();
}


// Add an element
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator ManageSurfaces::addSurface(ManageSurfaces::e_thing type, std::shared_ptr<Surface> surf)
{
	m_surfaces.push_back(std::make_pair(type, surf));
	auto p = m_surfaces.end();
	--p;

	return p;
}


// Delete an element
int ManageSurfaces::deleteSurface(std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator it)
{
	m_surfaces.erase(it);

	return 0;
}


// Print the element
int ManageSurfaces::print(sf::RenderWindow &win, const Camera &cam)
{
	for (auto it(m_surfaces.begin()); it != m_surfaces.end(); ++it)
	{
		if ((it->second) == NULL)
		{
			THROW_VALUE("Error when managing a surface");
			it = m_surfaces.erase(it);
			--it;
		}
		else if ((it->second->getEnable()
				&& (!((it->second->getX() + it->second->getWidth() <= cam.getX())
				|| (it->second->getX() >= cam.getX() + cam.getWidth())
				|| (it->second->getY() + it->second->getHeight() <= cam.getY())
				|| (it->second->getY() >= cam.getY() + cam.getHeight())))))
		{
			switch (it->first)
			{
			case TEXT:
				std::dynamic_pointer_cast<SurfaceText>(it->second)->setPosition(float(it->second->getX() - cam.getX()), float(it->second->getY() - cam.getY()));
				win.draw(*std::dynamic_pointer_cast<SurfaceText>(it->second));
				break;
			case SPRITE:
				std::dynamic_pointer_cast<SurfaceSprite>(it->second)->setPosition(float(it->second->getX() - cam.getX()), float(it->second->getY() - cam.getY()));
				win.draw(*std::dynamic_pointer_cast<SurfaceSprite>(it->second));
				break;
			default:
				THROW_VALUE("Error when blitting a surface " + std::to_string(it->first));
				break;
			}
		}
	}
	return 0;
}