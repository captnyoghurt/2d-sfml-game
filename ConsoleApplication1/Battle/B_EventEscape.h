#pragma once

#include "B_Event.h"

class B_EventEscape : public B_Event
{
public:
	B_EventEscape();
	~B_EventEscape();

public:

private:
	std::shared_ptr<Fighter> m_source;
};

