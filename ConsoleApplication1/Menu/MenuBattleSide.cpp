#include "../constants.h"
#include "../Map/ManageSurfaces.h"
#include "MenuBattleSide.h"
#include "../Battle/Health.h"
#include "../Battle/Mana.h"


MenuBattleSide::MenuBattleSide(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer, int type) : Menu(ress, surf, lastEventLayer)
{
	m_barType = type;

	m_cursorSurfaceRight = surf.addSurface(ManageSurfaces::e_thing::SPRITE, std::shared_ptr<Surface>(new SurfaceSprite));

	std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceRight->second)->setTexture(ress.getTheTexture(RESSOURCE_TEXTURE_NUMBER_MENU));
	std::dynamic_pointer_cast<SurfaceSprite>(m_cursorSurfaceRight->second)->setTextureRect(sf::IntRect(MENU_SURFACE_CURSOR_RIGHT_BEGIN_X, MENU_SURFACE_CURSOR_RIGHT_BEGIN_Y, MENU_SURFACE_CURSOR_RIGHT_WIDTH, MENU_SURFACE_CURSOR_RIGHT_HEIGHT));

	m_selectedChoice = 0;
	m_initialized = false;
	m_numberMaxChoices = TEAM_BATTLE_MAX_NUMBER;
}


MenuBattleSide::~MenuBattleSide()
{
}


// Return the cursor for the right surface
std::list < std::pair < ManageSurfaces::e_thing, std::shared_ptr<Surface> > >::iterator MenuBattleSide::getCursor()
{
	return m_cursorSurfaceRight;
}


// Return the current selected choice
int MenuBattleSide::getSelectedChoice() const
{
	return m_selectedChoice;
}


// Return the maximum number of choices
int MenuBattleSide::getNumberMaxChoices() const
{
	return m_numberMaxChoices;
}


// Return all the choices with modifying possibilities
std::vector< std::shared_ptr<M_choice> >& MenuBattleSide::getChoices()
{
	return m_choices;
}


// Modify the current selected choice
int MenuBattleSide::setSelectedChoice(const int &s)
{
	if ((unsigned)s < (unsigned)m_numberMaxChoices)
	{
		m_selectedChoice = s;
		return 0;
	}

	return -1;
}


// Modify the maximum number of choices
int MenuBattleSide::setNumberMaxChoices(const int &c)
{
	if ((unsigned)c < (unsigned)TEAM_BATTLE_MAX_NUMBER)
	{
		m_numberMaxChoices = c;

		if (m_selectedChoice >= m_numberMaxChoices)
			m_selectedChoice = c - 1;

		return 0;
	}

	return -1;
}


// Update the surfaces according to the ressource given
int MenuBattleSide::updateBar(int n, MenuBattleSide::e_menuBattleSideItems type, int act, int max)
{
	double ratio = (double)(act/max);

	if (ratio < 0.0)
		ratio = 0;

	if (!((unsigned)n < m_choices.size()))
		return -1;
	if ((type != MenuBattleSide::e_menuBattleSideItems::HP_IMAGE)
		&& (type != MenuBattleSide::e_menuBattleSideItems::MP_IMAGE)
		&& (type != MenuBattleSide::e_menuBattleSideItems::TP_IMAGE))
		return -1;

	// Update the bar surface
	std::dynamic_pointer_cast<SurfaceSprite>(m_choices.at(n)->getRealRenderTextureManager().getTheSurface((int)type)->second)->setTextureRect(
		sf::IntRect((1.0 - ratio)*HEALTH_SURFACE_WIDTH / 2,
			std::dynamic_pointer_cast<SurfaceSprite>(m_choices.at(n)->getRealRenderTextureManager().getTheSurface((int)type)->second)->getTextureRect().top,
			std::dynamic_pointer_cast<SurfaceSprite>(m_choices.at(n)->getRealRenderTextureManager().getTheSurface((int)type)->second)->getTextureRect().width,
			std::dynamic_pointer_cast<SurfaceSprite>(m_choices.at(n)->getRealRenderTextureManager().getTheSurface((int)type)->second)->getTextureRect().height
		)
	);

	// Update the text surface
	std::string text;

	if (type == MenuBattleSide::e_menuBattleSideItems::HP_IMAGE)
		text = HEALTH_NAME;
	else if (type == MenuBattleSide::e_menuBattleSideItems::MP_IMAGE)
		text = MANA_NAME;
	else
		text = SKILLPOINTS_NAME;

	text = text + " " + std::to_string(act) + "/" + std::to_string(max);

	std::dynamic_pointer_cast<SurfaceText>(m_choices.at(n)->getRealRenderTextureManager().getTheSurface((int)(type - 1))->second)->setString(text);

	return 0;
}


// Update health bar & text
int MenuBattleSide::updateHealth(int n, const Health& hp)
{
	return updateBar(n, MenuBattleSide::e_menuBattleSideItems::HP_IMAGE, hp.getPoints(), hp.getMaxPoints());
}


// Update mana bar & text
int MenuBattleSide::updateMana(int n, const Mana& mp)
{
	return updateBar(n, MenuBattleSide::e_menuBattleSideItems::MP_IMAGE, mp.getPoints(), mp.getMaxPoints());
}


// Load the menu
int MenuBattleSide::load(ManageRessources& ress, ManageSurfaces& surf, const int &x, const int &y, const int &w, const int &h)
{
	// [TODO]
	return 0;
}


// Update surfaces
int MenuBattleSide::update(Game &g)
{
	// [TODO]
	return 0;
}


// Close the menu
int MenuBattleSide::close(ManageSurfaces& surf)
{
	// [TODO]
	return 0;
}