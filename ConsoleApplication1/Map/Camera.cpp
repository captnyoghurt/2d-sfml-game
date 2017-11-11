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
*  Camera of the map.
*
*/

#include <iostream>
#include "Camera.h"


Camera::Camera(bool blocked)
{
	m_blocked = blocked;
	m_x = 0;
	m_y = 0;
	m_width = 0;
	m_height = 0;
	m_maxX = 0;
	m_maxY = 0;
}


Camera::Camera(const int &x, const int &y, const int &w, const int &h, const int &mx, const int &my, bool blocked)
{
	m_blocked = blocked;
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	setMaxX(mx);
	setMaxY(my);
}


Camera::Camera(const Camera &c)
{
	m_blocked = c.getBlocked();
	m_height = c.getHeight();
	m_width = c.getWidth();
	m_x = c.getX();
	m_y = c.getY();
	m_maxX = c.getMaxX();
	m_maxY = c.getMaxY();
}

Camera::~Camera()
{
}


Camera &Camera::operator=(const Camera &c)
{
	m_blocked = c.getBlocked();
	m_height = c.getHeight();
	m_width = c.getWidth();
	m_x = c.getX();
	m_y = c.getY();
	m_maxX = c.getMaxX();
	m_maxY = c.getMaxY();

	return *this;
}


// Return if the camera is blocked at the borders
bool Camera::getBlocked() const
{
	return m_blocked;
}


// Return the abciss of the Tile
int Camera::getX() const
{
	return m_x;
}


// Return the y position of the Tile
int Camera::getY() const
{
	return m_y;
}


// Return the width of the Tile
int Camera::getWidth() const
{
	return m_width;
}


// Return the height of the Tile
int Camera::getHeight() const
{
	return m_height;
}


// Return the maxX of the camera
int Camera::getMaxX() const
{
	return m_maxX;
}


// Return the maxY of the camera
int Camera::getMaxY() const
{
	return m_maxY;
}


// Modify if the camera is blocked at the borders
bool Camera::setBlocked(bool b)
{
	m_blocked = b;
	return 0;
}


// Modify the abciss of the Tile
int Camera::setX(const int &x)
{
	m_x = x;

	//std::cout << "Camera setX " << m_x << "/" << m_y << std::endl;

	return 0;
}


// Modify the y position of the Tile
int Camera::setY(const int &y)
{
	m_y = y;

	//std::cout << "Camera setY " << m_x << "/" << m_y << std::endl;

	return 0;
}


// Modify the width of the Tile
int Camera::setWidth(const int &w)
{
	if (w < 0)
		return -1;

	m_width = w;
	return 0;
}


// Modify the height of the Tile
int Camera::setHeight(const int &h)
{
	if (h < 0)
		return -1;

	m_height = h;
	return 0;
}


// Move the camera to a direction
int Camera::move(const int &dx, const int &dy)
{
	if (m_blocked)
	{
		if (m_x + dx <= 0)
		{
			m_x = 0;
		}
		else if (m_x + dx >= m_maxX)
		{
			m_x = m_maxX;
		}
		else
		{
			m_x += dx;
		}
		if (m_y + dy <= 0)
		{
			m_y = 0;
		}
		else if (m_y + dy >= m_maxY)
		{
			m_y = m_maxY;
		}
		else
		{
			m_y += dy;
		}
	}
	else
	{
		m_x += dx;
		m_y += dy;
	}
	return 0;
}


// Modify the maxX of the camera
int Camera::setMaxX(int mapWidth)
{
	if (mapWidth - m_width >= 0)
	{
		m_maxX = mapWidth - m_width;
		return 0;
	}
	return -1;
}


// Modify the maxY of the camera
int Camera::setMaxY(int mapHeight)
{
	if (mapHeight - m_height >= 0)
	{
		m_maxY = mapHeight - m_height;
		return 0;
	}
	return -1;
}