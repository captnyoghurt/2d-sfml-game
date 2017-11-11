/**
*  @file
*  @author  Paul Coignet
*  @date    11 / 11 / 2017
*  @version 0.1
*
*  @brief Class header.
*
*  @section DESCRIPTION
*
*  Describe the battle and execute the different turn.
*
*/

#include <iostream>
#include "Battle.h"
#include "Fighters/EnemiBasic.h"
#include "../Map/ManageRessources.h"
#include "../Map/ManageSurfaces.h"
#include "../constants.h"
#include "../Menu/MenuBattle.h"
#include "../Game.h"
#include "../Menu/MenuBattleSide.h"
#include "../Menu/MenuDialogBox.h"
#include "../Error/InitializationException.h"
#include "../Error/ValueException.h"


Battle::Battle(TeamBattle &tb)
{
	m_updated = true;
	m_started = false;
	m_inTurn = false;
	m_choicesFinished = false;
	m_shown = true;
	m_battleExit = Battle::e_BattleExit::BATTLE_EXIT_TOTAL;
	m_battleTurn = 0;
	m_lastKeyEventLayer = 0;
	m_battleEventCreated = 0;
	
	// Team
	m_alliesTeam = &tb;
}


Battle::~Battle()
{
	//m_battleMenu.reset();
}


// Return if the battle has started
bool Battle::getStarted() const
{
	return m_started;
}


// Return if the turn has begun
bool Battle::getInTurn() const
{
	return m_inTurn;
}


// Return if the choices for the turn has been made
bool Battle::getChoicesFinished() const
{
	return m_choicesFinished;
}


// Return if the battle is shown
bool Battle::getShown() const
{
	return m_shown;
}


// Return the number of turn since the begining of the battle
int Battle::getBattleTurn() const
{
	if (!m_started)
		THROW_INIT("Battle not started");

	return m_battleTurn;
}


// Return the enemie team
Enemies Battle::getEnemies() const
{
	return m_enemieTeam;
}


// Return the allie team
TeamBattle Battle::getAllies() const
{
	return *m_alliesTeam;
}


// Return the selected TeamMate
TeamMate Battle::getSelectedTeamMate() const
{
	if (!m_started)
		THROW_GAME("Select TeamMate without a started game");
	if ((unsigned)m_battleEventCreated > m_battleOrder.size())
		THROW_GAME("Impossible m_battleEventCreated");
	if (!m_battleOrder.at(m_battleEventCreated-1)->isTeamMate())
		THROW_VALUE("No selected team mate, but selected fighter" + std::to_string(m_battleEventCreated-1));

	return *std::dynamic_pointer_cast<TeamMate>(m_battleOrder.at(m_battleEventCreated-1));
}


// Return the last key event layer
int Battle::getLastKeyEventLayer() const
{
	return m_lastKeyEventLayer;
}


// Return the number of battle event created
int Battle::getBattleEventCreated() const
{
	return m_battleEventCreated;
}


// Return the battle exit
Battle::e_BattleExit Battle::getBattleExit() const
{
	return m_battleExit;
}


// Return the enemie team with modifying possibilities
Enemies& Battle::getRealEnemies()
{
	return m_enemieTeam;
}


// Return the allie team with modifiying possibilities
TeamBattle& Battle::getRealAllies()
{
	return *m_alliesTeam;
}


// Return the battleMenu with modifying possibilities
MenuBattle& Battle::getRealBattleMenu()
{
	return *m_battleMenu;
}


// Return the battleEventManager with modifying possibilities
BattleEventManager& Battle::getRealBattleEventManager()
{
	return m_battleEventManager;
}


// Return the background with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& Battle::getRealBackground()
{
	return m_background;
}


// Return the real battle order
std::vector< std::shared_ptr<Fighter> >& Battle::getRealBattleOrder()
{
	return m_battleOrder;
}


// Modify the battle exit
int Battle::setBattleExit(const Battle::e_BattleExit &be)
{
	if (be >= Battle::e_BattleExit::BATTLE_EXIT_WIN
		&& be <= Battle::e_BattleExit::BATTLE_EXIT_TOTAL)
	{
		m_battleExit = be;
		return 0;
	}

	THROW_VALUE(std::to_string(be));

	return -1;
}


// Modify if the battle is shown
int Battle::setShown(const bool &b)
{
	if (b != m_shown)
	{
		m_background->second->setEnable(b);

		for (std::shared_ptr<TeamMate> tm : m_alliesTeam->getRealTeam())
			tm->getRealSurface()->second->setEnable(b);
	}

	return 0;
}


// Tell the battle it's updated
int Battle::gotUpdated()
{
	m_updated = true;

	return 0;
}


// Start a new battle turn
int Battle::startTurn(Game *g)
{
	if (!m_started || m_inTurn)
		THROW_INIT("Battle not started");

	m_battleEventCreated = 0;
	m_inTurn = true;
	m_choicesFinished = false;
	m_battleEventManager.setWaiting(false);
	m_battleEventManager.setExecuteStarted(false);

	definedOrder(g);

	return 0;
}


// Start a battle according to the arguments
int Battle::start(const std::string &backgroundFilename, TeamBattle team, std::string enemies, Game *g)
{
	if (m_started)
		THROW_INIT("Battle already started");

	clear();

	// Event layer
	m_lastKeyEventLayer = g->getEventManager().getKeyEventLayer();

	// Texture background
	m_texture = g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_BATTLE).addTexture();
	m_texture->loadFromFile(backgroundFilename);
	m_background = g->getRealSurfaceManager(BATTLE_MIN_LAYER).addSurface(ManageSurfaces::SPRITE ,std::make_shared<SurfaceSprite>());
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setTexture(*m_texture);
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setScale(CAMERA_WIDTH / std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->getGlobalBounds().width,
		CAMERA_HEIGHT / std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->getGlobalBounds().height);
	m_background->second->setDimensions(0, 0, CAMERA_WIDTH, CAMERA_HEIGHT);

	// Menus
	m_battleMenu = std::make_shared<MenuBattle>(this, g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_MENU), g->getRealSurfaceManager(BATTLE_MIN_LAYER), BATTLE_KEY_EVENT_LAYER);

	// Load sides
	std::dynamic_pointer_cast<MenuBattleSide>(m_battleMenu->getRealMenus().at(MenuBattle::BM_RIGHT))->loadWithAllies(g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_MENU), g->getRealSurfaceManager(BATTLE_MIN_LAYER), *m_alliesTeam);
	
	EnemiBasic f;
	f.setCharacteristic(Characteristic(5, 10000), Characteristic::e_characteristics::ATTACK_PHYSIC);
	f.setHealth(Health(30));
	f.setMana(Mana(10));
	f.setName("Monstre simple");
	m_enemieTeam.addMember(std::make_shared<EnemiBasic>(f));
	f.setHealth(Health(50));
	f.setName("Monstre 2");
	m_enemieTeam.addMember(std::make_shared<EnemiBasic>(f));
	f.setName("Monstre 3");
	m_enemieTeam.addMember(std::make_shared<EnemiBasic>(f));

	std::dynamic_pointer_cast<MenuBattleSide>(m_battleMenu->getRealMenus().at(MenuBattle::BM_LEFT))->loadWithEnemies(g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_MENU), g->getRealSurfaceManager(BATTLE_MIN_LAYER), m_enemieTeam);

	// Dialog box
	std::dynamic_pointer_cast<MenuDialogBox>(m_battleMenu->getRealMenus().at(MenuBattle::BM_DIALOG))->addText("Début du combat.\n");
	std::dynamic_pointer_cast<MenuDialogBox>(m_battleMenu->getRealMenus().at(MenuBattle::BM_DIALOG))->continueText(
		g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_MENU),
		g->getRealSurfaceManager(BATTLE_MIN_LAYER)
	);

	m_battleMenu->setIsBlocking(true);
	m_battleMenu->setActiveMenu(MenuBattle::BM_DIALOG);

	// Choice
	m_battleMenu->getRealMenus().at(MenuBattle::BM_CHOICE)->setShown(false);

	// BattleOrder
	m_battleOrder.clear();
	int as(m_alliesTeam->getTeam().size()), es(m_enemieTeam.getTeam().size());
	m_battleOrder.resize(as + es);
	for (int i(0); i < as; i++)
		m_battleOrder.at(i) = m_alliesTeam->getRealTeam().at(i);
	for (int i(as); i < as + es; i++)
		m_battleOrder.at(i) = m_enemieTeam.getRealTeam().at(i - as);

	g->getRealSoundManager().addMusic("data/audio/bgm/002-Battle01.flac");

	m_started = true;
	m_updated = true;

	return 0;
}


// Update the battle
int Battle::update(Game *g)
{
	// [TODO]
	if ((!m_updated && !m_battleMenu->getUpdated()) || !m_started)
		return 1;

	// <debuging>
	if (m_alliesTeam->getNumberTeamMateAlive() <= 0)
		m_battleExit = BATTLE_EXIT_LOSE;
	else if (m_enemieTeam.getNumberFighterAlive() <= 0)
		m_battleExit = BATTLE_EXIT_WIN;
	// </debuging>

	if (m_battleExit != Battle::e_BattleExit::BATTLE_EXIT_TOTAL)
	{
		end(g);

		g->getRealEventManager().setKeyEventLayer(0);

		g->getRealMap().gotUpdated();

		return m_battleExit;
	}

	m_battleMenu->getRealMenus().at(MenuBattle::BM_LEFT)->update(*g);
	m_battleMenu->getRealMenus().at(MenuBattle::BM_RIGHT)->update(*g);
	m_battleMenu->getRealMenus().at(MenuBattle::BM_DIALOG)->update(*g);
	m_battleMenu->getRealMenus().at(MenuBattle::BM_CHOICE)->update(*g);

	if (!m_battleMenu->getIsBlocking())
	{
		if (!m_inTurn)
			startTurn(g);
		if (m_inTurn && !m_choicesFinished)
			chooseBattleEvent(g);

		else if (m_choicesFinished)
		{
			m_battleEventManager.execute(*g);
			if(m_battleEventManager.getRealBattleEvents().size() == 0)
				m_inTurn = false;
		}
		// [TODO]
		// <debuging>
		//m_battleMenu->setActiveMenu(MenuBattle::BM_CHOICE);
		//m_battleMenu->setIsBlocking(true);
		//m_battleMenu->getRealMenus().at(MenuBattle::BM_CHOICE)->setShown(true);
		// </debuging>
		//m_battleEventManager.execute(this);
	}

	m_updated = false;

	return 0;
}


// End the battle
int Battle::end(Game *g)
{
	// [TODO]

	if (!m_started)
		THROW_INIT("Battle not started");

	// Free textures
	g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_BATTLE).deleteTexture(m_texture);
	g->getRealSurfaceManager(BATTLE_MIN_LAYER).deleteSurface(m_background);

	// Free menus
	m_battleMenu->close(g->getRealSurfaceManager(BATTLE_MIN_LAYER));
	m_battleMenu.reset();

	// Free enemies
	m_enemieTeam.clear();
	
	g->getRealSoundManager().deleteMusic();

	m_started = false;

	return 0;
}


// Set m_battleOrder to make the right order
int Battle::definedOrder(Game *g)
{
	if (!m_started)
		THROW_INIT("Battle not started");

	for (unsigned int i(1) ; i < m_battleOrder.size() ; i++)
	{
		for (int j(i-1) ; j >= 0 ; j--)
		{
			if (m_battleOrder.at(i)->getRealCharacteristics().at(Characteristic::e_characteristics::SPEED).getValue()
				<= m_battleOrder.at(j)->getRealCharacteristics().at(Characteristic::e_characteristics::SPEED).getValue())
			{
				std::swap(m_battleOrder.at(i), m_battleOrder.at(j));
				j = -1;
			}
		}
	}

	return 0;
}


// Choose battle event for the next player
int Battle::chooseBattleEvent(Game *g)
{
	if (!m_started || !m_inTurn)
		THROW_INIT("Battle not started");

	if (m_battleEventCreated == m_battleOrder.size())
	{
		m_choicesFinished = true;
		return 0;
	}

	if (m_battleOrder.at(m_battleEventCreated)->isTeamMate())
	{
		//m_selectedTeamMate = *std::dynamic_pointer_cast<TeamMate>(m_battleOrder.at(m_battleEventCreated));

		m_battleMenu->setIsBlocking(true);

		std::string str("Que dois faire ");

		str = str + m_battleOrder.at(m_battleEventCreated)->getName() + " ?";

		std::dynamic_pointer_cast<MenuDialogBox>(m_battleMenu->getRealMenus().at(MenuBattle::BM_DIALOG))->addText(str);
		std::dynamic_pointer_cast<MenuDialogBox>(m_battleMenu->getRealMenus().at(MenuBattle::BM_DIALOG))->continueText(
			g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_MENU),
			g->getRealSurfaceManager(BATTLE_MIN_LAYER)
		);
		m_battleMenu->setActiveMenu(MenuBattle::BM_CHOICE);
	}
	else
	{
		m_battleEventManager.getRealBattleEvents().push_back(m_battleOrder.at(m_battleEventCreated)->chooseEvent(g));
	}

	m_battleEventCreated++;

	return 0;
}


// Clear the battle attribute from last battle
int Battle::clear()
{
	m_battleEventCreated = 0;
	m_battleExit = Battle::e_BattleExit::BATTLE_EXIT_TOTAL;
	
	return m_battleEventManager.clear();
}