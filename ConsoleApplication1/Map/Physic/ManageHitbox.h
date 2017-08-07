#pragma once

#include <map>
#include <memory>
#include <deque>
#include "Hitbox.h"

class ManageHitbox
{
public:
	enum e_CollisionType { COLLISION_NONE, COLLISION_WATER, COLLISION_HARD };

public:
	ManageHitbox();
	~ManageHitbox();

public:
	// Return the id counter
	int getIdCount() const;
	// Return the tile hitbox
	std::map< std::pair<int, int>, Hitbox > getTileHitbox() const;
	// Return the normal hitbox
	std::deque< Hitbox > getHitbox() const;

	// Return the tile hitbox with modifying possibilities
	std::map< std::pair<int, int>, Hitbox >& getRealTileHitbox();
	// Return the normal hitbox with modifying possibilities
	std::deque< Hitbox >& getRealHitbox();

	// Add a tile hitbox
	std::shared_ptr<Hitbox> addTileHitbox(const int &tx, const int &ty, const Hitbox& hb);
	// Add a hitbox
	std::shared_ptr<Hitbox> addHitbox(const Hitbox& hb, const int &id = -1);

	// Give the tile hitbox
	Hitbox& at(const int &tx, const int &ty);

	// Return the rect of tile where the hitbox is
	sf::Rect<int> rectTilePosition(const Hitbox &hb);
	// Return if the two hitbox are colliding
	e_CollisionType areColliding(const Hitbox &hb1, const Hitbox &hb2);

private:
	int m_idCount;
	std::map< std::pair<int, int>, Hitbox > m_tileHitbox;
	std::deque< Hitbox > m_hitbox;
};

