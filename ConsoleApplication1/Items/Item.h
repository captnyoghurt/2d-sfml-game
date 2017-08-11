#pragma once

#include <deque>
#include <string>
#include "../Battle/BattleEffects.h"


class Item
{
public:
	enum e_ItemType { ITEM_CLASSIC, ITEM_CONSUMABLE_BATTLE, ITEM_CONSUMABLE_OUT, ITEM_CONSUMABLE, ITEM_EQUIPEMENT, ITEM_TOTAL };

public:
	Item();
	~Item();

public:
	// Return the id
	int getId() const;
	// Return the name
	std::string getName() const;
	// Return the description
	std::string getDescription() const;
	// Return the price when bought
	int getPriceBuy() const;
	// Return the price when sold
	int getPriceSell() const;
	// Return the type of the item
	e_ItemType getType() const;
	// Return the effects
	std::deque<BattleEffects> getEffects() const;

	// Return the effects with modifying possibilities
	std::deque<BattleEffects>& getRealEffects();

	// Modify the id
	int setId(const int &id);
	// Modify the name
	int setName(const std::string &name);
	// Modify the description
	int setDescription(const std::string &description);
	// Modify the price when bought
	int setPriceBuy(const int &p);
	// Modify the price when sold
	int setPriceSell(const int &p);
	// Modify the type of the item
	int setType(const e_ItemType &t);

private:
	int m_id;
	std::string m_name;
	std::string m_description;
	int m_priceBuy;
	int m_priceSell;
	e_ItemType m_type;
	std::deque<BattleEffects> m_effects;
};

