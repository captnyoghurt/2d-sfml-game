#pragma once

#include <random>
#include "Fighter.h"

class Game;

class EnemiBasic : public Fighter
{
public:
	EnemiBasic();
	EnemiBasic(const Fighter &f);
	~EnemiBasic();

public:
	// Take a decision for the next battle action
	virtual std::shared_ptr<B_Event> chooseEvent(Game *g);

private:
	std::default_random_engine m_generator;
};

