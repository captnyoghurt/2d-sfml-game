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

#include "MenuTeam.h"
#include <sstream>



MenuTeam::MenuTeam(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer) :
	MenuChoice(ress, surf, lastEventLayer)
{
}


MenuTeam::~MenuTeam()
{
}


//brief Load the menu
int MenuTeam::load(const TeamBattle &tb, ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, const int &wchoice, const int &hchoice)
{
	std::stringstream ss;
	return MenuChoice::loadFromStream(ress, surf, ss, xcam, ycam, wchoice, hchoice);
}