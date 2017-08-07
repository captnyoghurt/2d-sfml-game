#include "ManageHitbox.h"
#include "../../constants.h"
#include "../../Error/ValueException.h"



ManageHitbox::ManageHitbox()
{
	m_idCount = 0;
}


ManageHitbox::~ManageHitbox()
{
	m_hitbox.clear();
	m_tileHitbox.clear();
}


// Return the id counter
int ManageHitbox::getIdCount() const
{
	return m_idCount;
}


// Return the tile hitbox
std::map< std::pair<int, int>, Hitbox > ManageHitbox::getTileHitbox() const
{
	return m_tileHitbox;
}


// Return the normal hitbox
std::deque< Hitbox > ManageHitbox::getHitbox() const
{
	return m_hitbox;
}


// Return the tile hitbox with modifying possibilities
std::map< std::pair<int, int>, Hitbox >& ManageHitbox::getRealTileHitbox()
{
	return m_tileHitbox;
}


// Return the normal hitbox with modifying possibilities
std::deque< Hitbox >& ManageHitbox::getRealHitbox()
{
	return m_hitbox;
}


// Add a tile hitbox
std::shared_ptr<Hitbox> ManageHitbox::addTileHitbox(const int &tx, const int &ty, const Hitbox& hb)
{
	if (tx < 0 || ty < 0)
		THROW_VALUE("Wrong tile hitbox position : " + std::to_string(tx) + std::to_string(ty));

	m_tileHitbox.insert(std::make_pair(std::make_pair(tx, ty), hb));

	return std::make_shared<Hitbox>(m_tileHitbox.at(std::make_pair(tx, ty)));
}


// Add a hitbox
std::shared_ptr<Hitbox> ManageHitbox::addHitbox(const Hitbox& hb, const int &id)
{
	m_hitbox.push_back(hb);

	if (id == -1)
		m_hitbox.back().setId(++m_idCount);

	return std::make_shared<Hitbox>(m_hitbox.back());
}


// Give the tile hitbox
Hitbox& ManageHitbox::at(const int &tx, const int &ty)
{
	auto it = m_tileHitbox.find(std::make_pair(tx, ty));

	if (it == m_tileHitbox.end())
		THROW_VALUE("TileHitbox doesn't exist : " + std::to_string(tx) + std::to_string(ty));

	return it->second;
}


// Return the rect of tile where the hitbox is
sf::Rect<int> ManageHitbox::rectTilePosition(const Hitbox &hb)
{
	sf::Rect<int> rect(0, 0, 0, 0);

	rect.left = hb.getX() / TILE_WIDTH;
	rect.top = hb.getY() / TILE_HEIGHT;

	// Get the width
	for (rect.width = 0; (rect.left + 1 + rect.width)*TILE_WIDTH >= hb.getX() + hb.getWidth(); rect.width++);

	// Get the height
	for (rect.height = 0; (rect.top + 1 + rect.height)*TILE_HEIGHT >= hb.getY() + hb.getHeight(); rect.height++);

	return rect;
}


// Return if the hitbox will collide
ManageHitbox::e_CollisionType ManageHitbox::willCollide(const Hitbox &hb, const int &dx, const int &dy)
{
	Hitbox newHb(hb);
	newHb.setX(newHb.getX() + dx);
	newHb.setY(newHb.getY() + dy);

	return collision(newHb);
}


// Return if the hitbox is colliding
ManageHitbox::e_CollisionType ManageHitbox::collision(const Hitbox &hb)
{
	sf::Rect<int> rect(rectTilePosition(hb));
	ManageHitbox::e_CollisionType maxCollision(COLLISION_NONE);
	ManageHitbox::e_CollisionType temp(COLLISION_NONE);

	for(int i(rect.left) ; i < rect.left + rect.width ; i++)
		for (int j(rect.top); j < rect.top + rect.height; j++)
		{
			auto it(m_tileHitbox.find(std::make_pair(i, j)));
			if (it != m_tileHitbox.end())
			{
				temp = areColliding(hb, it->second);
				maxCollision = MAX(maxCollision, temp);
			}
		}

	for (auto it(m_hitbox.begin()); it != m_hitbox.end(); it++)
	{
		if (it->getId() != hb.getId() && hb.getId() != -1)
		{
			temp = areColliding(hb, *it);
			maxCollision = MAX(maxCollision, temp);
		}
	}

	return maxCollision;
}


// Return if the two hitbox are colliding
ManageHitbox::e_CollisionType ManageHitbox::areColliding(const Hitbox &hb1, const Hitbox &hb2)
{
	if (hb1.getX() < hb2.getX() + hb2.getWidth()
		&& hb1.getX() + hb1.getWidth() > hb2.getX()
		&& hb1.getY() < hb2.getY() + hb2.getHeight()
		&& hb1.getY() + hb1.getHeight() > hb2.getY())
		return ManageHitbox::e_CollisionType::COLLISION_HARD;

	return ManageHitbox::e_CollisionType::COLLISION_NONE;
}