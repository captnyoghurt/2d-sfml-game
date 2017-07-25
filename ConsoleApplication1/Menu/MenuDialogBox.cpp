#include <iostream>
#include "../constants.h"
#include "MenuDialogBox.h"



MenuDialogBox::MenuDialogBox(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer) : Menu(ress, surf, lastEventLayer)
{
	m_cursorSurfaceDown = surf.addSurface(ManageSurfaces::e_thing::SPRITE, std::make_shared<SurfaceSprite>());
	
	std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->setTexture(ress.getTheTexture(0));
	std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->setTextureRect(sf::IntRect(MENU_SURFACE_CURSOR_DOWN_BEGIN_X, MENU_SURFACE_CURSOR_DOWN_BEGIN_Y, MENU_SURFACE_CURSOR_DOWN_WIDTH, MENU_SURFACE_CURSOR_DOWN_HEIGHT));

	m_initialized = false;
	m_firstShownCharacter = 0;
	m_lastShownCharacter = 0;
}


MenuDialogBox::~MenuDialogBox()
{
}


// Return the global text in the dialog box
std::string MenuDialogBox::getText() const
{
	return m_text;
}


// Return the first shown character
int MenuDialogBox::getFirstShownCharacter() const
{
	return m_firstShownCharacter;
}


// Return the last shown character
int MenuDialogBox::getLastShownCharacter() const
{
	return m_lastShownCharacter;
}


// Return the down cursor surface with modifying possibilities
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& MenuDialogBox::getCursorSurfaceDown()
{
	return m_cursorSurfaceDown;
}


// Modify the global text in the dialog box
int MenuDialogBox::setText(const std::string &text)
{
	if (m_initialized)
		return -1;

	m_text = text;
	m_textStream.str(text);

	return 0;
}


// Keep on reading in the text
int MenuDialogBox::continueText(ManageRessources& ress, ManageSurfaces& surf)
{
	// Clear the current text surfaces
	for (unsigned int i(0); i < m_textSurface.size(); i++)
	{
		surf.deleteSurface(m_textSurface.at(i));
	}
	m_textSurface.clear();

	// Variables for the reading
	std::string lineActual;
	int fillHeightCounter(0);
	int fillWidthCounter(0);
	char c;

	if (m_textStream.eof())
		return 1;

	m_textSurface.push_back(surf.addSurface(ManageSurfaces::e_thing::TEXT, std::make_shared<SurfaceText>()));
	m_textSurface.back()->second->setDimensions(m_x + MENUS_BORDER_X,
		m_y + MENUS_BORDER_Y,
		MENU_DIALOG_BOX_WIDTH - 2 * MENUS_BORDER_X,
		MENU_DIALOG_BOX_HEIGHT - 2 * MENUS_BORDER_Y);

	fillHeightCounter += MENU_DIALOG_BOX_GAP_BETWEEN_LINES + 2*MENUS_BORDER_Y;

	while (fillHeightCounter < m_height)
	{
		fillWidthCounter = 0;
		lineActual = "";
		while (fillWidthCounter < MENU_DIALOG_BOX_CHARACTER_BY_LINE)
		{
			if (!m_textStream.get(c))
			{
				fillWidthCounter = m_width;
				fillHeightCounter = m_height;
				break;
			}
			if (!(lineActual.empty() && c == ' '))
			{
				if (c == '\\')
				{
					int heightSup = readInstruction(surf);
					if (heightSup > 0)
					{
						fillHeightCounter += heightSup;
						remakeText(lineActual, std::dynamic_pointer_cast<SurfaceText>(m_textSurface.at(m_textSurface.size() - 2)->second), ress);
						break;
					}
				}
				else
				{
					lineActual += c;
					fillWidthCounter++;
				}
			}
		}
		if (fillWidthCounter >= MENU_DIALOG_BOX_CHARACTER_BY_LINE)
		{
			if (!m_textStream.eof() && (lineActual.back() >= 'a' && lineActual.back() <= 'z') || (lineActual.back() >= 'A' && lineActual.back() <= 'Z'))
			{
				m_textStream.get(c);
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
				{
					lineActual.at(lineActual.size() - 1) = '-';
					m_textStream.seekg(-1, m_textStream.cur);
				}
				m_textStream.seekg(-1, m_textStream.cur);
			}
			remakeText(lineActual, std::dynamic_pointer_cast<SurfaceText>(m_textSurface.back()->second), ress);
			fillHeightCounter += MENU_DIALOG_BOX_FONTSIZE;

			newLine(surf);
		}

	}

	if (m_textStream.eof())
		m_cursorSurfaceDown->second->setEnable(false);

	return 0;
}


// Load the menu
int MenuDialogBox::load(ManageRessources& ress, ManageSurfaces& surf, const std::string &text, const int &xcam, const int &ycam)
{
	// Initialization
	if (m_initialized)
		return -1;
	setText(text);
	m_initialized = true;

	// Set the dimensions
	m_x = MENU_DIALOG_BOX_X + xcam;
	m_y = MENU_DIALOG_BOX_Y + ycam;
	m_width = MENU_DIALOG_BOX_WIDTH;
	m_height = MENU_DIALOG_BOX_HEIGHT;

	// Place the background
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setEnable(true);
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setScale(float(m_width) / (MENU_SURFACE_WIDTH), float(m_height) / (MENU_SURFACE_HEIGHT));
	std::dynamic_pointer_cast<SurfaceSprite>(m_background->second)->setDimensions(m_x, m_y, m_width, m_height);

	// Cursor
	m_cursorSurfaceDown->second->setEnable(true);
	m_cursorSurfaceDown->second->setDimensions(m_x + (m_width / 2) - int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->getGlobalBounds().width),
		m_y + m_height - int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->getGlobalBounds().height),
		int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->getGlobalBounds().width),
		int(std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceDown->second)->getGlobalBounds().height));

	// Start loading the text
	continueText(ress, surf);

	return 0;
}


// Update surfaces
int MenuDialogBox::update(Game &g)
{
	return 0;
}


// Close the menu
int MenuDialogBox::close(ManageSurfaces& surf)
{
	for (unsigned int i(0); i < m_textSurface.size(); i++)
	{
		surf.deleteSurface(m_textSurface.at(i));
	}

	m_textSurface.clear();

	surf.deleteSurface(m_background);
	surf.deleteSurface(m_cursorSurfaceDown);

	return m_lastEventLayer;
}


// Remake the text surface
int MenuDialogBox::remakeText(const std::string &str, std::shared_ptr<SurfaceText> &text, ManageRessources &ress)
{
	text->setString(str);
	text->setFont(ress.getTheFont(0));
	text->setCharacterSize(MENU_DIALOG_BOX_FONTSIZE);
	text->setWidth(int(text->getGlobalBounds().width));
	text->setHeight(int(text->getGlobalBounds().height));

	return 0;
}


// Read an instruction in the text
int MenuDialogBox::readInstruction(ManageSurfaces& surf)
{
	newLine(surf);
	
	return MENU_DIALOG_BOX_GAP_BETWEEN_LINES;
}


// Create a new line
int MenuDialogBox::newLine(ManageSurfaces& surf)
{
	m_textSurface.push_back(surf.addSurface(ManageSurfaces::e_thing::TEXT, std::make_shared<SurfaceText>()));
	m_textSurface.back()->second->setDimensions(m_textSurface.at(m_textSurface.size() - 2)->second->getX(),
		m_textSurface.at(m_textSurface.size() - 2)->second->getY() + MENUS_GAP_BETWEEN_LINES,
		m_textSurface.at(m_textSurface.size() - 2)->second->getWidth(),
		m_textSurface.at(m_textSurface.size() - 2)->second->getHeight());

	std::dynamic_pointer_cast<SurfaceText>(m_textSurface.back()->second)->setCharacterSize(MENU_DIALOG_BOX_FONTSIZE);

	return 0;
}