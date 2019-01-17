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
*  Call the actions according to the trigger.
*
*/

#pragma once

#include <vector>
#include "IG_KeyEvent.h"


class ManageEvent
{
public:
	ManageEvent();
	~ManageEvent();

public:
	/**
	* \brief Return the actual key event layer	.
	*
	* \return int object.
	*/
	int getKeyEventLayer() const;
	/**
	* \brief Return the key event list	.
	*
	* \return std::vector< object.
	*/
	std::vector< std::vector< std::pair<unsigned short, unsigned short> > > getKeyEventList() const;
	/**
	* \brief Retuen the maching key event list	.
	*
	* \return std::vector<IG_KeyEvent> object.
	*/
	std::vector<IG_KeyEvent> getMatchingKeyEvent() const;

	/**
	* \brief Modify the actual key event layer	.
	*
	* \param l The new value.
	* \return int object.
	*/
	int setKeyEventLayer(const int &l);
	/**
	* \brief Modify a key event	.
	*
	* \param true The new value.
	* \return int object.
	*/
	int setKeyEvent(int layer, int code, unsigned short matchCode, bool down = true);
	
	/**
	* \brief Create a matching	.
	*
	* \return unsigned object.
	*/
	unsigned short createMatchingKey(const IG_KeyEvent &k);
	unsigned short createMatchingKey(IG_Action a);
	/**
	* \brief Create the layers	.
	*
	* \return int object.
	*/
	int createLayers(const int &l);
	
	/**
	* \brief Update event	.
	*
	* \return int object.
	*/
	int updateEvent(Game &g);
private:
	int m_keyEventLayer;
	std::vector< std::vector< std::pair<unsigned short, unsigned short> > > m_keyEventList;
	std::vector<IG_KeyEvent> m_matchingKeyEvent;
};
