/**
*  @file
*  @author  Paul Coignet
*  @date    12 / 11 / 2017
*  @version 0.1
*
*  @brief Class header.
*
*  @section DESCRIPTION
*
*  Menu to select team mate.
*
*/

#pragma once

#include <sstream>
#include "MenuChoice.h"
#include "../Battle/Fighters/TeamBattle.h"

class MenuTeam :
	public MenuChoice
{
public:
	enum e_MenuTeamType{MENU_TEAM_SPELLS, MENU_TEAM_CHAR, MENU_TEAM_ALL};

public:
	MenuTeam(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~MenuTeam();

public:
	/**
	* \brief Return the type of the menu team.
	*
	* \return e_MenuTeamType object
	*/
	e_MenuTeamType getType() const;

	/**
	* \brief Modify the type of the menu team.
	*
	* \return in object
	*/
	int getType(const e_MenuTeamType &type);

	/**
	* \brief Load the menu	.
	*
	* \return int object.
	*/
	virtual int load(const TeamBattle &tb, ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, const int &wchoice = 0, const int &hchoice = 0);

protected:
	/**
	* \brief Make the stringstream to load the team
	*  menu choice.
	* 
	* \return stringstream to load.
	*/
	std::stringstream makeChoicesSS(const TeamBattle &tb);
	/**
	* \brief Set the action to the real ones.
	* 
	* \return Code error.
	*/
	int setTrueActions(const TeamBattle &tb);

private:
	e_MenuTeamType m_type;
};

