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
*  Menu to show the spells.
*
*/

#pragma once

#include <memory>
#include "MenuDialogBox.h"
#include "MenuChoice.h"
#include "../Battle/Status/Spell.h"

class MenuSpells :
	public Menu
{
public:
	MenuSpells(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~MenuSpells();

public:
	/**
	* \brief Return the spells	.
	*
	* \return std::vector<Spell> object.
	*/
	std::vector<Spell> getSpells() const;

	/**
	* \brief Return the dialog box with modifying possibilities	.
	*
	* \return MenuDialogBox& object.
	*/
	MenuDialogBox& getRealDialogBox();
	/**
	* \brief Return the menu choice with modifying possibilities	.
	*
	* \return MenuChoice& object.
	*/
	MenuChoice& getRealMenuChoices();
	/**
	* \brief Return the spells with modifying possibilities	.
	*
	* \return std::vector<Spell>& object.
	*/
	std::vector<Spell>& getRealSpells();

	/**
	* \brief Load the menu	.
	*
	* \return virtual object.
	*/
	virtual int load(ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, std::vector<Spell> &spells);
	/**
	* \brief Update surfaces	.
	*
	* \return virtual object.
	*/
	virtual int update(Game &g);
	/**
	* \brief Close the menu	.
	*
	* \return virtual object.
	*/
	virtual int close(ManageSurfaces &surf);

protected:
	/**
	* \brief Make a stringstream	.
	*
	* \return std::stringstream object.
	*/
	std::stringstream makeChoicesSS(std::vector<Spell> &spells);

public:
	MenuDialogBox m_dialogBox;
	MenuChoice m_choices;
	std::unique_ptr<std::vector<Spell>> m_spells;
};
