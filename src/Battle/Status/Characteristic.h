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
*  A characteristic of a fighter.
*
*/

#pragma once

#include <list>
#include "EffectOnCharacteristic.h"

class Spell;

class Characteristic
{
public:
	enum e_characteristics {STRENGH, INTELLIGENCE, VITALITY, AGILITY, SPEED, REGEN_MP, ATTACK_PHYSIC, ATTACK_MAGIC, DEFENSE_PHYSIC, DEFENSE_MAGIC, RESISTANCE_SLEEP, RESISTANCE_POISON, RESISTANCE_PARALYSIS, RESISTANCE_MUTE, CHARACTERISTICS_TOTAL};

public:
	Characteristic();
	Characteristic(int points, int maxPoints);
	Characteristic(const Characteristic& c);
	~Characteristic();

	Characteristic& operator=(const Characteristic &c);
public:
	/**
	* \brief Return the number of health points	.
	*
	* \return int object.
	*/
	int getPoints() const;
	/**
	* \brief Return the maximum number of health points	.
	*
	* \return int object.
	*/
	int getMaxPoints() const;
	/**
	* \brief Return the actual health bonus	.
	*
	* \return int object.
	*/
	int getBonus() const;
	/**
	* \brief Return the total amount of points	.
	*
	* \return int object.
	*/
	int getValue() const;
	/**
	* \brief Return all the actual effects	.
	*
	* \return std::list<EffectOnCharacteristic> object.
	*/
	std::list<EffectOnCharacteristic> getEffects() const;

	/**
	* \brief Return all the actual effects with modifying possibilities	.
	*
	* \return std::list<EffectOnCharacteristic>& object.
	*/
	std::list<EffectOnCharacteristic>& getRealEffects();

	/**
	* \brief Modify the number of health points	.
	*
	* \param p The new value.
	* \return int object.
	*/
	int setPoints(const int &p);
	/**
	* \brief Modify the maximum number of health	.
	*
	* \param maxp The new value.
	* \return int object.
	*/
	int setMaxPoints(const int &maxp);

	/**
	* \brief Say if a spell can be used	.
	*
	* \return bool object.
	*/
	bool canCastSpell(const Spell &sp);
	/**
	* \brief Say if there is enought health	.
	*
	* \return bool object.
	*/
	bool enoughFor(const int &points);

	/**
	* \brief Use some health points	.
	*
	* \return int object.
	*/
	int use(const int &points);
	int use(const Spell &sp);
	/**
	* \brief Get some health points	.
	*
	* \return int object.
	*/
	int recharge(const int &points);
	/**
	* \brief Update effects	.
	*
	* \return int object.
	*/
	int updateEffects();

private:
	int m_maxPoints;
	int m_points;
	int m_bonus;
	std::list<EffectOnCharacteristic> m_effects;
};
