#include "../constants.h"
#include "../Game.h"
#include "Menu.h"



Menu::Menu(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer)
{
	m_background = surf.addSurface(ManageSurfaces::e_thing::SPRITE, std::shared_ptr<Surface>(new SurfaceSprite));
	/*if(showCursor)
		m_cursorSurface = surf.addSurface(ManageSurfaces::e_thing::SPRITE, std::shared_ptr<Surface>(new SurfaceSprite));
	m_selectedChoiceSurface = surf.addSurface(ManageSurfaces::e_thing::SPRITE, std::shared_ptr<Surface>(new SurfaceSprite));*/

	m_lastEventLayer = lastEventLayer;
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setEnable(false);
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setTexture(ress.getTheTexture(RESSOURCE_TEXTURE_NUMBER_MENU));
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setTextureRect(sf::IntRect(MENU_SURFACE_BEGIN_X, MENU_SURFACE_BEGIN_Y, MENU_SURFACE_WIDTH, MENU_SURFACE_HEIGHT));
	/*if (showCursor)
	{
		std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurface->second)->setTexture(-*(it++));
	}

	m_showCursor = showCursor;
	m_initialized = false;
	m_selectedChoice = 0;
	m_firstChoiceShown = 0;
	m_lastChoiceShown = 0;*/
	m_x = 0;
	m_y = 0;
	m_width = 0;
	m_height = 0;
	m_initialized = false;
}


Menu::~Menu()
{
}


// Return if the menu is initialized
bool Menu::getInitialized() const
{
	return m_initialized;
}


// Return the background with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator Menu::getBackground()
{
	return m_background;
}

/*
// Return the choices surfaces with modifying possibilities
std::vector<std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator> Menu::getChoicesSurface()
{
	return m_choicesSurface;
}


// Return the cursor surfaces with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator Menu::getCursorSurface()
{
	return m_cursorSurface;
}


// Return the selected choice surface with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator Menu::getSelectedChoiceSurface()
{
	return m_selectedChoiceSurface;
}


// Return the selected choice
int Menu::getSelectedChoice() const
{
	return m_selectedChoice;
}


// Return the first choice actually shown
int Menu::getFirstChoiceShown() const
{
	return m_firstChoiceShown;
}


// Return the last choice actually shown
int Menu::getLastChoiceShown() const
{
	return m_lastChoiceShown;
}
*/

// Return the position X of the menu
int Menu::getX() const
{
	return m_x;
}


// Return the position Y of the menu
int Menu::getY() const
{
	return m_y;
}


// Return the width of the menu
int Menu::getWidth() const
{
	return m_width;
}


// Return the height of the menu
int Menu::getHeight() const
{
	return m_height;
}

/*
// Modify the selected choice
int Menu::setSelectedChoice(const int &ch)
{
	if ((unsigned)ch < m_choicesSurface.size())
		m_selectedChoice = ch;
	else
		return 0;

	return update();
}
*/

// Load the menu
int Menu::load(ManageRessources& ress, ManageSurfaces& surf, const int &x, const int &y, const int &w, const int &h)
{
	if (m_initialized)
		return -1;
	
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setEnable(true);
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setScale(float(w) / (MENU_SURFACE_WIDTH), float(h) / (MENU_SURFACE_HEIGHT));
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setDimensions(x, y, w, h);
	m_initialized = true;


	/*auto it(ress.getFonts().begin());
	int max = -1;
	it++;*/

	/*m_choicesSurface.resize(choices.size());

	for (int i(0); i < choices.size(); i++)
	{
		m_choicesSurface.at(i) = surf.addSurface(ManageSurfaces::e_thing::TEXT, std::shared_ptr<Surface>(new SurfaceText));
		std::dynamic_pointer_cast<SurfaceText>(m_choicesSurface.at(i)->second)->setFont(*it);
		std::dynamic_pointer_cast<SurfaceText>(m_choicesSurface.at(i)->second)->setString(choices.at(i));
		std::dynamic_pointer_cast<SurfaceText>(m_choicesSurface.at(i)->second)->setPosition(float(x), float(y));
	}

	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setTextureRect(sf::IntRect(x, y, w, h));*/
	return 0;
}


// Update surfaces
int Menu::update(Game &g)
{
	int x = g.getRealMap().getCamera().getX();
	int y = g.getRealMap().getCamera().getY();
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setPosition(float(x + m_x), float(y + m_y));
	return 0;
}


// Close the menu
int Menu::close(ManageSurfaces& surf)
{
	surf.deleteSurface(m_background);
	return m_lastEventLayer;
}