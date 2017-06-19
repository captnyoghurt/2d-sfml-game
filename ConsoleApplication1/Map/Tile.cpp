#include "../constants.h"
#include "Tile.h"

Tile::Tile()
{
	m_empty = true;
	m_x = 0;
	m_y = 0;
	m_width = 0;
	m_height = 0;
}

Tile::Tile(unsigned short x, unsigned short y, short w, short h)
{
	m_empty = false;
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
}

Tile::Tile(Tile &t)
{
	m_empty = false;
	m_x = t.getX();
	m_y = t.getY();
	m_width = t.getWidth();
	m_height = t.getHeight();
	m_proprieties = t.getProprieties();
}

Tile::~Tile()
{
}


// Return if the tile is empty or not
bool Tile::getEmpty() const
{
	return m_empty;
}


// Return the abciss of the Tile
unsigned short Tile::getX() const
{
	return m_x;
}


// Return the y position of the Tile
unsigned short Tile::getY() const
{
	return m_y;
}


// Return the width of the Tile
short Tile::getWidth() const
{
	return m_width;
}


// Return the height of the Tile
short Tile::getHeight() const
{
	return m_height;
}


// Return the proprietes of the Tile
std::vector<int> Tile::getProprieties() const
{
	return m_proprieties;
}


// Modify if the tile is empty or not
int Tile::setEmpty(const bool &b)
{
	m_empty = b;
	return 0;
}


// Modify the abciss of the Tile
int Tile::setX(const unsigned short &x)
{
	if (x < 0)
		return -1;
	
	m_x = x;
	return 0;
}

// Modify the y position of the Tile
int Tile::setY(const unsigned short &y)
{
	if (y < 0)
		return -1;

	m_y = y;
	return 0;
}

// Modify the width of the Tile
int Tile::setWidth(const short &w)
{
	if (w < 0)
		return -1;

	m_width = w;
	return 0;
}

// Modify the height of the Tile
int Tile::setHeight(const short &h)
{
	if (h < 0)
		return -1;

	m_height = h;
	return 0;
}

// Modify the proprietes of the Tile
int Tile::setProprieties(const std::vector<int> &props)
{
	m_proprieties = props;
	return 0;
}