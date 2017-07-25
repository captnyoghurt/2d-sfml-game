#include "Battle.h"
#include "../Map/ManageRessources.h"
#include "../Map/ManageSurfaces.h"
#include "../constants.h"
#include "../Menu/MenuBattle.h"



Battle::Battle()
{
	m_started = false;
}


Battle::~Battle()
{
	delete m_battleMenu;
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
	return m_alliesTeam;
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
	return m_alliesTeam;
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
int Battle::start(const std::string &backgroundFilename, TeamBattle team, std::string enemies, ManageRessources &ress, ManageSurfaces &surf, int lastEventLayer)
{
	if (m_started)
		return -1;

	// Event layer
	m_lastKeyEventLayer = lastEventLayer;

	// Texture background
	m_texture = ress.addTexture();
	m_texture->loadFromFile(backgroundFilename);
	m_background = surf.addSurface(ManageSurfaces::SPRITE ,std::shared_ptr<Surface>(new SurfaceSprite));
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setTexture(*m_texture);
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setScale(CAMERA_WIDTH / std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->getGlobalBounds().width,
		CAMERA_HEIGHT / std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->getGlobalBounds().height);
	m_background->second->setDimensions(0, 0, CAMERA_WIDTH, CAMERA_HEIGHT);

	// Menus
	m_battleMenu = new MenuBattle(this, ress, surf, BATTLE_KEY_EVENT_LAYER);

	m_started = true;

	return 0;
}


// Update the battle
int Battle::update(ManageRessources &ress, ManageSurfaces& surf)
{
	// [TODO]

	return 0;
}


// End the battle
int Battle::end(ManageRessources &ress, ManageSurfaces& surf)
{
	// [TODO]

	if (!m_started)
		return -1;

	// Free textures
	ress.deleteTexture(m_texture);
	surf.deleteSurface(m_background);

	// Free menus
	m_battleMenu->close(surf);
	delete m_battleMenu;

	m_started = false;

	return 0;
}