#include "Character.h"
#include "../constants.h"
#include "../Game.h"


Character::Character()
{
}


Character::~Character()
{
}


// Return the abciss of the Character
unsigned short Character::getCombatX() const
{
	return m_combatX;
}


// Return the y position of the Character
unsigned short Character::getCombatY() const
{
	return m_combatY;
}


// Return the width of the Character
short Character::getCombatWidth() const
{
	return m_combatW;
}


// Return the height of the Character
short Character::getCombatHeight() const
{
	return m_combatH;
}


// Return the iterator of the combat stand surface of the character
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator Character::getCombatStand()
{
	return m_combatStand;
}


// Return the iterator of the combat stand surface of the character with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& Character::getRealCombatStand()
{
	return m_combatStand;
}


// Modify the abciss of the Character
int Character::setCombatX(const unsigned short &x)
{
	m_combatX = x;

	return 0;
}


// Modify the y position of the Character
int Character::setCombatY(const unsigned short &y)
{
	m_combatY = y;

	return 0;
}


// Modify the width of the Character
int Character::setCombatWidth(const short &w)
{
	m_combatW = w;

	return 0;
}


// Modify the height of the Character
int Character::setCombatHeight(const short &h)
{
	m_combatH = h;

	return 0;
}


// Load the surface of the combat stand
int Character::loadComnatStand(sf::Texture& t, Game &g)
{
	m_combatStand = g.getRealSurfaceManager().at(MAP_MAX_LAYER + Game::e_ressourcesLayer::RESSOURCES_CHARACTERS - 1).addSurface(ManageSurfaces::e_thing::SPRITE, std::make_shared<SurfaceSprite>());
	std::dynamic_pointer_cast<SurfaceSprite>(m_combatStand->second)->setTexture(t);

	return 0;
}