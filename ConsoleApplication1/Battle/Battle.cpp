#include <iostream>
#include "Battle.h"
#include "../Map/ManageRessources.h"
#include "../Map/ManageSurfaces.h"
#include "../constants.h"
#include "../Menu/MenuBattle.h"
#include "../Game.h"
#include "../Menu/MenuBattleSide.h"
#include "../Menu/MenuDialogBox.h"



Battle::Battle(TeamBattle &tb)
{
	m_updated = true;
	m_started = false;
	m_inTurn = false;
	m_choicesFinished = false;
	
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


// Return the number of turn since the begining of the battle
int Battle::getBattleTurn() const
{
	if (!m_started)
		return -1;

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
		return -1;

	m_battleEventCreated = 0;
	m_inTurn = true;
	m_choicesFinished = false;

	//definedOrder(g);

	return 0;
}


// Start a battle according to the arguments
int Battle::start(const std::string &backgroundFilename, TeamBattle team, std::string enemies, Game *g)
{
	if (m_started)
		return -1;

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
	
	Fighter f;
	f.setHealth(30);
	f.setMana(10);
	f.setName("Monstre simple");
	m_enemieTeam.addMember(f);
	f.setHealth(50);
	f.setName("Monstre 2");
	m_enemieTeam.addMember(f);
	f.setName("Monstre 3");
	m_enemieTeam.addMember(f);

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
		m_battleOrder.at(i) = std::make_shared<TeamMate>(m_alliesTeam->getRealTeam().at(i));
	for (int i(as); i < as + es; i++)
		m_battleOrder.at(i) = m_enemieTeam.getRealTeam().at(i - as);

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
			if (m_battleEventManager.execute(*g) < 0)
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
		return -1;

	// Free textures
	g->getRealRessourceManager(Game::e_ressourcesLayer::RESSOURCES_BATTLE).deleteTexture(m_texture);
	g->getRealSurfaceManager(BATTLE_MIN_LAYER).deleteSurface(m_background);

	// Free menus
	m_battleMenu->close(g->getRealSurfaceManager(BATTLE_MIN_LAYER));
	m_battleMenu.reset();

	// Free enemies
	m_enemieTeam.clear();

	m_started = false;

	return 0;
}


// Set m_battleOrder to make the right order
int Battle::definedOrder(Game *g)
{
	if (!m_started)
		return -1;

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
		return -1;

	if (m_battleEventCreated == m_battleOrder.size())
	{
		m_choicesFinished = true;
		return 0;
	}

	if (m_battleOrder.at(m_battleEventCreated)->isTeamMate())
	{
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
		std::cout << "Non teammate" << std::endl;

	m_battleEventCreated++;

	return 0;
}


// Clear the battle attribute from last battle
int Battle::clear()
{
	m_battleEventCreated = 0;
	
	return m_battleEventManager.clear();
}