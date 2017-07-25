#include "Battle.h"
#include "../Map/ManageRessources.h"
#include "../Map/ManageSurfaces.h"
#include "../constants.h"
#include "../Menu/MenuBattle.h"
#include "../Game.h"



Battle::Battle(TeamBattle &tb)
{
	m_started = false;
	
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


// Start a battle according to the arguments
int Battle::start(const std::string &backgroundFilename, TeamBattle team, std::string enemies, Game *g)
{
	if (m_started)
		return -1;

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

	m_started = true;

	return 0;
}


// Update the battle
int Battle::update(Game *g)
{
	// [TODO]

	m_battleMenu->getRealMenus().at(MenuBattle::BM_LEFT)->update(*g);
	m_battleMenu->getRealMenus().at(MenuBattle::BM_RIGHT)->update(*g);
	m_battleMenu->getRealMenus().at(MenuBattle::BM_DIALOG)->update(*g);
	m_battleMenu->getRealMenus().at(MenuBattle::BM_CHOICE)->update(*g);

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

	m_started = false;

	return 0;
}