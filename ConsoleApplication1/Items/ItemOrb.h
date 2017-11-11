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
*  An orb, which can give a bonus.
*
*/

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
