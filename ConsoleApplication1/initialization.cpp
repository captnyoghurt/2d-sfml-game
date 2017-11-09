#include <fstream>
#include <sstream>
#include <iostream>
#include "Event\actionFunctions.h"
#include "constants.h"
#include "Game.h"
#include "Event\IG_Action.h"
#include "initialization.h"
#include "Error\RessourceException.h"
#include "Error\ValueException.h"

// Initiate everything in the program
int initialization()
{
	int ret = 0;

	try
	{
		ret = initiate_constants("param.conf");
	}
	catch (GameException &e)
	{
		if (e.getLevel() > 1)
		{
			e.append("During initialization");
			throw e;
		}
		else
		{
			e.append("Didn't stop the process");
			e.what();
		}
	}

	return ret;
}


// Initiate the global variables in the program
int initiate_constants(std::string filename)
{
	std::ifstream file(filename);
	std::string line, word;

	if (!file.is_open())
		THROW_RESSOURCE("Constant file", filename);

	while (std::getline(file, line))
	{
		if (line.size() > 0 && line[0] != '#')
		{
			std::istringstream iss(line);
			int value;

			iss >> word;
				
			if (word == "WINDOW_WIDTH")
			{
				iss >> value;
				WINDOW_WIDTH = ((value > 0) ? value : WINDOW_WIDTH);
			}
			else if (word == "WINDOW_HEIGHT")
			{
				iss >> value;
				WINDOW_HEIGHT = ((value > 0) ? value : WINDOW_HEIGHT);
			}
			else if (word == "WINDOW_X")
			{
				iss >> value;
				WINDOW_X = ((value >= 0) ? value : WINDOW_X);
			}
			else if (word == "WINDOW_Y")
			{
				iss >> value;
				WINDOW_Y = ((value >= 0) ? value : WINDOW_Y);
			}
			else if (word == "WINDOW_SLEEPTIME")
			{
				iss >> value;
				WINDOW_SLEEPTIME = ((value >= 0) ? value : WINDOW_SLEEPTIME);
			}
			else if (word == "WINDOW_FRAMERATES")
			{
				iss >> value;
				WINDOW_FRAMERATES = ((value >= 0) ? value : WINDOW_FRAMERATES);
			}
			else if (word == "MAP_FONT_TEXT")
			{
				iss >> word;
				MAP_FONT_TEXT = word;
			}
			else if (word == "MAP_MAX_LAYER")
			{
				iss >> value;
				MAP_MAX_LAYER = ((value >= 0) ? value : MAP_MAX_LAYER);
			}
			else if (word == "TILE_WIDTH")
			{
				iss >> value;
				TILE_WIDTH = ((value >= 0) ? value : TILE_WIDTH);
			}
			else if (word == "TILE_HEIGHT")
			{
				iss >> value;
				TILE_HEIGHT = ((value >= 0) ? value : TILE_HEIGHT);
			}
			else if (word == "CAMERA_WIDTH")
			{
				iss >> value;
				CAMERA_WIDTH = ((value >= 0) ? value : CAMERA_WIDTH);
			}
			else if (word == "CAMERA_HEIGHT")
			{
				iss >> value;
				CAMERA_HEIGHT = ((value >= 0) ? value : CAMERA_HEIGHT);
			}
			else if (word == "CAMERA_MOVING_X")
			{
				iss >> value;
				CAMERA_MOVING_X = ((value >= 0) ? value : CAMERA_MOVING_X);
			}
			else if (word == "CAMERA_MOVING_Y")
			{
				iss >> value;
				CAMERA_MOVING_Y = ((value >= 0) ? value : CAMERA_MOVING_Y);
			}
			else if (word == "TEAM_MOVING_X")
			{
				iss >> value;
				TEAM_MOVING_X = ((value >= 0) ? value : TEAM_MOVING_X);
			}
			else if (word == "TEAM_MOVING_Y")
			{
				iss >> value;
				TEAM_MOVING_Y = ((value >= 0) ? value : TEAM_MOVING_Y);
			}
			else if (word == "ANIMATION_REFRESHING")
			{
				iss >> value;
				ANIMATION_REFRESHING = ((value >= 0) ? value : ANIMATION_REFRESHING);
			}
			else if (word == "ANIMATION_NB_LAYER")
			{
				iss >> value;
				ANIMATION_NB_LAYER = ((value >= 0) ? value : ANIMATION_NB_LAYER);
			}
			else if (word == "TEAM_BASIC_WALKSTAND")
			{
				iss >> word;
				TEAM_BASIC_WALKSTAND = word;
			}
			else if (word == "TEAM_WALK_ANIMATION_REFRESH")
			{
				iss >> value;
				TEAM_WALK_ANIMATION_REFRESH = ((value >= 0) ? value : TEAM_WALK_ANIMATION_REFRESH);
			}
			else if (word == "TEAM_WALK_WIDTH")
			{
				iss >> value;
				TEAM_WALK_WIDTH = ((value >= 0) ? value : TEAM_WALK_WIDTH);
			}
			else if (word == "TEAM_WALK_HEIGHT")
			{
				iss >> value;
				TEAM_WALK_HEIGHT = ((value >= 0) ? value : TEAM_WALK_HEIGHT);
			}
			else if (word == "TEAM_WALK_FRAME_NUMBER")
			{
				iss >> value;
				TEAM_WALK_FRAME_NUMBER = ((value >= 0) ? value : TEAM_WALK_FRAME_NUMBER);
			}
			else if (word == "TEAM_WALK_UP_POSITION_Y")
			{
				iss >> value;
				TEAM_WALK_UP_POSITION_Y = ((value >= 0) ? value : TEAM_WALK_UP_POSITION_Y);
			}
			else if (word == "TEAM_WALK_DOWN_POSITION_Y")
			{
				iss >> value;
				TEAM_WALK_DOWN_POSITION_Y = ((value >= 0) ? value : TEAM_WALK_DOWN_POSITION_Y);
			}
			else if (word == "TEAM_WALK_RIGHT_POSITION_Y")
			{
				iss >> value;
				TEAM_WALK_RIGHT_POSITION_Y = ((value >= 0) ? value : TEAM_WALK_RIGHT_POSITION_Y);
			}
			else if (word == "TEAM_WALK_LEFT_POSITION_Y")
			{
				iss >> value;
				TEAM_WALK_LEFT_POSITION_Y = ((value >= 0) ? value : TEAM_WALK_LEFT_POSITION_Y);
			}
			else if (word == "TEAM_WALK_LAYER")
			{
				iss >> value;
				TEAM_WALK_LAYER = ((value >= 0) ? value : TEAM_WALK_LAYER);
			}
			else
			{
				THROW_VALUE("Unknown constant " + word)
			}
		}
	}

	return 0;
}


// Initiate all the key event in the program
int initiate_events(std::string filename, Game &g)
{
	std::ifstream file(filename);
	std::string line, word;
	int nb, pressed;

	if (!file.is_open())
		THROW_RESSOURCE("Events file", filename);

	file >> nb;

	if (nb <= 0)
		THROW_VALUE("Number of event layer incorrect");

	g.getRealEventManager().createLayers(nb);

	while (std::getline(file, line))
	{
		if (line.size() > 0 && line[0] != '#')
		{
			std::istringstream iss(line);
			int layer;

			iss >> layer;
			iss >> pressed;

			if ((unsigned)layer < (unsigned)nb)
			{
				int code(0);
				if (iss >> word)
					code = getCodeFromWord(word);
				if (iss >> word)
				{
					if (word == "new")
					{
						iss >> word;
						IG_Action::s_action act = getActionFromWord(word);
						g.getRealEventManager().setKeyEvent(layer, code, g.getRealEventManager().createMatchingKey(IG_Action(act)), (pressed == 1) ? true : false);
					}
					else
					{
						g.getRealEventManager().setKeyEvent(layer, code, std::stoi(word));
					}
				}
			}
			else
			{
				THROW_VALUE("Impossible value of layer event : " + std::to_string(layer));
			}
		}
	}

	return 0;
}

int getCodeFromWord(std::string w)
{
	if (w == "A")
		return sf::Keyboard::Key::A;
	else if (w == "B")
		return sf::Keyboard::Key::B;
	else if (w == "C")
		return sf::Keyboard::Key::C;
	else if (w == "D")
		return sf::Keyboard::Key::D;
	else if (w == "E")
		return sf::Keyboard::Key::E;
	else if (w == "F")
		return sf::Keyboard::Key::F;
	else if (w == "G")
		return sf::Keyboard::Key::G;
	else if (w == "H")
		return sf::Keyboard::Key::H;
	else if (w == "I")
		return sf::Keyboard::Key::I;
	else if (w == "J")
		return sf::Keyboard::Key::J;
	else if (w == "K")
		return sf::Keyboard::Key::K;
	else if (w == "L")
		return sf::Keyboard::Key::L;
	else if (w == "M")
		return sf::Keyboard::Key::M;
	else if (w == "N")
		return sf::Keyboard::Key::N;
	else if (w == "O")
		return sf::Keyboard::Key::O;
	else if (w == "P")
		return sf::Keyboard::Key::P;
	else if (w == "Q")
		return sf::Keyboard::Key::Q;
	else if (w == "R")
		return sf::Keyboard::Key::R;
	else if (w == "S")
		return sf::Keyboard::Key::S;
	else if (w == "T")
		return sf::Keyboard::Key::T;
	else if (w == "U")
		return sf::Keyboard::Key::U;
	else if (w == "V")
		return sf::Keyboard::Key::V;
	else if (w == "W")
		return sf::Keyboard::Key::W;
	else if (w == "X")
		return sf::Keyboard::Key::X;
	else if (w == "Y")
		return sf::Keyboard::Key::Y;
	else if (w == "Z")
		return sf::Keyboard::Key::Z;

	else if (w == "DOWN")
		return sf::Keyboard::Key::Down;
	else if (w == "UP")
		return sf::Keyboard::Key::Up;
	else if (w == "LEFT")
		return sf::Keyboard::Key::Left;
	else if (w == "RIGHT")
		return sf::Keyboard::Key::Right;

	else if (w == "ESC")
		return sf::Keyboard::Key::Escape;
	else if (w == "ENTER")
		return sf::Keyboard::Key::Return;

	else
		THROW_VALUE(std::string("Unknown key : " + w));

	return 0;
}

IG_Action::s_action getActionFromWord(std::string w)
{
	if (w == "NOTHING")
		return &doNothing;
	else if (w == "EXIT")
		return &af_exit;
	else if (w == "CAMERA_DOWN")
		return &af_camDown;
	else if (w == "CAMERA_UP")
		return &af_camUp;
	else if (w == "CAMERA_RIGHT")
		return &af_camRight;
	else if (w == "CAMERA_LEFT")
		return &af_camLeft;
	else if (w == "TEAM_DOWN")
		return &af_teamDown;
	else if (w == "TEAM_UP")
		return &af_teamUp;
	else if (w == "TEAM_RIGHT")
		return &af_teamRight;
	else if (w == "TEAM_LEFT")
		return &af_teamLeft;
	else if (w == "TEAM_STOP_DOWN")
		return &af_teamStopDown;
	else if (w == "TEAM_STOP_UP")
		return &af_teamStopUp;
	else if (w == "TEAM_STOP_RIGHT")
		return &af_teamStopRight;
	else if (w == "TEAM_STOP_LEFT")
		return &af_teamStopLeft;
	else if (w == "MENU_OPEN_SIMPLE")
		return &af_menuOpenSimple;
	else if (w == "MENU_CLOSE_SIMPLE")
		return &af_menuCloseSimple;
	else if (w == "MENU_CHOICE_UP")
		return &af_menuChoiceUp;
	else if (w == "MENU_CHOICE_DOWN")
		return &af_menuChoiceDown;
	else if (w == "MENU_CHOICE_ACTION")
		return &af_menuChoiceAction;
	else if (w == "BAG_OPEN_COMPLETE")
		return &af_bagOpenComplete;
	else if (w == "DIALOG_BOX_OPEN")
		return &af_dialogBoxOpen;
	else if (w == "DIALOG_BOX_CONTINUE")
		return &af_dialogBoxContinue;
	else if (w == "BATTLE_START")
		return &af_battleStart;
	else if (w == "BATTLE_END")
		return &af_battleEnd;
	else if (w == "MENU_BATTLE_DOWN")
		return &af_menuBattleDown;
	else if (w == "MENU_BATTLE_UP")
		return &af_menuBattleUp;
	else if (w == "MENU_BATTLE_RIGHT")
		return &af_menuBattleRight;
	else if (w == "MENU_BATTLE_LEFT")
		return &af_menuBattleLeft;
	else if (w == "MENU_BATTLE_ENTER")
		return &af_menuBattleEnter;
	else if (w == "MENU_BATTLE_USE_RIGHT")
		return &af_menuBattleUseRight;
	else if (w == "MENU_BATTLE_USE_LEFT")
		return &af_menuBattleUseLeft;
	else if (w == "MENU_BATTLE_USE_DIALOG_BOX")
		return &af_menuBattleUseDialogBox;
	else if (w == "MENU_BATTLE_USE_CHOICE")
		return &af_menuBattleUseChoice;
	else if (w == "BATTLE_EVENT_CREATE_ATTACK")
		return &af_battleEventCreateAttack;
	else if (w == "MENU_SPELLS_OPEN")
		return &af_menuSpellsOpen;
	else if (w == "MENU_SPELLS_CLOSE")
		return &af_menuSpellsClose;
	else if (w == "MENU_SPELLS_DOWN")
		return &af_menuSpellDown;
	else if (w == "MENU_SPELLS_UP")
		return &af_menuSpellUp;
	else if (w == "MENU_INVENTORY_OPEN")
		return &af_menuInventoryOpen;
	else if (w == "MENU_INVENTORY_CLOSE")
		return &af_menuInventoryClose;
	else if (w == "MENU_INVENTORY_DOWN")
		return &af_menuInventoryDown;
	else if (w == "MENU_INVENTORY_UP")
		return &af_menuInventoryUp;

	else
		THROW_VALUE(std::string("Unknown action : " + w));

	return &doNothing;
}