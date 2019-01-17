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
*  Make a battle defense.
*
*/

#pragma once

#include "B_Event.h"

class B_EventDefense : public B_Event
{
public:
	B_EventDefense();
	B_EventDefense(std::shared_ptr<Fighter> dest, const std::string &description = "Unknown");
	~B_EventDefense();

public:
	/**
	* \brief Return if the fighter destination of the defense	.
	*
	* \return std::shared_ptr<Fighter> object.
	*/
	std::shared_ptr<Fighter> getDestination();

	/**
	* \brief Modify if the fighter destination of the defense	.
	*
	* \param dest The new value.
	* \return int object.
	*/
	int setDestination(std::shared_ptr<Fighter> dest);

	/**
	* \brief Do the event	.
	*
	* \return virtual object.
	*/
	virtual int execute(Battle *bat, ManageSound& snd);
private:
	std::shared_ptr<Fighter> m_destination;
};
