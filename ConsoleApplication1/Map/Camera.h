#pragma once


class Camera
{
public:
	Camera(bool blocked=true);
	Camera(const int &x, const int &y, const int &w, const int &h, const int &mx, const int &my, bool blocked = true);
	Camera(const Camera &c);
	~Camera();

	Camera &operator=(const Camera &c);

public:
	// Return if the camera is blocked at the borders
	bool getBlocked() const;
	// Return the abciss of the Tile
	int getX() const;
	// Return the y position of the Tile
	int getY() const;
	// Return the width of the Tile
	int getWidth() const;
	// Return the height of the Tile
	int getHeight() const;
	// Return the maxX of the camera
	int getMaxX() const;
	// Return the maxY of the camera
	int getMaxY() const;

	// Modify if the camera is blocked at the borders
	bool setBlocked(bool b);
	// Modify the abciss of the Tile
	int setX(const int &x);
	// Modify the y position of the Tile
	int setY(const int &y);
	// Modify the width of the Tile
	int setWidth(const int &w);
	// Modify the height of the Tile
	int setHeight(const int &h);
	// Modify the maxX of the camera
	int setMaxX(int mapWidth);
	// Modify the maxY of the camera
	int setMaxY(int mapHeight);

	// Move the camera to a direction
	int move(const int &dx, const int &dy);
private:
	bool m_blocked;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_maxX;
	int m_maxY;
};

