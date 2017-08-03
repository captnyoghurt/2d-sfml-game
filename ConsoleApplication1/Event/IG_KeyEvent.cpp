#include "IG_KeyEvent.h"

IG_KeyEvent::IG_KeyEvent()
{
	m_action = IG_Action(&doNothing);
}


IG_KeyEvent::~IG_KeyEvent()
{
}

// Return the key of this in game key event
sf::Keyboard::Key IG_KeyEvent::getKey() const
{
	return m_key;
}


// Return the action done by this in game key event
IG_Action IG_KeyEvent::getIGAction() const
{
	return m_action;
}


// Modify the key of this in game key event
int IG_KeyEvent::setKey(sf::Keyboard::Key k)
{
	m_key = k;

	return 0;
}


// Modify the action done by this in game key event
int IG_KeyEvent::setIGAction(IG_Action act)
{
	m_action.setAction(act.getAction());

	return 0;
}


// Call the function this event is supposed to do
int IG_KeyEvent::doAction(Game &game)
{
	if (m_action.getAction() == NULL)
		return -1;
	return m_action.getAction()(game);
}