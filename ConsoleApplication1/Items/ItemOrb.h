#pragma once

#include "Item.h"

class ItemOrb :
	public Item
{
public:
	ItemOrb();
	ItemOrb(const int &id, const std::string &name, const std::string &description);
	explicit ItemOrb(const Item &item);
	~ItemOrb();
};

