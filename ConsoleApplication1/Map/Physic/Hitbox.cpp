#include "Hitbox.h"
#include "../../Error/ValueException.h"



Hitbox::Hitbox() :
	m_id(-1),
	m_x(0),
	m_y(0),
	m_width(0),
	m_height(0)
{
}

Hitbox::Hitbox(const int &id, const int &x, const int &y, const int &w, const int &h) :
	m_id(id),
	m_x(x),
	m_y(y),
	m_width(w),
	m_height(h)
{
}

Hitbox::Hitbox(const int &id, const sf::Rect<int> &r) :
	Hitbox(id, r.left, r.top, r.width, r.height)
{
}

Hitbox::Hitbox(const Hitbox &hb) :
	Hitbox(hb.getId(), hb.getX(), hb.getY(), hb.getWidth(), hb.getHeight())
{
}

Hitbox::~Hitbox()
{
}


// Return the id of the Hitbox
int Hitbox::getId() const
{
	return m_id;
}


// Return the abciss of the Hitbox
int Hitbox::getX() const
{
	return m_x;
}


// Return the y position of the Hitbox
int Hitbox::getY() const
{
	return m_y;
}


// Return the width of the Hitbox
int Hitbox::getWidth() const
{
	return m_width;
}


// Return the height of the Hitbox
int Hitbox::getHeight() const
{
	return m_height;
}


// Modify the id of the Hitbox
int Hitbox::setId(const int &id)
{
	m_id = id;

	return 0;
}


// Hitbox the abciss of the Hitbox
int Hitbox::setX(const int &x)
{
	if (x < 0)
		THROW_VALUE(std::to_string(x));

	m_x = x;
	return 0;
}

// Modify the y position of the Hitbox
int Hitbox::setY(const int &y)
{
	if (y < 0)
		THROW_VALUE(std::to_string(y));

	m_y = y;
	return 0;
}

// Modify the width of the Hitbox
int Hitbox::setWidth(const int &w)
{
	if (w < 0)
		THROW_VALUE(std::to_string(w));

	m_width = w;
	return 0;
}

// Modify the height of the Hitbox
int Hitbox::setHeight(const int &h)
{
	if (h < 0)
		THROW_VALUE(std::to_string(h));

	m_height = h;
	return 0;
}


// Modify x & y of the Hitbox
int Hitbox::move(const int &dx, const int &dy)
{
	return setX(m_x + dx) + setY(m_y + dy);
}


// Move to a position
int Hitbox::moveTo(const int &x, const int &y)
{
	return setX(x) + setY(y);
}