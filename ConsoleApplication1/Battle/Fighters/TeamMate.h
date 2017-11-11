/**
*  @file
*  @author  Paul Coignet
*  @date    11 / 11 / 2017
*  @version 0.1
*
*  @brief Class header.
*
*  @section DESCRIPTION
*
*  An ally of the group.
*
*/

#pragma once

#include "Fighter.h"
#include "../Status/CharCourb.h"
#include "../Status/Spell.h"

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
	/**
	* \brief Return the courbs	.
	*
	* \return std::vector<CharCourb> object.
	*/
	std::vector<CharCourb> getCourbs() const;
	/**
	* \brief Return the basic spells	.
	*
	* \return std::vector<std::pair<int, object.
	*/
	std::vector<std::pair<int, Spell> > getBasicSpells() const;
	/**
	* \brief Return all the spells	.
	*
	* \return std::vector<Spell> object.
	*/
	std::vector<Spell> getAllAvailableSpells() const;
	/**
	* \brief Return the experience courb	.
	*
	* \return CharCourb object.
	*/
	CharCourb getExpCourb() const;
	/**
	* \brief Return the health courb	.
	*
	* \return CharCourb object.
	*/
	CharCourb getHealthCourb() const;
	/**
	* \brief Return the mana courb	.
	*
	* \return CharCourb object.
	*/
	CharCourb getManaCourb() const;
	/**
	* \brief Return the current experience	.
	*
	* \return int object.
	*/
	int getExperience() const;
	/**
	* \brief Return the current level	.
	*
	* \return int object.
	*/
	int getLevel() const;

	/**
	* \brief Return the courbs with modifying possibilities	.
	*
	* \return std::vector<CharCourb>& object.
	*/
	std::vector<CharCourb>& getRealCourb();
	/**
	* \brief Return the basic spells with modifying possibilities	.
	*
	* \return std::vector<std::pair<int, object.
	*/
	std::vector<std::pair<int, Spell> >& getRealBasicSpells();

	/**
	* \brief Modify the experience courb	.
	*
	* \param exp The new value.
	* \return int object.
	*/
	int setExpCourb(const CharCourb &exp);
	/**
	* \brief Modify the health courb	.
	*
	* \param h The new value.
	* \return int object.
	*/
	int setHealthCourb(const CharCourb &h);
	/**
	* \brief Modify the mana courb	.
	*
	* \param m The new value.
	* \return int object.
	*/
	int setManaCourb(const CharCourb &m);
	/**
	* \brief Modify the current experience	.
	*
	* \param experience The new value.
	* \return int object.
	*/
	int setExperience(const int &experience);
	/**
	* \brief Modify the current level	.
	*
	* \param lvl The new value.
	* \return int object.
	*/
	int setLevel(const int &lvl);

	/**
	* \brief Add some XP	.
	*
	* \return int object.
	*/
	int addExperience(const int &exp);
	/**
	* \brief Reload the TeamMate with the new courbs	.
	*
	* \return int object.
	*/
	int reload(const bool &healing = false);

	/**
	* \brief Take a decision for the next battle action	.
	*
	* \return virtual object.
	*/
	virtual std::shared_ptr<B_Event> chooseEvent(Game *g);
	/**
	* \brief True if the fighter is in reality a TeamMate	.
	*
	* \return virtual object.
	*/
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
