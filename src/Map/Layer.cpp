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
*  Layer of tile in the map.
*
*/

#include "Layer.h"
#include "../Error/ValueException.h"

using namespace sf;
using namespace std;

Layer::Layer()
{
	m_tileW = 0;
	m_tileH = 0;
	m_width = 0;
	m_height = 0;
}

Layer::Layer(int w, int h, int tw, int th)
{
	m_tileW = tw;
	m_tileH = th;
	m_width = w;
	m_height = h;

	m_layer.resize(w, vector<Tile>(h));
}

Layer::~Layer()
{
}


// Return all the tile of the layer
vector< vector<Tile> > Layer::getLayer() const
{
	return m_layer;
}


// Return the width of the layer
int Layer::getWitdth() const
{
	return m_width;
}


// Return the height of the layer
int Layer::getHeight() const
{
	return m_height;
}


// Return the width of each tile
int Layer::getTileW() const
{
	return m_tileW;
}


// Return the height of each tile
int Layer::getTileH() const
{
	return m_tileH;
}


// Return the tile asked (x,y) from the layer
Tile& Layer::getTile(int x, int y)
{
	return m_layer.at(x).at(y);
}


// Modify the width of the layer
int Layer::setWitdth(const int &w)
{
	if (w < 0)
		THROW_VALUE(std::to_string(w));

	m_width = w;

	m_layer.resize(w);

	return 0;
}


// Modify the height of the layer
int Layer::setHeight(const int &h)
{
	if (h < 0)
		THROW_VALUE(std::to_string(h));

	m_height = h;

	for (int i(0); i < m_width; i++)
	{
		m_layer.at(i).resize(h);
	}

	return 0;
}


int Layer::resize(const int &w, const int &h)
{
	if (w < 0 || h < 0)
		THROW_VALUE(std::to_string(w) + "/" + std::to_string(h));

	m_width = w;
	m_height = h;
	m_layer.resize(w, vector<Tile>(h));

	return 0;
}


// Modify the width of each tile
int Layer::setTileW(const int &w)
{
	m_tileW = w;

	return 0;
}


// Modify the height of each tile
int Layer::setTileH(const int &h)
{
	m_tileH = h;

	return 0;
}


// Modify the tile asked (x,y) from the layer
int Layer::setTile(int x, int y, const Tile& t)
{
	m_layer.at(x).at(y).setX(t.getX());
	m_layer.at(x).at(y).setY(t.getY());
	m_layer.at(x).at(y).setWidth(t.getWidth());
	m_layer.at(x).at(y).setHeight(t.getHeight());
	m_layer.at(x).at(y).setProprieties(t.getProprieties());

	return 0;
}


// Print the layer thanks to the tileset
int Layer::printLayer(Texture tileset, RenderWindow &win, int xCam, int yCam, int wCam, int hCam)
{
	Sprite sp;
	int iBegin = xCam/m_tileW - 1;
	int jBegin = yCam/m_tileH - 1;

	sp.setTexture(tileset, true);

	for (int i(0); i < wCam/m_tileW + 2 && i < m_width && i + iBegin < m_width; i++)
	{
		if (i + iBegin >= 0)
		{
			for (int j(0); j < hCam/m_tileH + 2 && j < m_height && j + jBegin < m_height; j++)
			{
				if (j + jBegin >= 0)
				{
					// The Most top-left Tile that can be seen (even partly) with the camera
					Tile t(m_layer.at(i + iBegin).at(j + jBegin));

					if (!t.getEmpty())
					{
						sp.setPosition(float((i - 1)*m_tileW - xCam%m_tileW), float((j - 1)*m_tileH - yCam%m_tileH));
						sp.setTextureRect(sf::IntRect(t.getX(), t.getY(), t.getWidth(), t.getHeight()));
						win.draw(sp);
					}
				}
			}
		}
	}
	return 0;
}