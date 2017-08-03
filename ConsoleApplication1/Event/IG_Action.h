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
	IG_Action(s_action a);
	~IG_Action();

public:
	// Return the action (function)
	s_action getAction() const;

	// Modify the action (function)
	int setAction(s_action act);

private:
	s_action m_action;
};

////////////////////////////////////////////////////////////
// Used for the in game key that are useless
int doNothing(Game &);