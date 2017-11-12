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

// Spells
int af_menuSpellsOpen(Game &g, std::vector<Spell> sp);
int af_menuSpellsClose(Game &g);
int af_menuSpellUp(Game &g);
int af_menuSpellDown(Game &g);

// Inventory
int af_menuInventoryOpen(Game &g);
int af_menuInventoryClose(Game &g);
int af_menuInventoryUp(Game &g);
int af_menuInventoryDown(Game &g);

// Team Menu
int af_menuTeamOpen(Game &g);
int af_menuTeamClose(Game &g);

// Battle
/// General
int af_battleStart(Game &g);
int af_battleEnd(Game &g);

/// Menu Battle
int af_menuBattleDown(Game &g);
int af_menuBattleUp(Game &g);
int af_menuBattleRight(Game &g);
int af_menuBattleLeft(Game &g);
int af_menuBattleEnter(Game &g);

int af_menuBattleUseRight(Game &g);
int af_menuBattleUseLeft(Game &g);
int af_menuBattleUseDialogBox(Game &g);
int af_menuBattleUseChoice(Game &g);

/// Event battle
int af_battleEventCreateAttack(Game &g);