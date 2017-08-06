#include <fstream>
#include <sstream>
#include "../constants.h"
#include "../Game.h"
#include "../Event/IG_Action.h"
#include "../initialization.h"
#include "MenuChoice.h"
#include "../Error/InitializationException.h"
#include "../Error/ValueException.h"
#include "../Error/RessourceException.h"


MenuChoice::MenuChoice(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer) : Menu(ress, surf, lastEventLayer)
{
	m_selectedChoiceSurface = surf.addSurface(ManageSurfaces::e_thing::SPRITE, std::shared_ptr<Surface>(new SurfaceSprite));
	m_cursorSurfaceDown = surf.addSurface(ManageSurfaces::e_thing::SPRITE, std::shared_ptr<Surface>(new SurfaceSprite));
	m_cursorSurfaceUp = surf.addSurface(ManageSurfaces::e_thing::SPRITE, std::shared_ptr<Surface>(new SurfaceSprite));

	std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceUp->second)->setTexture(ress.getTheTexture(RESSOURCE_TEXTURE_NUMBER_MENU));
	std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceUp->second)->setTextureRect(sf::IntRect(MENU_SURFACE_CURSOR_UP_BEGIN_X, MENU_SURFACE_CURSOR_UP_BEGIN_Y, MENU_SURFACE_CURSOR_UP_WIDTH, MENU_SURFACE_CURSOR_UP_HEIGHT));
	std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->setTexture(ress.getTheTexture(RESSOURCE_TEXTURE_NUMBER_MENU));
	std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->setTextureRect(sf::IntRect(MENU_SURFACE_CURSOR_DOWN_BEGIN_X, MENU_SURFACE_CURSOR_DOWN_BEGIN_Y, MENU_SURFACE_CURSOR_DOWN_WIDTH, MENU_SURFACE_CURSOR_DOWN_HEIGHT));
	std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->setTexture(ress.getTheTexture(RESSOURCE_TEXTURE_NUMBER_MENU));
	std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->setTextureRect(sf::IntRect(MENU_SURFACE_SELECTED_BEGIN_X, MENU_SURFACE_SELECTED_BEGIN_Y, MENU_SURFACE_SELECTED_WIDTH, MENU_SURFACE_SELECTED_HEIGHT));

	m_initialized = false;
	m_selectedChoice = 0;
	m_firstChoiceShown = 0;
	m_lastChoiceShown = 0;
}


MenuChoice::~MenuChoice()
{

}


// Return the choices surfaces with modifying possibilities
std::vector<std::shared_ptr<M_choice>> MenuChoice::getChoices()
{
	return m_choices;
}


// Return the down cursor surfaces with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator MenuChoice::getCursorSurfaceDown()
{
	return m_cursorSurfaceDown;
}


// Return the up cursor surfaces with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator MenuChoice::getCursorSurfaceUp()
{
	return m_cursorSurfaceUp;
}

// Return the selected choice surface with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator MenuChoice::getSelectedChoiceSurface()
{
	return m_selectedChoiceSurface;
}


// Return the selected choice
int MenuChoice::getSelectedChoice() const
{
	return m_selectedChoice;
}


// Return the first choice actually shown
int MenuChoice::getFirstChoiceShown() const
{
	return m_firstChoiceShown;
}


// Return the last choice actually shown
int MenuChoice::getLastChoiceShown() const
{
	return m_lastChoiceShown;
}


// Modify if the menu should be shown or not
int MenuChoice::setShown(const bool &b)
{
	if (Menu::setShown(b) >= 0)
	{
		m_cursorSurfaceDown->second->setEnable(b);
		m_cursorSurfaceUp->second->setEnable(b);
		m_selectedChoiceSurface->second->setEnable(b);

		for (unsigned int i(0); i < m_choices.size(); i++)
		{
			m_choices.at(i)->getRealSurface()->second->setEnable(b);
		}
		if(b)
			setSelectedChoice(m_selectedChoice);

		return 0;
	}

	THROW_GAME("Menu::setShown error");

	return -1;
}


// Modify the selected choice
int MenuChoice::setSelectedChoice(const int	&ch)
{
	if ((unsigned)ch < m_choices.size())
		m_selectedChoice = ch;
	else
		return 0;

	if (m_firstChoiceShown > ch)
	{
		m_lastChoiceShown = ch + m_lastChoiceShown - m_firstChoiceShown;
		m_firstChoiceShown = ch;
	}
	else if(m_lastChoiceShown < ch)
	{
		m_firstChoiceShown = ch - (m_lastChoiceShown - m_firstChoiceShown);
		m_lastChoiceShown = ch;
	}

	m_cursorSurfaceDown->second->setEnable((unsigned)m_lastChoiceShown < m_choices.size() - 1);
	m_cursorSurfaceUp->second->setEnable(m_firstChoiceShown > 0);

	/*std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->setDimensions(std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->getX(),
		std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->getY() + ((m_selectedChoice - m_firstChoiceShown)*MENUS_GAP_BETWEEN_LINES) + MENUS_BORDER_Y - ((MENU_SURFACE_SELECTED_HEIGHT - MENU_SIMPLE_FONTSIZE) / 4),
		int(std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->getGlobalBounds().width),
		int(std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->getGlobalBounds().height));*/

	for (unsigned int i(0); i < m_choices.size(); i++)
	{
		if (i >= (unsigned)m_firstChoiceShown && i <= (unsigned)m_lastChoiceShown)
		{
			m_choices.at(i)->setShown(true, 0, -m_firstChoiceShown*MENUS_GAP_BETWEEN_LINES);
		}
		else
		{
			m_choices.at(i)->setShown(false, 0, 0);
		}
	}

	m_selectedChoiceSurface->second->setDimensions(
		m_choices.at(m_selectedChoice)->getX() - MENUS_BORDER_X,
		m_choices.at(m_selectedChoice)->getY() - m_firstChoiceShown*MENUS_GAP_BETWEEN_LINES,
		int(std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->getGlobalBounds().width),
		int(std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->getGlobalBounds().height)
	);

	return 1;
}


// Resize the ChoiceSurface according to the selected choice
int MenuChoice::resizeChoiceSurface()
{
	float w, h;

	if (!m_initialized)
		THROW_INIT("Not initiate");

	w = (float)m_choices.at(m_selectedChoice)->getRealSurface()->second->getWidth() + 2 * MENUS_BORDER_X;
	h = (float)m_choices.at(m_selectedChoice)->getRealSurface()->second->getHeight();

	std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->setWidth((int)w);
	std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->setHeight((int)h);

	std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->scale(
		w / std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->getGlobalBounds().width,
		h / std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->getGlobalBounds().height
	);
	return 0;
}


// Load the menu
int MenuChoice::load(ManageRessources& ress, ManageSurfaces& surf, const std::string &filename, const int &xcam, const int &ycam)
{
	if (m_initialized)
		THROW_INIT("Already initiate");

	bool autoPlacement(false);
	sf::Font& f(ress.getTheFont(RESSOURCE_FONT_NUMBER_MONO));
	int numberOfChoices(0);
	std::ifstream file(filename);
	std::string firstLine, secondLine;
	IG_Action act;

	if (!file.is_open())
		THROW_RESSOURCE("File for menu choice", filename);

	// Doesn't read the header with commentary
	while (std::getline(file, firstLine) && ((firstLine.size() > 0 && firstLine[0] == '#') || firstLine.size() == 0));

	if (firstLine == "AUTO")
		autoPlacement = true;

	file >> m_lastChoiceShown >> m_x >> m_y >> m_width >> m_height;
	std::getline(file, firstLine);

	// Place the cursors for the scrolling menu
	m_cursorSurfaceUp->second->setDimensions(xcam + m_x + (m_width / 2) - int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceUp->second)->getGlobalBounds().width),
												ycam + m_y,
												int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceUp->second)->getGlobalBounds().width),
												int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceUp->second)->getGlobalBounds().height));
	m_cursorSurfaceDown->second->setDimensions(xcam + m_x + (m_width / 2) - int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->getGlobalBounds().width),
												ycam + m_y + m_height - int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->getGlobalBounds().height),
												int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->getGlobalBounds().width),
												int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->getGlobalBounds().height));

	while (std::getline(file, firstLine) && std::getline(file, secondLine))
	{
		m_choices.push_back(std::shared_ptr<M_choice>(new M_choice));
		int cx, cy;

		// Read the "first line" with every indication (position, action)
		if (autoPlacement)
		{
			act.setAction(getActionFromWord(firstLine));
			cx = xcam + m_x + MENUS_BORDER_X;
			cy = ycam + m_y + MENUS_BORDER_Y + (MENUS_GAP_BETWEEN_LINES*numberOfChoices);
		}
		else
		{
			std::istringstream iss(firstLine);
			std::string word;
			iss >> cx >> cy >> word;
			act.setAction(getActionFromWord(word));
		}
		// Second line used for the string
		m_choices.back()->load(surf, secondLine, f, cx, cy, true, act);

		numberOfChoices++;
	}
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setEnable(true);
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setScale(float(m_width) / (MENU_SURFACE_WIDTH), float(m_height) / (MENU_SURFACE_HEIGHT));
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setDimensions(xcam + m_x, ycam + m_y, m_width, m_height);
	m_initialized = true;

	m_firstChoiceShown = 0;
	
	if (m_lastChoiceShown >= 0)
		m_lastChoiceShown = MIN(m_lastChoiceShown-1, numberOfChoices - 1);
	else
		m_lastChoiceShown = numberOfChoices - 1;

	std::dynamic_pointer_cast<SurfaceSprite>(m_selectedChoiceSurface->second)->setScale(float(m_width) / (MENU_SURFACE_SELECTED_WIDTH),
																						float(std::dynamic_pointer_cast<SurfaceSprite>(m_choices.at(0)->getRealSurface()->second)->getGlobalBounds().height) / (MENU_SURFACE_SELECTED_HEIGHT));

	setSelectedChoice(0);

	return 0;
}


// Update surfaces
int MenuChoice::update(Game &g)
{
	int x = g.getRealMap().getCamera().getX();
	int y = g.getRealMap().getCamera().getY();
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setPosition(float(x + m_x), float(y + m_y));

	for (unsigned int i(0); i < m_choices.size(); i++)
	{
		std::dynamic_pointer_cast<SurfaceSprite>(m_choices.at(i)->getSurface()->second)->setPosition(float(x + m_x + MENUS_BORDER_X), float(x + m_y + MENUS_BORDER_Y + (i*MENUS_GAP_BETWEEN_LINES)));
	}

	return 0;
}


// Close the menu
int MenuChoice::close(ManageSurfaces& surf)
{
	for (unsigned int i(0); i < m_choices.size(); i++)
	{
		m_choices.at(i)->clear(surf);
	}

	m_choices.clear();

	surf.deleteSurface(m_background);
	surf.deleteSurface(m_selectedChoiceSurface);
	surf.deleteSurface(m_cursorSurfaceDown);
	surf.deleteSurface(m_cursorSurfaceUp);

	return m_lastEventLayer;
}