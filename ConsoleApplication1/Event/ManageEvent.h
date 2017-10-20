#pragma once

#include <vector>
#include "IG_KeyEvent.h"


class ManageEvent
{
public:
	ManageEvent();
	~ManageEvent();

public:
	// Return the actual key event layer
	int getKeyEventLayer() const;
	// Return the key event list
	std::vector< std::vector< std::pair<unsigned short, unsigned short> > > getKeyEventList() const;
	// Retuen the maching key event list
	std::vector<IG_KeyEvent> getMatchingKeyEvent() const;

	// Modify the actual key event layer
	int setKeyEventLayer(const int &l);
	// Modify a key event
	int setKeyEvent(int layer, int code, unsigned short matchCode, bool down = true);
	
	// Create a matching
	unsigned short createMatchingKey(const IG_KeyEvent &k);
	unsigned short createMatchingKey(IG_Action a);
	// Create the layers
	int createLayers(const int &l);
	
	// Update event
	int updateEvent(Game &g);
private:
	int m_keyEventLayer;
	std::vector< std::vector< std::pair<unsigned short, unsigned short> > > m_keyEventList;
	std::vector<IG_KeyEvent> m_matchingKeyEvent;
};

