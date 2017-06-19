#include "Battle.h"
#include "Fighter.h"



Fighter::Fighter()
{
}


Fighter::~Fighter()
{
}


// Return health
Health Fighter::getHealth() const
{
	return m_health;
}


// Return mana
Mana Fighter::getMana() const
{
	return m_mana;
}


// Return skill points
SkillPoints Fighter::getSkillPoints() const
{
	return m_skillPoints;
}


// Return all the characteristics
std::vector<Characteristic> Fighter::getCharacteristics() const
{
	return m_characteristics;
}


// Return the surface
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator Fighter::getSurface()
{
	return m_surface;
}


// Return health with modifying possibilities
Health& Fighter::getRealHealth()
{
	return m_health;
}


// Return mana with modifying possibilities
Mana& Fighter::getRealMana()
{
	return m_mana;
}


// Return skill points with modifying possibilities
SkillPoints& Fighter::getRealSkillPoints()
{
	return m_skillPoints;
}


// Return all the characteristics with modifying possibilities
std::vector<Characteristic>& Fighter::getRealCharacteristics()
{
	return m_characteristics;
}


// Return the surface with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& Fighter::getRealSurface()
{
	return m_surface;
}


// Modify health
int Fighter::setHealth(const Health &h)
{
	m_health.setMaxPoints(h.getMaxPoints());
	m_health.setPoints(h.getPoints());

	return 0;
}


// Modify mana
int Fighter::setMana(const Mana &m)
{
	m_mana.setMaxPoints(m.getMaxPoints());
	m_mana.setPoints(m.getPoints());

	return 0;
}


// Modify skill points
int Fighter::setSkillPoints(const SkillPoints &skp)
{
	m_skillPoints.setMaxPoints(skp.getMaxPoints());
	m_skillPoints.setPoints(skp.getPoints());

	return 0;

}


// Modify a characteristic
int Fighter::setCharacteristic(const Characteristic &ch, int n)
{
	if (n < 0 || n >= m_characteristics.size())
		return -1;

	m_characteristics.at(n).setMaxPoints(ch.getMaxPoints());
	m_characteristics.at(n).setPoints(ch.getPoints());

	return 0;
}


// Modify the surface
int Fighter::setSurface(std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator it)
{
	m_surface = it;

	return 0;
}


// Make the fighter do an action for the next turn
int Fighter::doAction(B_Event evt)
{
	// [TODO]
	// Add the event to the battle historic

	return 0;
}


// True if the fighter is dead (== 0 HP)
bool Fighter::isDead() const
{
	return (m_health.getPoints() <= 0);
}


// Change stance & possibilities
int Fighter::switchToDead()
{
	m_surface->second->setEnable(false);

	return 0;
}
int Fighter::switchToAlive()
{
	m_surface->second->setEnable(true);

	return 0;
}