#pragma once

#include <SFML/Graphics.hpp>
#include "IG_Action.h"

// Break cyclic inclusions
class Game;

class IG_KeyEvent
{
public:
	IG_KeyEvent();
	~IG_KeyEvent();

public:
	// Return the key of this in game key event
	sf::Keyboard::Key getKey() const;
	// Return the action done by this in game key event
	IG_Action getIGAction() const;

	// Modify the key of this in game key event
	int setKey(sf::Keyboard::Key k);
	// Modify the action done by this in game key event
	int setIGAction(IG_Action act);

	// Call the function this event is supposed to do
	int doAction(Game &game);
private:
	sf::Keyboard::Key m_key;
	IG_Action m_action;
};