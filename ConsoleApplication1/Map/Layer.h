#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

using namespace sf;

class Layer
{
public:
	Layer();
	Layer(int w, int h, int tw, int th);
	~Layer();

public:
	// Return all the tile of the layer
	std::vector< std::vector<Tile> > getLayer() const;
	// Return the width of the layer
	int getWitdth() const;
	// Return the height of the layer
	int getHeight() const;
	// Return the width of each tile
	int getTileW() const;
	// Return the height of each tile
	int getTileH() const;
	// Return the tile asked (x,y) from the layer
	Tile& getTile(int x, int y);

	// Modify the width of the layer
	int setWitdth(const int &w);
	// Modify the height of the layer
	int setHeight(const int &h);
	// Modify the width and the height
	int resize(const int &w, const int &h);
	// Modify the width of each tile
	int setTileW(const int &w);
	// Modify the height of each tile
	int setTileH(const int &h);
	// Modify the tile asked (x,y) from the layer
	int setTile(int x, int y, const Tile& t);

	// Print the layer thanks to the tileset
	int printLayer(Texture tileset, RenderWindow &win, int xCam, int yCam, int wCam, int hCam);

private:
	std::vector< std::vector<Tile> > m_layer;
	int m_tileW;
	int m_tileH;
	int m_width;
	int m_height;
};

