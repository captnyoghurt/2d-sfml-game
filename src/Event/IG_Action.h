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
*  An action to play after a trigger.
*
*/

#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

// Break cyclic inclusions
class Game;


class IG_Action
{
public:
	typedef std::function<int(Game &)> s_action;

public:
	IG_Action();
	explicit IG_Action(const s_action &a);
	~IG_Action();

public:
	/**
	* \brief Return the action (function)	.
	*
	* \return s_action object.
	*/
	s_action getAction() const;

	/**
	* \brief Modify the action (function)	.
	*
	* \param act The new value.
	* \return int object.
	*/
	int setAction(s_action act);

private:
	s_action m_action;
};

////////////////////////////////////////////////////////////
// Used for the in game key that are useless
int doNothing(Game &);