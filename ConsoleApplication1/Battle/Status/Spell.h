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
*  A spell of a fighter. Can be cast.
*
*/

#pragma once

#include <deque>
#include "BattleEffects.h"

class Spell
{
public:
	Spell();
	Spell(int id, const std::string name, int damage, int allyDestination, int enemiDestination, int costHP, int costMP, int costTP, int chanceSleep, int chancePoison, int chanceParalysis, int chanceMute, int iconId, const std::string &desc);
	Spell(const Spell &sp);
	~Spell();

	Spell& operator=(const Spell &sp);
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
	* \brief Return the damage	.
	*
	* \return int object.
	*/
	int getDamage() const;
	/**
	* \brief Return ally destination	.
	*
	* \return int object.
	*/
	int getAllyDestination() const;
	/**
	* \brief Return the enemi destination	.
	*
	* \return int object.
	*/
	int getEnemiDestination() const;
	/**
	* \brief Return the hp cost	.
	*
	* \return int object.
	*/
	int getCostHP() const;
	/**
	* \brief Return the mp cost	.
	*
	* \return int object.
	*/
	int getCostMP() const;
	/**
	* \brief Return the tp cost	.
	*
	* \return int object.
	*/
	int getCostTP() const;
	/**
	* \brief Return the chance of sleep	.
	*
	* \return int object.
	*/
	int getChanceSleep() const;
	/**
	* \brief Return the chance of poison	.
	*
	* \return int object.
	*/
	int getChancePoison() const;
	/**
	* \brief Return the chance of paralysis	.
	*
	* \return int object.
	*/
	int getChanceParalysis() const;
	/**
	* \brief Return the chance of mute	.
	*
	* \return int object.
	*/
	int getChanceMute() const;
	/**
	* \brief Return the icon id	.
	*
	* \return int object.
	*/
	int getIconId() const;
	/**
	* \brief Return the battle effects	.
	*
	* \return std::deque<BattleEffects> object.
	*/
	std::deque<BattleEffects> getEffects() const;
	/**
	* \brief Return the description	.
	*
	* \return std::string object.
	*/
	std::string getDescription() const;

	/**
	* \brief Return the battle effects with modifying possibilities	.
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
	* \brief Modify the damage	.
	*
	* \param d The new value.
	* \return int object.
	*/
	int setDamage(const int &d);
	/**
	* \brief Modify ally destination	.
	*
	* \param ad The new value.
	* \return int object.
	*/
	int setAllyDestination(const int &ad);
	/**
	* \brief Modify enemi destination	.
	*
	* \param ed The new value.
	* \return int object.
	*/
	int setEnemiDestination(const int &ed);
	/**
	* \brief Modify the hp cost	.
	*
	* \param cost The new value.
	* \return int object.
	*/
	int setCostHP(const int &cost);
	/**
	* \brief Modify the mp cost	.
	*
	* \param cost The new value.
	* \return int object.
	*/
	int setCostMP(const int &cost);
	/**
	* \brief Modify the tp cost	.
	*
	* \param cost The new value.
	* \return int object.
	*/
	int setCostTP(const int &cost);
	/**
	* \brief Modify the chance of sleep	.
	*
	* \param chance The new value.
	* \return int object.
	*/
	int setChanceSleep(const int &chance);
	/**
	* \brief Modify the chance of poison	.
	*
	* \param chance The new value.
	* \return int object.
	*/
	int setChancePoison(const int &chance);
	/**
	* \brief Modify the chance of paralysis	.
	*
	* \param chance The new value.
	* \return int object.
	*/
	int setChanceParalysis(const int &chance);
	/**
	* \brief Modify the chance of mute	.
	*
	* \param chance The new value.
	* \return int object.
	*/
	int setChanceMute(const int &chance);
	/**
	* \brief Modify the id icon	.
	*
	* \param id The new value.
	* \return int object.
	*/
	int setIconId(const int &id);
	/**
	* \brief Modify the description	.
	*
	* \param des The new value.
	* \return int object.
	*/
	int setDescription(const std::string &des);

	/**
	* \brief Add an effect	.
	*
	* \return int object.
	*/
	int addEffect(const BattleEffects &be);

public:
	int m_id;
	std::string m_name;
	int m_damage;
	int m_allyDestination;
	int m_enemiDestination;
	int m_costHP;
	int m_costMP;
	int m_costTP;
	int m_chanceSleep;
	int m_chancePoison;
	int m_chanceParalysis;
	int m_chanceMute;
	int m_iconId;
	std::deque<BattleEffects> m_effects;
	std::string m_description;
};
