#pragma once


class Surface
{
public:
	Surface();
	virtual ~Surface();

public:
	// Return if it should be printed
	bool getEnable() const;
	// Return the abciss of the Surface
	int getX() const;
	// Return the y position of the Surface
	int getY() const;
	// Return the width of the Surface
	int getWidth() const;
	// Return the height of the Surface
	int getHeight() const;

	// Modify if it should be printed
	int setEnable(const bool &e);
	// Modify the abciss of the Surface
	int setX(const int &x);
	// Modify the y position of the Surface
	int setY(const int &y);
	// Modify the width of the Surface
	int setWidth(const int &w);
	// Modify the height of the Surface
	int setHeight(const int &h);
	// Modify everything
	int setDimensions(const int &x, const int &y, const int &w = -1, const int &h = -1);

private:
	bool m_enable;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};

