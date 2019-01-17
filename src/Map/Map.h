/**
*  @file
*  @author  Paul Coignet
*  @date    11 / 11 / 2017
*  @version 0.1
*
*  @brief Class header.
*
*  @section DESCRIPTION
*
*  The map information.
*
*/

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
	explicit Map(Game &g);
	~Map();

public:
	/**
	* \brief Return if the map is paused	.
	*
	* \return bool object.
	*/
	bool getPaused() const;
	/**
	* \brief Return if the map was updated since the last print	.
	*
	* \return bool object.
	*/
	bool getUpdated() const;
	/**
	* \brief Return the width of the layer	.
	*
	* \return int object.
	*/
	int getWitdth() const;
	/**
	* \brief Return the height of the layer	.
	*
	* \return int object.
	*/
	int getHeight() const;
	/**
	* \brief Return the name of the actual map	.
	*
	* \return std::string object.
	*/
	std::string getName() const;
	/**
	* \brief Return the surface of the name	.
	*
	* \return std::string object.
	*/
	std::string getTextName()	const;
	/**
	* \brief Return all the layers	.
	*
	* \return std::vector<Layer> object.
	*/
	std::vector<Layer> getLayers() const;
	/**
	* \brief Return the number of layers	.
	*
	* \return int object.
	*/
	int getNumberOfLayer() const;
	/**
	* \brief Return the tileset of this map	.
	*
	* \return Texture object.
	*/
	Texture getTileset() const;
	/**
	* \brief Return the camera	.
	*
	* \return Camera object.
	*/
	Camera getCamera()	const;
	/**
	* \brief Return the hitbox manager	.
	*
	* \return ManageHitbox object.
	*/
	ManageHitbox getHitboxManager() const;

	/**
	* \brief Return the camera with modifying possibilities	.
	*
	* \return Camera& object.
	*/
	Camera& getRealCamera();
	/**
	* \brief Return the hitbox manager with modifying possibilities	.
	*
	* \return ManageHitbox& object.
	*/
	ManageHitbox& getRealHitboxManager();

	/**
	* \brief Modify if the map is paused (won't be printed)	.
	*
	* \param b The new value.
	* \return int object.
	*/
	int setPaused(const bool &b);
	/**
	* \brief Modify the width of the layer	.
	*
	* \param w The new value.
	* \return int object.
	*/
	int setWitdth(const int &w);
	/**
	* \brief Modify the height of the layer	.
	*
	* \param h The new value.
	* \return int object.
	*/
	int setHeight(const int &h);
	/**
	* \brief Modify the name of the actual map	.
	*
	* \param name The new value.
	* \return int object.
	*/
	int setName(std::string name);
	/**
	* \brief Modify the tileset of this map	.
	*
	* \param filename The new value.
	* \return int object.
	*/
	int setTileset(std::string filename);
	int setTileset(Texture t);
	/**
	* \brief Modify the camera	.
	*
	* \param cam The new value.
	* \return int object.
	*/
	int setCamera(const Camera &cam);

	/**
	* \brief Ask the map a new print	.
	*
	* \return int object.
	*/
	int gotUpdated();
	/**
	* \brief Load a new map	.
	*
	* \return int object.
	*/
	int load(std::string filename, Game &g);
	/**
	* \brief Print the map	.
	*
	* \return int object.
	*/
	int print(RenderWindow &win, std::vector<ManageSurfaces>& ms);
	/**
	* \brief Update every item of the map	.
	*
	* \return int object.
	*/
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
	/**
	* \brief usique	.
	*
	* \return ; object.
	*/
};
