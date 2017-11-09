#include "Item.h"
#include "../Error/ValueException.h"
#include "../constants.h"



Item::Item() :
	m_id(-1),
	m_name(""),
	m_description(""),
	m_priceBuy(0),
	m_priceSell(0),
	m_iconId(0),
	m_type(Item::e_ItemType::ITEM_CLASSIC)
{
}

Item::Item(const int &id, const std::string &name, const std::string &description, const int &priceBuy, const int &priceSell, const int &iconId, const Item::e_ItemType &type) :
	m_id(id),
	m_name(name),
	m_description(description),
	m_priceBuy(priceBuy),
	m_priceSell(priceSell),
	m_iconId(iconId),
	m_type(type)
{

}

Item::Item(const Item &item)
{
	m_id = item.getId();
	m_name = item.getName();
	m_description = item.getDescription();
	m_priceBuy = item.getPriceBuy();
	m_priceSell = item.getPriceSell();
	m_type = item.getType();
	m_effects = item.getEffects();
}


Item::~Item()
{
}


Item& Item::operator=(const Item &item)
{
	m_id = item.getId();
	m_name = item.getName();
	m_description = item.getDescription();
	m_priceBuy = item.getPriceBuy();
	m_priceSell = item.getPriceSell();
	m_type = item.getType();
	m_effects = item.getEffects();

	return *this;
}


// Return the id
int Item::getId() const
{
	return m_id;
}


// Return the name
std::string Item::getName() const
{
	return m_name;
}


// Return the description
std::string Item::getDescription() const
{
	return m_description;
}


// Return the price when bought
int Item::getPriceBuy() const
{
	return m_priceBuy;
}


// Return the price when sold
int Item::getPriceSell() const
{
	return m_priceSell;
}


// Modify the icon id of the item
int Item::getIconId() const
{
	return m_iconId;
}


// Return the type of the item
Item::e_ItemType Item::getType() const
{
	return m_type;
}


// Return the effects
std::deque<BattleEffects> Item::getEffects() const
{
	return m_effects;
}


// Return the effects with modifying possibilities
std::deque<BattleEffects>& Item::getRealEffects()
{
	return m_effects;
}


// Modify the id
int Item::setId(const int &id)
{
	if (id < 0)
		THROW_VALUE("Impossible id : " + std::to_string(id));

	m_id = id;

	return 0;
}


// Modify the name
int Item::setName(const std::string &name)
{
	m_name = name;

	return 0;
}


// Modify the description
int Item::setDescription(const std::string &description)
{
	m_description = description;

	return 0;
}


// Modify the price when bought
int Item::setPriceBuy(const int &p)
{
	if (p < 0)
		THROW_VALUE("Impossible price : " + std::to_string(p));

	m_priceBuy = p;

	return 0;
}


// Modify the price when sold
int Item::setPriceSell(const int &p)
{
	if (p < 0)
		THROW_VALUE("Impossible price : " + std::to_string(p));

	m_priceSell = p;

	return 0;
}


// Modify the icon id of the item
int Item::setIconId(const int &id)
{
	if (!((unsigned)id < ICONS_SURFACE_BY_COLUMN*ICONS_SURFACE_BY_LINE))
		THROW_VALUE("Wrong value of icon id : " + std::to_string(id));

	m_iconId = id;

	return 0;
}


// Modify the type of the item
int Item::setType(const Item::e_ItemType &t)
{
	if (t < 0 || t >= Item::e_ItemType::ITEM_TOTAL)
		THROW_VALUE("Impossible type of item value : " + std::to_string(t));

	m_type = t;

	return 0;
}