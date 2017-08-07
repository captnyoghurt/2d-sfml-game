#include "ManageHitbox.h"
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