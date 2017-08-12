#include <memory>
#include "MenuInventory.h"
#include "../constants.h"
#include "../Error/ValueException.h"
#include "../Error/InitializationException.h"



MenuInventory::MenuInventory(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer) :
	Menu(ress, surf, lastEventLayer),
	m_dialogBox(ress, surf, lastEventLayer),
	m_choices(ress, surf, lastEventLayer),
	m_initialized(false)
{
	surf.deleteSurface(m_background);
}


MenuInventory::~MenuInventory()
{
}


// Return the spells
std::vector<Item> MenuInventory::getItems() const
{
	return *m_items;
}


// Return the dialog box with modifying possibilities
MenuDialogBox& MenuInventory::getRealDialogBox()
{
	return m_dialogBox;
}


// Return the menu choice with modifying possibilities
MenuChoice& MenuInventory::getRealMenuChoices()
{
	return m_choices;
}


// Return the spells with modifying possibilities
std::vector<Item>& MenuInventory::getRealItems()
{
	return *m_items;
}


// Load the menu
int MenuInventory::load(ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, std::vector<Item> &items)
{
	if (m_initialized)
		THROW_GAME("Already initiate");
	if (items.size() <= 0)
		THROW_VALUE("No spells");

	m_dialogBox.load(ress, surf, "Menu des sorts et techniques", xcam, ycam, MENU_SPELLS_DIALOG_BOX_X, MENU_SPELLS_DIALOG_BOX_Y, MENU_SPELLS_DIALOG_BOX_WIDTH, MENU_SPELLS_DIALOG_BOX_HEIGHT);
	m_choices.loadFromStream(ress, surf, makeChoicesSS(items), xcam, ycam, MENU_SPELLS_CHOICES_WIDTH - (2 * MENUS_BORDER_X), MENUS_GAP_BETWEEN_LINES);

	m_items = std::make_unique<std::vector<Item>>(items);

	m_initialized = true;

	return 0;
}


// Update surfaces
int MenuInventory::update(Game &g)
{
	m_dialogBox.update(g);
	m_choices.update(g);

	return 0;
}


// Close the menu
int MenuInventory::close(ManageSurfaces &surf)
{
	if (!m_initialized)
		THROW_INIT("MenuSpells not initiate");

	m_dialogBox.close(surf);
	m_choices.close(surf);

	return 0;
}


// Make a stringstream
std::stringstream MenuInventory::makeChoicesSS(std::vector<Item> &items)
{
	std::stringstream ss;

	ss << "AUTO\n" << MIN((signed)items.size(), (MENU_SPELLS_CHOICES_HEIGHT - (2 * MENUS_BORDER_Y)) / (MENUS_GAP_BETWEEN_LINES)) << " "
		<< MENU_SPELLS_CHOICES_X << " " << MENU_SPELLS_CHOICES_Y << " " << MENU_SPELLS_CHOICES_WIDTH << " " << MENU_SPELLS_CHOICES_HEIGHT << "\n";

	for (unsigned int i(0); i < items.size(); i++)
	{
		ss << "NOTHING\n" << items.at(i).getName();

		if ((unsigned)(i + 1) < items.size())
			ss << "\n";
	}

	ss.seekg(0, ss.beg);
	return ss;
}