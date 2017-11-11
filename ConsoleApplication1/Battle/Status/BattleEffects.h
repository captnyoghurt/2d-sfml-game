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
*  An effect in the battle.
*
*/

#pragma once

#include "Characteristic.h"

class BattleEffects
{
public:
	enum e_EffectsTarget {ET_ALLY, ET_ENEMI, ET_ALL};

public:
	BattleEffects();
	BattleEffects(const int id, const Characteristic::e_characteristics &c, const int &chance, const int &power, const e_EffectsTarget &et, const int &people);
	BattleEffects(const BattleEffects &be);
	~BattleEffects();

	BattleEffects& operator=(const BattleEffects &be);
public:
	/**
	* \brief Return the id	.
	*
	* \return int object.
	*/
	int getId() const;
	/**
	* \brief Return the characteristic	.
	*
	* \return Characteristic::e_characteristics object.
	*/
	Characteristic::e_characteristics getCharacteristic() const;
	/**
	* \brief Return the chance	.
	*
	* \return int object.
	*/
	int getChance() const;
	/**
	* \brief Return the power	.
	*
	* \return int object.
	*/
	int getPower() const;
	/**
	* \brief Return the target type	.
	*
	* \return e_EffectsTarget object.
	*/
	e_EffectsTarget getTargetType() const;
	/**
	* \brief Return the number of people	.
	*
	* \return int object.
	*/
	int getNumberOfPeople() const;

	/**
	* \brief Modify the id	.
	*
	* \param id The new value.
	* \return int object.
	*/
	int setId(const int &id);
	/**
	* \brief Modify the characteristic	.
	*
	* \param c The new value.
	* \return int object.
	*/
	int setCharacteristic(const Characteristic::e_characteristics &c);
	/**
	* \brief Modify the chance	.
	*
	* \param ch The new value.
	* \return int object.
	*/
	int setChance(const int &ch);
	/**
	* \brief Modify the power	.
	*
	* \param po The new value.
	* \return int object.
	*/
	int setPower(const int &po);
	/**
	* \brief Modify the target type	.
	*
	* \param et The new value.
	* \return int object.
	*/
	int setTargetType(const e_EffectsTarget &et);
	/**
	* \brief Modify the number of people	.
	*
	* \param n The new value.
	* \return int object.
	*/
	int setNumberOfPeople(const int &n);

private:
	int m_id;
	Characteristic::e_characteristics m_characteristic;
	int m_chance;
	int m_power;
	e_EffectsTarget m_targetType;
	int m_numberOfPeople;
};
