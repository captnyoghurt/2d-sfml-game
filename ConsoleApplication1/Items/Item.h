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
*  A simple item.
*
*/

#pragma once

#include <deque>
#include <string>
#include "../Battle/Status/BattleEffects.h"


class Item
{
public:
	enum e_ItemType { ITEM_CLASSIC, ITEM_CONSUMABLE_BATTLE, ITEM_CONSUMABLE_OUT, ITEM_CONSUMABLE, ITEM_EQUIPEMENT, ITEM_ORB, ITEM_TOTAL };

public:
	Item();
	Item(const int &id, const std::string &name, const std::string &description, const int &priceBuy, const int &priceSell, const int &iconId, const Item::e_ItemType &type);
	Item(const Item &item);
	~Item();

	Item& operator=(const Item &item);
public:
	/**
	* \brief Return the id	.
	*
	* \return int object.
	*/
	int getId() const;
	/**
	* \brief Return the name	.
	*
	* \return std::string object.
	*/
	std::string getName() const;
	/**
	* \brief Return the description	.
	*
	* \return std::string object.
	*/
	std::string getDescription() const;
	/**
	* \brief Return the price when bought	.
	*
	* \return int object.
	*/
	int getPriceBuy() const;
	/**
	* \brief Return the price when sold	.
	*
	* \return int object.
	*/
	int getPriceSell() const;
	/**
	* \brief Return the icon id of the item	.
	*
	* \return int object.
	*/
	int getIconId() const;
	/**
	* \brief Return the type of the item	.
	*
	* \return e_ItemType object.
	*/
	e_ItemType getType() const;
	/**
	* \brief Return the effects	.
	*
	* \return std::deque<BattleEffects> object.
	*/
	std::deque<BattleEffects> getEffects() const;

	/**
	* \brief Return the effects with modifying possibilities	.
	*
	* \return std::deque<BattleEffects>& object.
	*/
	std::deque<BattleEffects>& getRealEffects();

	/**
	* \brief Modify the id	.
	*
	* \param id The new value.
	* \return int object.
	*/
	int setId(const int &id);
	/**
	* \brief Modify the name	.
	*
	* \param name The new value.
	* \return int object.
	*/
	int setName(const std::string &name);
	/**
	* \brief Modify the description	.
	*
	* \param description The new value.
	* \return int object.
	*/
	int setDescription(const std::string &description);
	/**
	* \brief Modify the price when bought	.
	*
	* \param p The new value.
	* \return int object.
	*/
	int setPriceBuy(const int &p);
	/**
	* \brief Modify the price when sold	.
	*
	* \param p The new value.
	* \return int object.
	*/
	int setPriceSell(const int &p);
	/**
	* \brief Modify the icon id of the item	.
	*
	* \param id The new value.
	* \return int object.
	*/
	int setIconId(const int &id);
	/**
	* \brief Modify the type of the item	.
	*
	* \param t The new value.
	* \return int object.
	*/
	int setType(const e_ItemType &t);

private:
	int m_id;
	std::string m_name;
	std::string m_description;
	int m_priceBuy;
	int m_priceSell;
	int m_iconId;
	e_ItemType m_type;
	std::deque<BattleEffects> m_effects;
};
