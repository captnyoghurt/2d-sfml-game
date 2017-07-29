#pragma once
#include <sstream>
#include "Menu.h"


class MenuDialogBox :
	public Menu
{
public:
	MenuDialogBox(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~MenuDialogBox();

public:
	// Return the global text in the dialog box
	std::string getText() const;
	// Return the first shown character
	int getFirstShownCharacter() const;
	// Return the last shown character
	int getLastShownCharacter() const;

	// Return the down cursor surface with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getCursorSurfaceDown();

	// Modify the global text in the dialog box
	int setText(const std::string &text);
	// Add text to the stream
	int addText(const std::string &text);

	// Keep on reading in the text
	int continueText(ManageRessources& ress, ManageSurfaces& surf);

	// Load the menu
	virtual int load(ManageRessources& ress, ManageSurfaces& surf, const std::string &text, const int &xcam, const int &ycam);
	// Update surfaces
	virtual int update(Game &g);
	// Close the menu
	virtual int close(ManageSurfaces& surf);

protected:
	// Remake the text surface
	int remakeText(const std::string &str, std::shared_ptr<SurfaceText> &text, ManageRessources &ress);

	// Read an instruction in the text
	int readInstruction(ManageSurfaces& surf);

	// Create a new line
	int newLine(ManageSurfaces& surf);

private:
	std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator m_cursorSurfaceDown;
	std::vector < std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator > m_textSurface;
	std::string m_text;
	std::stringstream m_textStream;
	int m_firstShownCharacter;
	int m_lastShownCharacter;
};

