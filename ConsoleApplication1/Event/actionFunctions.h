#pragma once

#include "../Game.h"

int af_exit(Game &g);

// Camera movement
int af_camUp(Game &g);
int af_camDown(Game &g);
int af_camLeft(Game &g);
int af_camRight(Game &g);

// Team movement
int af_teamUp(Game &g);
int af_teamDown(Game &g);
int af_teamLeft(Game &g);
int af_teamRight(Game &g);

int af_teamStop(Game &g);

int af_teamStopUp(Game &g);
int af_teamStopDown(Game &g);
int af_teamStopRight(Game &g);
int af_teamStopLeft(Game &g);

// Menu changement
int af_menuOpenSimple(Game &g);
int af_menuCloseSimple(Game &g);

int af_menuChoiceUp(Game &g);
int af_menuChoiceDown(Game &g);
int af_menuChoiceAction(Game &g);

// Bag
int af_bagOpenComplete(Game &g);

// DialogBox
int af_dialogBoxOpen(Game &g);
int af_dialogBoxContinue(Game &g);

// Battle
int af_battleStart(Game &g);
int af_battleEnd(Game &g);
int af_menuBattleDown(Game &g);
int af_menuBattleUp(Game &g);
int af_menuBattleRight(Game &g);
int af_menuBattleLeft(Game &g);
int af_menuBattleEnter(Game &g);