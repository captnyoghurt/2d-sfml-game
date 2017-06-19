#pragma once

#include <list>
#include <memory>
#include "../Map/ManageSurfaces.h"
#include "../Map/Surface.h"

class Game;

class Character
{
public:
	Character();
	~Character();

public:
	// Return the abciss of the Character
	unsigned short getCombatX() const;
	// Return the y position of the Character
	unsigned short getCombatY() const;
	// Return the width of the Character
	short getCombatWidth() const;
	// Return the height of the Character
	short getCombatHeight() const;
	// Return the iterator of the combat stand surface of the character
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getCombatStand();

	// Return the iterator of the combat stand surface of the character with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealCombatStand();

	// Modify the abciss of the Character
	int setCombatX(const unsigned short &x);
	// Modify the y position of the Character
	int setCombatY(const unsigned short &y);
	// Modify the width of the Character
	int setCombatWidth(const short &w);
	// Modify the height of the Character
	int setCombatHeight(const short &h);

	// Load the surface of the combat stand
	int loadComnatStand(sf::Texture& t, Game &g);

public:
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_combatStand;
	unsigned short m_combatX;
	unsigned short m_combatY;
	short m_combatW;
	short m_combatH;

};

