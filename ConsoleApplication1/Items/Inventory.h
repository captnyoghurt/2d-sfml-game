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
	// Return the items
	std::list<Item> getItems() const;
	// Return the orbs
	std::list<ItemOrb> getOrbs() const;
	// Return the POE
	std::list<PieceOfEquipement> getPieceOfEquipement() const;

	// Return the items with the modifying possibilities
	std::list<Item>& getRealItems();
	// Return the orbs with the modifying possibilities
	std::list<ItemOrb>& getRealOrbs();
	// Return the POE with the modifying possibilities
	std::list<PieceOfEquipement>& getRealPieceOfEquipement();

private:
	std::list<Item> m_items;
	std::list<ItemOrb> m_orbs;
	std::list<PieceOfEquipement> m_pieceOfEquipement;
};

