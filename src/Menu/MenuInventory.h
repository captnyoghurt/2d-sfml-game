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
*  Menu to show the bag.
*
*/

#pragma once

#include "../Items/Item.h"
#include "Menu.h"
#include "MenuDialogBox.h"
#include "MenuChoice.h"


class MenuInventory :
	public Menu
{
public:
	MenuInventory(ManageRessources& ress, ManageSurfaces& surf, int lastEventLayer);
	~MenuInventory();

public:
	/**
	* \brief Return the spells	.
	*
	* \return std::vector< object.
	*/
	std::vector< std::pair<Item, int> > getItems() const;

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
	* \return std::vector< object.
	*/
	std::vector< std::pair<Item, int> >& getRealItems();

	/**
	* \brief Load the menu	.
	*
	* \return virtual object.
	*/
	virtual int load(ManageRessources& ress, ManageSurfaces& surf, const int &xcam, const int &ycam, std::list< std::pair<Item, int> > &items, std::vector<bool> enabledTypes);
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
	std::stringstream makeChoicesSS(std::list< std::pair<Item, int> > &items);

private:
	MenuDialogBox m_dialogBox;
	MenuChoice m_choices;
	std::vector< std::pair<Item, int> > m_items;
};
