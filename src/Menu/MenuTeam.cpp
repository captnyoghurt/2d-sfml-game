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
#include "../Error/ValueException.h"



MenuTeam::MenuTeam(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer) :
	MenuChoice(ress, surf, lastEventLayer),
	m_type(MenuTeam::e_MenuTeamType::MENU_TEAM_SPELLS)
{
}


MenuTeam::~MenuTeam()
{
}


// Return the type of the menu team.
MenuTeam::e_MenuTeamType MenuTeam::getType() const
{
	return m_type;
}



// Modify the type of the menu team.
int MenuTeam::getType(const e_MenuTeamType &type)
{
	if (type >= 0 && type < e_MenuTeamType::MENU_TEAM_ALL)
	{
		m_type = type;
		return 0;
	}

	THROW_VALUE("Wrong MenuTeamType : " + std::to_string(type));

	return -1;
}


//brief Load the menu
int MenuTeam::load(const e_MenuTeamType &type, TeamBattle &tb, ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, const int &wchoice, const int &hchoice)
{
	if (tb.getTeam().empty())
	{
		THROW_VALUE("No team mate");
		return -1;
	}

	int ret = MenuChoice::loadFromStream(ress, surf, makeChoicesSS(tb), xcam, ycam, wchoice, hchoice);

	getType(type);

	ret += (setTrueActions(tb) << 1);

	return ret;
}


//Make the stringstream to load the team menu choice.
std::stringstream MenuTeam::makeChoicesSS(TeamBattle &tb)
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
int MenuTeam::setTrueActions(TeamBattle &tb)
{
	for (unsigned int i(0); i < tb.getRealTeam().size(); i++)
	{
		switch (m_type)
		{
		case MenuTeam::MENU_TEAM_SPELLS:
			this->getChoices().at(i)->setAction(IG_Action(
				std::bind(&af_openMenuSpells, *tb.getRealTeam().at(i), std::placeholders::_1)
			));
			break;
		case MenuTeam::MENU_TEAM_CHAR:
			THROW_VALUE("Not implemented yet");
			break;
		case MenuTeam::MENU_TEAM_ALL:
		default:
			THROW_VALUE("Unknown type of MenuTeam" + std::to_string(m_type));
			break;
		}
	}

	return 0;
}