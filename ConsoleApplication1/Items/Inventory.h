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
	std::list< std::pair<Item, int> > getItems() const;
	// Return the orbs
	std::list< std::pair<ItemOrb, int> > getOrbs() const;
	// Return the POE
	std::list< std::pair<PieceOfEquipement, int> > getPieceOfEquipement() const;

	// Return the items with the modifying possibilities
	std::list< std::pair<Item, int> >& getRealItems();
	// Return the orbs with the modifying possibilities
	std::list< std::pair<ItemOrb, int> >& getRealOrbs();
	// Return the POE with the modifying possibilities
	std::list< std::pair<PieceOfEquipement, int> >& getRealPieceOfEquipement();

private:
	std::list< std::pair<Item, int> > m_items;
	std::list< std::pair<ItemOrb, int> > m_orbs;
	std::list< std::pair<PieceOfEquipement, int> > m_pieceOfEquipement;
};

