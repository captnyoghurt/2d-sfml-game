#include "ItemOrb.h"



ItemOrb::ItemOrb()
{
}

ItemOrb::ItemOrb(const int &id, const std::string &name, const std::string &description) :
	Item(id, name, description, 0, 0, 0, Item::e_ItemType::ITEM_ORB)
{

}

ItemOrb::ItemOrb(const Item &item) :
	Item(item)
{

}

ItemOrb::~ItemOrb()
{
}
