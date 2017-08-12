#include "Inventory.h"



Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}


// Return the items
std::list<Item> Inventory::getItems() const
{
	return m_items;
}


// Return the orbs
std::list<ItemOrb> Inventory::getOrbs() const
{
	return m_orbs;
}


// Return the POE
std::list<PieceOfEquipement> Inventory::getPieceOfEquipement() const
{
	return m_pieceOfEquipement;
}


// Return the items with the modifying possibilities
std::list<Item>& Inventory::getRealItems()
{
	return m_items;
}


// Return the orbs with the modifying possibilities
std::list<ItemOrb>& Inventory::getRealOrbs()
{
	return m_orbs;
}


// Return the POE with the modifying possibilities
std::list<PieceOfEquipement>& Inventory::getRealPieceOfEquipement()
{
	return m_pieceOfEquipement;
}