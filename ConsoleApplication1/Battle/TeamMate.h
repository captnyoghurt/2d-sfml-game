#pragma once

#include "Fighter.h"
#include "CharCourb.h"
#include "Spell.h"

class TeamMate : public Fighter
{
public:
	enum e_MateId {MATE_ID_CHAR1 = 0b00001, MATE_ID_CHAR2 = 0b00010, MATE_ID_CHAR3 = 0b00100, MATE_ID_CHAR4 = 0b01000, MATE_ID_CHAR5 = 0b10000, MATE_ID_ALL = 0b11111};

public:
	TeamMate();
	TeamMate(const TeamMate &tm);
	~TeamMate();

	TeamMate& operator=(const TeamMate &tm);
public:
	// Return the courbs
	std::vector<CharCourb> getCourbs() const;
	// Return the basic spells
	std::vector<std::pair<int, Spell> > getBasicSpells() const;
	// Return all the spells
	std::vector<Spell> getAllAvailableSpells() const;
	// Return the experience courb
	CharCourb getExpCourb() const;
	// Return the health courb
	CharCourb getHealthCourb() const;
	// Return the mana courb
	CharCourb getManaCourb() const;
	// Return the current experience
	int getExperience() const;
	// Return the current level
	int getLevel() const;

	// Return the courbs with modifying possibilities
	std::vector<CharCourb>& getRealCourb();
	// Return the basic spells with modifying possibilities
	std::vector<std::pair<int, Spell> >& getRealBasicSpells();

	// Modify the experience courb
	int setExpCourb(const CharCourb &exp);
	// Modify the health courb
	int setHealthCourb(const CharCourb &h);
	// Modify the mana courb
	int setManaCourb(const CharCourb &m);
	// Modify the current experience
	int setExperience(const int &experience);
	// Modify the current level
	int setLevel(const int &lvl);

	// Add some XP
	int addExperience(const int &exp);
	// Reload the TeamMate with the new courbs
	int reload(const bool &healing = false);

	// Take a decision for the next battle action
	virtual std::shared_ptr<B_Event> chooseEvent(Game *g);
	// True if the fighter is in reality a TeamMate
	virtual bool isTeamMate() const;

private:
	std::vector<CharCourb> m_courbs;
	std::vector<std::pair<int, Spell> > m_basicSpells;
	CharCourb m_expCourb;
	CharCourb m_healthCourb;
	CharCourb m_manaCourb;
	int m_experience;
	int m_level;
};

