#pragma once
#include <vector>

class Tile
{
public:
	Tile();
	Tile(unsigned short x, unsigned short y, short w, short h);
	Tile(Tile &t);
	~Tile();

	Tile& operator=(const Tile &t);
public:
	// Return if the tile is empty or not
	bool getEmpty() const;
	// Return the abciss of the Tile
	unsigned short getX() const;
	// Return the y position of the Tile
	unsigned short getY() const;
	// Return the width of the Tile
	short getWidth() const;
	// Return the height of the Tile
	short getHeight() const;
	// Return the proprietes of the Tile
	std::vector<int> getProprieties() const;

	// Modify if the tile is empty or not
	int setEmpty(const bool &b);
	// Modify the abciss of the Tile
	int setX(const unsigned short &x);
	// Modify the y position of the Tile
	int setY(const unsigned short &y);
	// Modify the width of the Tile
	int setWidth(const short &w);
	// Modify the height of the Tile
	int setHeight(const short &h);
	// Modify the proprietes of the Tile
	int setProprieties(const std::vector<int> &props);

private:
	std::vector<int>  m_proprieties;
	bool m_empty;
	unsigned short m_x;
	unsigned short m_y;
	short m_width;
	short m_height;
};

