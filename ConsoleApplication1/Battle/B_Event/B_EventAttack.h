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
*  Make an attack.
*
*/

#pragma once

#include "B_Event.h"
#include "../Fighters/Fighter.h"
#include <memory>

class B_EventAttack : public B_Event
{
public:
	explicit B_EventAttack(const std::string &description = "Attack");
	~B_EventAttack();

public:

	/**
	* \brief Do the event	.
	*
	* \return virtual object.
	*/
	virtual int execute(Battle *bat, ManageSound& snd);
private:

};
