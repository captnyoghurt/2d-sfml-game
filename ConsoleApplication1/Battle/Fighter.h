#pragma once


#include <vector>
#include "Health.h"
#include "Characteristic.h"
#include "../Map/ManageSurfaces.h"
#include "Mana.h"
#include "SkillPoints.h"
#include "Spell.h"

class Battle;
class B_Event;

class Fighter
{
public:
	Fighter();
	~Fighter();

public:
	// Return the name
	std::string getName() const;
	// Return health
	Health getHealth() const;
	// Return mana
	Mana getMana() const;
	// Return skill points
	SkillPoints getSkillPoints() const;
	// Return all the characteristics
	std::vector<Characteristic> getCharacteristics() const;
	// Return the surface
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getSurface();

	// Return health with modifying possibilities
	Health& getRealHealth();
	// Return mana with modifying possibilities
	Mana& getRealMana();
	// Return skill points with modifying possibilities
	SkillPoints& getRealSkillPoints();
	// Return all the characteristics with modifying possibilities
	std::vector<Characteristic>& getRealCharacteristics();
	// Return the surface with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealSurface();

	// Modify the name
	int setName(const std::string &name);
	// Modify health
	int setHealth(const Health &h);
	// Modify mana
	int setMana(const Mana &m);
	// Modify skill points
	int setSkillPoints(const SkillPoints &skp);
	// Modify a characteristic
	int setCharacteristic(const Characteristic &ch, int n);
	// Modify the surface
	int setSurface(std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator it);

	// Make the fighter do an action for the next turn
	int doAction(std::shared_ptr<B_Event> evt);
	// True if the fighter is dead (== 0 HP)
	bool isDead() const;
	// Change stance & possibilities
	int switchToDead();
	int switchToAlive();

protected:
	std::string m_name;
	Health m_health;
	Mana m_mana;
	SkillPoints m_skillPoints;
	std::vector<Characteristic> m_characteristics;
	std::vector<Spell> m_spells;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_surface;
};

