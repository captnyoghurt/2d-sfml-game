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

#include "MenuChoice.h"
#include "../Battle/Fighters/TeamBattle.h"

class MenuTeam :
	public MenuChoice
{
public:
	MenuTeam(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~MenuTeam();

public:
	/**
	* \brief Load the menu	.
	*
	* \return int object.
	*/
	virtual int load(const TeamBattle &tb, ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, const int &wchoice = 0, const int &hchoice = 0);

private:

};

