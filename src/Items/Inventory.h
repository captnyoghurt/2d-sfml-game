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
*  Has every item in the bag.
*
*/

#pragma once

#include <list>
#include "Item.h"
#include "ItemOrb.h"
#include "PieceOfEquipement.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

public:
	/**
	* \brief Return the items	.
	*
	* \return std::list< object.
	*/
	std::list< std::pair<Item, int> > getItems() const;
	/**
	* \brief Return the orbs	.
	*
	* \return std::list< object.
	*/
	std::list< std::pair<ItemOrb, int> > getOrbs() const;
	/**
	* \brief Return the POE	.
	*
	* \return std::list< object.
	*/
	std::list< std::pair<PieceOfEquipement, int> > getPieceOfEquipement() const;

	/**
	* \brief Return the items with the modifying possibilities	.
	*
	* \return std::list< object.
	*/
	std::list< std::pair<Item, int> >& getRealItems();
	/**
	* \brief Return the orbs with the modifying possibilities	.
	*
	* \return std::list< object.
	*/
	std::list< std::pair<ItemOrb, int> >& getRealOrbs();
	/**
	* \brief Return the POE with the modifying possibilities	.
	*
	* \return std::list< object.
	*/
	std::list< std::pair<PieceOfEquipement, int> >& getRealPieceOfEquipement();

private:
	std::list< std::pair<Item, int> > m_items;
	std::list< std::pair<ItemOrb, int> > m_orbs;
	std::list< std::pair<PieceOfEquipement, int> > m_pieceOfEquipement;
};
