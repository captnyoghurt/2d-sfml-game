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

#include <sstream>
#include "MenuTeam.h"
#include "../constants.h"



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
	int ret = MenuChoice::loadFromStream(ress, surf, makeChoicesSS(tb), xcam, ycam, wchoice, hchoice);

	ret += (setTrueActions(tb) << 1);

	return ret;
}


//Make the stringstream to load the team menu choice.
std::stringstream MenuTeam::makeChoicesSS(const TeamBattle &tb)
{
	std::stringstream ss;

	ss << "AUTO\n" << MIN((signed)tb.getTeam().size(), MENU_TEAM_CHOICES_DISPLAYED) << " "
		<< MENU_TEAM_X << " " << MENU_TEAM_Y << " " << MENU_TEAM_WIDTH << " " << MENU_TEAM_HEIGHT << "\n";

	for (unsigned int i(0); i < tb.getTeam().size(); i++)
	{
		ss << "NOTHING\n" << tb.getTeam().at(i)->getName();

		if ((unsigned)(i + 1) < tb.getTeam().size())
			ss << "\n";
	}

	ss.seekg(0, ss.beg);
	return ss;
}


//Set the action to the real ones.
int MenuTeam::setTrueActions(const TeamBattle &tb)
{
	return 0;
}