#pragma once

#include <random>
#include "Fighter.h"

class EnemiBasic : public Fighter
{
public:
	EnemiBasic();
	~EnemiBasic();

public:
	// Take a decision for the next battle action
	virtual std::shared_ptr<B_Event> chooseEvent(Battle &b);

private:
	std::default_random_engine m_generator;
};

