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
*  Manage all the animation to display.
*
*/

#include "../constants.h"
#include "../Game.h"
#include "ManageAnimation.h"
#include "../Error/debugFunctions.h"



ManageAnimation::ManageAnimation()
{
	m_clock.restart();
}


ManageAnimation::~ManageAnimation()
{
}


// Return all the curretn animations
std::list<Animation> ManageAnimation::getAnimations() const
{
	return m_animations;
}


// Return all the curretn animations with modification possibilities
std::list<Animation>& ManageAnimation::getRealAnimations()
{
	return m_animations;
}


// Add an animation
std::list<Animation>::iterator ManageAnimation::addAnimation(Animation a)
{
	m_animations.push_back(a);
	auto it(m_animations.end());
	--it;

#ifdef DEBUG_MODE_ON
	// Construction with copy constructor
	DEB_ALLOCATED_ANIMATION++;
#endif // DEBUG_MODE_ON

	return it;
}


// Update all the animations
int ManageAnimation::update(Game &g)
{
	if (m_clock.getElapsedTime().asMilliseconds() < ANIMATION_REFRESHING)
		return 0;

	std::list<Animation>::iterator it(m_animations.begin());

	while(it != m_animations.end())
	{
		int ret = it->update();

		if (ret == 3)
		{
			m_animations.erase(it++);
		}
		else
			++it;
		if (ret == 1)
		{
			g.getRealMap().gotUpdated();
		}
	}

	m_clock.restart();

	return 0;
}