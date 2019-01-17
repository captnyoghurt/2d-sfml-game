#pragma once

#include <string>
#include "Event/IG_Action.h"
#include "Game.h"

// Initiate everything in the program
int initialization();

// Initiate the global variables in the program
int initiate_constants(std::string filename);

// Initiate all the key event in the program
int initiate_events(std::string filename, Game &g);

int getCodeFromWord(std::string w);
IG_Action::s_action getActionFromWord(std::string w);