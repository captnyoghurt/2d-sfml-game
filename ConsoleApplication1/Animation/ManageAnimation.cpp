#include "../constants.h"
#include "../Game.h"
#include "ManageAnimation.h"



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