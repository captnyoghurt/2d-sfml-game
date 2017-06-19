#include "IG_Action.h"



IG_Action::IG_Action()
{
}


IG_Action::IG_Action(IG_Action::s_action a)
{
	m_action = a;
}


IG_Action::~IG_Action()
{
}


// Return the action (function)
IG_Action::s_action IG_Action::getAction() const
{
	return m_action;
}


// Modify the action (function)
int IG_Action::setAction(IG_Action::s_action act)
{
	m_action = act;
	return 0;
}


////////////////////////////////////////////////////////////
// Used for the in game key that are useless
int doNothing(Game &)
{
	return 0;
}