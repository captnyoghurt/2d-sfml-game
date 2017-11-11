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
*  Enemi team.
*
*/

#pragma once

#include <vector>
#include "Fighter.h"

class Enemies
{
public:
	Enemies();
	Enemies(const Enemies &enemie, int number = -1);
	~Enemies();

public:
	/**
	* \brief Return the number of team mate alive	.
	*
	* \return int object.
	*/
	int getNumberFighterAlive() const;
	/**
	* \brief Return the team mate vector	.
	*
	* \return std::vector<std::shared_ptr<Fighter>> object.
	*/
	std::vector<std::shared_ptr<Fighter>> getTeam();

	/**
	* \brief Return the team mate vector with modifying possibilities	.
	*
	* \return std::vector<std::shared_ptr<Fighter>>& object.
	*/
	std::vector<std::shared_ptr<Fighter>>& getRealTeam();

	/**
	* \brief Add a new member	.
	*
	* \return int object.
	*/
	int addMember(Fighter m);
	int addMember(std::shared_ptr<Fighter> f);

	/**
	* \brief Update the team batttle	.
	*
	* \return int object.
	*/
	int update();
	/**
	* \brief Clear the enemy team	.
	*
	* \return int object.
	*/
	int clear();
private:
	int m_numberFighterAlive;
	std::vector<std::shared_ptr<Fighter>> m_fighters;
};
