#pragma once

#include <list>
#include <memory>
#include "Camera.h"
#include "Surface.h"
#include "SurfaceText.h"
#include "SurfaceSprite.h"

class ManageSurfaces
{
public:
	enum e_thing{VOID, TEXT, SPRITE};

public:
	ManageSurfaces();
	~ManageSurfaces();

public:
	// Return all the surfaces
	std::list<std::pair<e_thing, std::shared_ptr<Surface>>> getSurfaces() const;

	// Return modifying element
	std::pair<e_thing, std::shared_ptr<Surface>>& getModifyingSurface(int n);

	// Add an element
	std::list<std::pair<e_thing, std::shared_ptr<Surface>>>::iterator addSurface(e_thing type, std::shared_ptr<Surface> surf);
	// Delete an element
	int deleteSurface(std::list<std::pair<e_thing, std::shared_ptr<Surface>>>::iterator it);
	// Print the element
	int print(sf::RenderWindow &win, const Camera &cam);

private:
	std::list<std::pair<e_thing, std::shared_ptr<Surface>>> m_surfaces;

};

