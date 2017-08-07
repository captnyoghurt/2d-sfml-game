#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Camera.h"
#include "Layer.h"
#include "ManageSurfaces.h"
#include "Tile.h"
#include "Physic/ManageHitbox.h"

class Game;

using namespace sf;

class Map
{
public:
	Map(Game &g);
	~Map();

public:
	// Return if the map is paused
	bool getPaused() const;
	// Return if the map was updated since the last print
	bool getUpdated() const;
	// Return the width of the layer
	int getWitdth() const;
	// Return the height of the layer
	int getHeight() const;
	// Return the name of the actual map
	std::string getName() const;
	// Return the surface of the name
	std::string getTextName()	const;
	// Return all the layers
	std::vector<Layer> getLayers() const;
	// Return the number of layers
	int getNumberOfLayer() const;
	// Return the tileset of this map
	Texture getTileset() const;
	// Return the camera
	Camera getCamera()	const;
	// Return the hitbox manager
	ManageHitbox getHitboxManager() const;

	// Return the camera with modifying possibilities
	Camera& getRealCamera();
	// Return the hitbox manager with modifying possibilities
	ManageHitbox& getRealHitboxManager();

	// Modify if the map is paused (won't be printed)
	int setPaused(const bool &b);
	// Modify the width of the layer
	int setWitdth(const int &w);
	// Modify the height of the layer
	int setHeight(const int &h);
	// Modify the name of the actual map
	int setName(std::string name);
	// Modify the tileset of this map
	int setTileset(std::string filename);
	int setTileset(Texture t);
	// Modify the camera
	int setCamera(const Camera &cam);

	// Ask the map a new print
	int gotUpdated();
	// Load a new map
	int load(std::string filename, Game &g);
	// Print the map
	int print(RenderWindow &win, std::vector<ManageSurfaces>& ms);
	// Update every item of the map
	int update();
private:
	bool m_paused;
	bool m_updated;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_mapName;
	std::string m_name;
	std::vector<Layer> m_layers;
	int	m_nbLayers;
	int m_width;
	int m_height;
	Texture m_tileset;
	Camera m_camera;
	ManageHitbox m_hitboxManager;
	//Musique
};

