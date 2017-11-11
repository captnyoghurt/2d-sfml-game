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
*  Health of a fighter.
*
*/

#pragma once

#include <list>
#include "EffectOnCharacteristic.h"

class Spell;

class Health
{
public:
	Health();
	Health(const Health &h);
	explicit Health(const int &max);
	~Health();

	Health& operator=(const Health& h);
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
	* \brief Return all the actual effects	.
	*
	* \return std::list<EffectOnCharacteristic> object.
	*/
	std::list<EffectOnCharacteristic> getEffects() const;
	/**
	* \brief Return all the actual adding effects	.
	*
	* \return std::list<EffectOnCharacteristic> object.
	*/
	std::list<EffectOnCharacteristic> getContinuousEffects() const;

	/**
	* \brief Return all the actual effects with modifying possibilities	.
	*
	* \return std::list<EffectOnCharacteristic>& object.
	*/
	std::list<EffectOnCharacteristic>& getRealEffects();
	/**
	* \brief Return all the actual adding effects with modifying possibilities	.
	*
	* \return std::list<EffectOnCharacteristic>& object.
	*/
	std::list<EffectOnCharacteristic>& getRealContinuousEffects();

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
	std::list<EffectOnCharacteristic> m_continuousEffects;
};
