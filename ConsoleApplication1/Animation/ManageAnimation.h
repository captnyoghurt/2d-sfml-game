#pragma once

#include "Animation.h"

class Game;

class ManageAnimation
{
public:
	ManageAnimation();
	~ManageAnimation();

public:
	// Return all the curretn animations
	std::list<Animation> getAnimations() const;

	// Return all the curretn animations with modification possibilities
	std::list<Animation>& getRealAnimations();

	// Add an animation
	std::list<Animation>::iterator addAnimation(Animation a);

	// Update all the animations
	int update(Game &g);

private:
	std::list<Animation> m_animations;
	sf::Clock m_clock;
};

