#include "actionFunctions.h"
#include "../constants.h"
#include "../Menu/MenuChoice.h"
#include "../Menu/MenuDialogBox.h"
#include "../Menu/MenuBattle.h"
#include "../Battle/B_EventAttack.h"

int af_exit(Game &g)
{
	g.exit();

	return 1;
}


// Camera movement
int af_camUp(Game &g)
{
	g.getRealMap().gotUpdated();
	return g.getRealMap().getRealCamera().move(0, -CAMERA_MOVING_Y);
}

int af_camDown(Game &g)
{
	g.getRealMap().gotUpdated();
	return g.getRealMap().getRealCamera().move(0, CAMERA_MOVING_Y);
}

int af_camLeft(Game &g)
{
	g.getRealMap().gotUpdated();
	return g.getRealMap().getRealCamera().move(-CAMERA_MOVING_X, 0);
}

int af_camRight(Game &g)
{
	g.getRealMap().gotUpdated();
	return g.getRealMap().getRealCamera().move(CAMERA_MOVING_X, 0);
}


// Team movement
int af_teamUp(Game &g)
{
	g.getRealMap().gotUpdated();
	return g.getRealTeam().move(0, -TEAM_MOVING_NORMAL_SPEED_Y, Team::e_teamDirection::UP);
}

int af_teamDown(Game &g)
{
	g.getRealMap().gotUpdated();
	return g.getRealTeam().move(0, TEAM_MOVING_NORMAL_SPEED_Y, Team::e_teamDirection::DOWN);
}

int af_teamLeft(Game &g)
{
	g.getRealMap().gotUpdated();
	return g.getRealTeam().move(-TEAM_MOVING_NORMAL_SPEED_X, 0, Team::e_teamDirection::LEFT);
}
//#include <iostream>
int af_teamRight(Game &g)
{
	g.getRealMap().gotUpdated();
	//std::cout << "\t\tRight pressed\n";
	return g.getRealTeam().move(TEAM_MOVING_NORMAL_SPEED_X, 0, Team::e_teamDirection::RIGHT);
}

int af_teamStop(Game &g)
{
	return g.getRealTeam().stopMoving();
}

int af_teamStopUp(Game &g)
{
	return g.getRealTeam().stopMoving(Team::UP);
}

int af_teamStopDown(Game &g)
{
	return g.getRealTeam().stopMoving(Team::DOWN);
}

int af_teamStopRight(Game &g)
{
	return g.getRealTeam().stopMoving(Team::RIGHT);
}

int af_teamStopLeft(Game &g)
{
	return g.getRealTeam().stopMoving(Team::LEFT);
}


// Menu changement
int af_menuOpenSimple(Game &g)
{
	g.getRealMap().gotUpdated();
	af_teamStop(g);
	g.getRealMenus().push_back(std::make_shared<MenuChoice>(g.getRealRessourceManager().at(Game::e_ressourcesLayer::RESSOURCES_MENU), g.getRealSurfaceManager(MENU_SIMPLE_LAYER), g.getEventManager().getKeyEventLayer()));
	g.getRealEventManager().setKeyEventLayer(1);
	
	return std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back())->load(g.getRealRessourceManager().at(Game::e_ressourcesLayer::RESSOURCES_MENU), g.getRealSurfaceManager(MENU_SIMPLE_LAYER), MENU_SIMPLE_TEXT, g.getMap().getCamera().getX(), g.getMap().getCamera().getY());
}

int af_menuCloseSimple(Game &g)
{
	g.getRealMap().gotUpdated();
	//std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back())->close(g.getRealSurfaceManager().at(MENU_SIMPLE_LAYER));
	return g.stopMenu();
}


int af_menuChoiceUp(Game &g)
{
	if (g.getRealMenus().size() == 0)
		return -1;
	int ret = std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back())->setSelectedChoice(std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back())->getSelectedChoice() - 1);
	if (ret > 0)
		g.getRealMap().gotUpdated();
	return 0;
}

int af_menuChoiceDown(Game &g)
{
	if (g.getRealMenus().size() == 0)
		return -1;
	int ret = std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back())->setSelectedChoice(std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back())->getSelectedChoice() + 1);
	if (ret > 0)
		g.getRealMap().gotUpdated();
	return 0;
}

int af_menuChoiceAction(Game &g)
{
	if (g.getRealMenus().size() == 0)
		return -1;
	/*int i = ;
	std::shared_ptr<MenuChoice> m(std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back()));
	M_choice *mc((std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back()))->getChoices().at(std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back())->getSelectedChoice()));*/
	return (std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back()))->getChoices().at(std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back())->getSelectedChoice())->getAction().getAction()(g);
}


// Bag
int af_bagOpenComplete(Game &g)
{
	g.getRealMap().gotUpdated();
	af_teamStop(g);
	g.getRealMenus().push_back(std::shared_ptr<MenuChoice>(new MenuChoice(g.getRealRessourceManager().at(Game::e_ressourcesLayer::RESSOURCES_MENU), g.getRealSurfaceManager(MENU_BAG_LAYER), g.getEventManager().getKeyEventLayer())));
	g.getRealEventManager().setKeyEventLayer(1);

	return std::dynamic_pointer_cast<MenuChoice>(g.getRealMenus().back())->load(g.getRealRessourceManager().at(Game::e_ressourcesLayer::RESSOURCES_MENU), g.getRealSurfaceManager(MENU_BAG_LAYER), MENU_BAG_TEXT, g.getMap().getCamera().getX(), g.getMap().getCamera().getY());
}


// DialogBox
int af_dialogBoxOpen(Game &g)
{
	g.getRealMap().gotUpdated();
	af_teamStop(g);
	g.getRealMenus().push_back(std::shared_ptr<MenuDialogBox>(new MenuDialogBox(g.getRealRessourceManager().at(Game::e_ressourcesLayer::RESSOURCES_MENU), g.getRealSurfaceManager(MENU_DIALOG_BOX_LAYER), g.getEventManager().getKeyEventLayer())));
	g.getRealEventManager().setKeyEventLayer(2);

	return std::dynamic_pointer_cast<MenuDialogBox>(g.getRealMenus().back())->load(g.getRealRessourceManager().at(Game::e_ressourcesLayer::RESSOURCES_MENU), g.getRealSurfaceManager(MENU_DIALOG_BOX_LAYER), "Test this stupid dialog box.\\  And try to switch line or so\\And a new line\\This line is a veeeeeeeeeeeeeery long one because i need to put it on two lines so there is a lot of words there and most of them are useless\\Not the last\\And a last one", g.getMap().getCamera().getX(), g.getMap().getCamera().getY());
}

int af_dialogBoxContinue(Game &g)
{
	if (g.getRealMenus().size() == 0)
		return -1;

	g.getRealMap().gotUpdated();

	int ret = std::dynamic_pointer_cast<MenuDialogBox>(g.getRealMenus().back())->continueText(g.getRealRessourceManager().at(Game::e_ressourcesLayer::RESSOURCES_MENU), g.getRealSurfaceManager(MENU_DIALOG_BOX_LAYER));
	
	if (ret != 0)
		return af_menuCloseSimple(g);

	return ret;
}


// Battle
/// General
int af_battleStart(Game &g)
{
	af_teamStop(g);

	g.getRealBattle().start("data/graphic/battleback/001-grl01.jpg", TeamBattle(), "", &g);
	
	g.getRealEventManager().setKeyEventLayer(BATTLE_KEY_EVENT_LAYER);

	return 0;
}

int af_battleEnd(Game &g)
{
	// [TODO]

	g.getRealEventManager().setKeyEventLayer(0);

	g.getRealMap().gotUpdated();

	return g.getRealBattle().end(&g);
}


/// Menu Battle
int af_menuBattleDown(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;
	return g.getRealBattle().getRealBattleMenu().af_MenuBattleDown(g);
}

int af_menuBattleUp(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;
	return g.getRealBattle().getRealBattleMenu().af_MenuBattleUp(g);
}

int af_menuBattleRight(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;
	return g.getRealBattle().getRealBattleMenu().af_MenuBattleRight(g);
}

int af_menuBattleLeft(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;
	return g.getRealBattle().getRealBattleMenu().af_MenuBattleLeft(g);
}

int af_menuBattleEnter(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;
	return g.getRealBattle().getRealBattleMenu().af_MenuBattleEnter(g);
}


int af_menuBattleUseRight(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;

	return g.getRealBattle().getRealBattleMenu().setActiveMenu(MenuBattle::BM_RIGHT);
}

int af_menuBattleUseLeft(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;
	return g.getRealBattle().getRealBattleMenu().setActiveMenu(MenuBattle::BM_LEFT);
}

int af_menuBattleUseDialogBox(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;
	return g.getRealBattle().getRealBattleMenu().setActiveMenu(MenuBattle::BM_DIALOG);
}

int af_menuBattleUseChoice(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;
	return g.getRealBattle().getRealBattleMenu().setActiveMenu(MenuBattle::BM_CHOICE);
}


/// Event battle
int af_battleEventCreateAttack(Game &g)
{
	if (!g.getRealBattle().getStarted())
		return -1;

	return g.getRealBattle().getRealBattleEventManager().createEvent(
		g.getRealBattle().getRealBattleOrder().at(g.getRealBattle().getBattleEventCreated() - 1),
		std::make_shared<B_EventAttack>(B_EventAttack(g.getRealBattle().getRealBattleOrder().at(g.getRealBattle().getBattleEventCreated() - 1)->getName() + " attaque")),
		g
	);
}