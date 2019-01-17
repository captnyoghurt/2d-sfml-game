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

#include "Inventory.h"



Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}


// Return the items
std::list< std::pair<Item, int> > Inventory::getItems() const
{
	return m_items;
}


// Return the orbs
std::list< std::pair<ItemOrb, int> > Inventory::getOrbs() const
{
	return m_orbs;
}


// Return the POE
std::list< std::pair<PieceOfEquipement, int> > Inventory::getPieceOfEquipement() const
{
	return m_pieceOfEquipement;
}


// Return the items with the modifying possibilities
std::list< std::pair<Item, int> >& Inventory::getRealItems()
{
	return m_items;
}


// Return the orbs with the modifying possibilities
std::list< std::pair<ItemOrb, int> >& Inventory::getRealOrbs()
{
	return m_orbs;
}


// Return the POE with the modifying possibilities
std::list< std::pair<PieceOfEquipement, int> >& Inventory::getRealPieceOfEquipement()
{
	return m_pieceOfEquipement;
}