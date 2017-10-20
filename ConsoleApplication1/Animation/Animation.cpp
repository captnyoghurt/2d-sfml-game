#include "Animation.h"
#include "../Error/ValueException.h"
#include "../Error/debugFunctions.h"


Animation::Animation(int refreshTime, const std::vector<sf::Rect<short>>& rects, std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator surf) :
	m_rectSprites(rects)
{
	m_refreshTime = refreshTime;
	m_rectAct = 0;
	m_surface = surf;
	m_finished = true;
	m_killWhenDone = false;
	m_moving = false;
	m_manathanDistance = 0;
	m_nbLoop = 0;
	m_endX = 0;
	m_endY = 0;
#ifdef DEBUG_MODE_ON
	DEB_ALLOCATED_ANIMATION++;
#endif // DEBUG_MODE_ON

}
Animation::Animation(int refreshTime, const std::vector<sf::Rect<short>>& rects, std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator surf, int loop, bool killWhenDone) :
	m_rectSprites(rects)
{
	m_refreshTime = refreshTime;
	m_rectAct = 0;
	m_surface = surf;
	m_nbLoop = loop;
	m_killWhenDone = killWhenDone;
	m_finished = false;
	m_clock.restart();
	m_moving = false;
	m_manathanDistance = 0;
	m_endX = 0;
	m_endY = 0;
#ifdef DEBUG_MODE_ON
	DEB_ALLOCATED_ANIMATION++;
#endif // DEBUG_MODE_ON
}
Animation::Animation(int refreshTime, const std::vector<sf::Rect<short>>& rects, std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator surf, int endX, int endY, int manDist, int loop, bool killWhenDone) :
	m_rectSprites(rects)
{
	m_refreshTime = refreshTime;
	m_rectAct = 0;
	m_surface = surf;
	m_nbLoop = loop;
	m_killWhenDone = killWhenDone;
	m_finished = false;
	m_endX = endX;
	m_endY = endY;
	m_manathanDistance = manDist;
	m_clock.restart();
	m_moving = true;
#ifdef DEBUG_MODE_ON
	DEB_ALLOCATED_ANIMATION++;
#endif // DEBUG_MODE_ON
}

Animation::~Animation()
{
#ifdef DEBUG_MODE_ON
	DEB_ALLOCATED_ANIMATION--;
#endif // DEBUG_MODE_ON
}


// Return if the animation moves
bool Animation::getMoving() const
{
	return m_moving;
}


// Return if the animation is finished
bool Animation::getFinished() const
{
	return m_finished;
}


// Return if the animation is supposed to be killed when its done
bool Animation::getKillWhenDone() const
{
	return m_killWhenDone;
}


// Return the remaining number of loop
int Animation::getNbLoop() const
{
	return m_nbLoop;
}


// Return the animation refresh time
int Animation::getRefreshTime() const
{
	return m_refreshTime;
}


// Return the distance walked by the animation at each call
int Animation::getManathanDistance() const
{
	return m_manathanDistance;
}


// Return the destination position X
int Animation::getEndX() const
{
	return m_endX;
}


// Return the destination position Y
int Animation::getEndY() const
{
	return m_endY;
}


// Return the location of the sprites rect
std::vector<sf::Rect<short>> Animation::getRectSprites() const
{
	return m_rectSprites;
}


// Modify the animation refresh time
int Animation::setRefreshTime(const int &t)
{
	if (t <= 0)
		THROW_VALUE(std::to_string(t));

	m_refreshTime = t;

	return 0;
}


// Return the surface used
std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator Animation::getRealSurface()
{
	return m_surface;
}


// Stop instantly the animation
int Animation::stop()
{
	m_finished = true;

	return 0;
}


// Stop after the end of the animation
int Animation::stopAfter()
{
	m_nbLoop = 1;

	return 0;
}


// Kill instantly the animation
int Animation::kill()
{
	m_finished = true;

	m_killWhenDone = true;

#ifdef DEBUG_MODE_ON
	DEB_ALLOCATED_ANIMATION--;
#endif // DEBUG_MODE_ON

	return 1;
}


// Update the animation
int Animation::update()
{
	if (m_finished)
	{
		if (m_killWhenDone)
			return 3;
		return 2;
	}

	if (m_clock.getElapsedTime().asMilliseconds() >= m_refreshTime)
	{
		m_rectAct++;
		if ((unsigned)m_rectAct >= m_rectSprites.size())
		{
			m_rectAct = 0;
			m_nbLoop--;
			if (m_nbLoop == 0)
			{
				m_finished = true;
				std::dynamic_pointer_cast<SurfaceSprite>(m_surface->second)->setTextureRect(sf::IntRect(m_rectSprites.at(0).left, m_rectSprites.at(0).top, m_rectSprites.at(0).width, m_rectSprites.at(0).height));
				return 1;
			}
		}
		std::dynamic_pointer_cast<SurfaceSprite>(m_surface->second)->setTextureRect(sf::IntRect(m_rectSprites.at(m_rectAct).left, m_rectSprites.at(m_rectAct).top, m_rectSprites.at(m_rectAct).width, m_rectSprites.at(m_rectAct).height));
		m_clock.restart();
		return 1;
	}

	return 0;
}


// Start the animation
int Animation::start(int endX, int endY, int manDist, int loop, bool killWhenDone)
{
	m_finished = false;
	m_endX = endX;
	m_endY = endY;
	m_manathanDistance = manDist;
	m_nbLoop = loop;
	m_killWhenDone = killWhenDone;
	m_rectAct = 0;
	m_clock.restart();

	return 0;
}
int Animation::start(int loop, bool killWhenDone)
{
	m_finished = false;
	m_nbLoop = loop;
	m_killWhenDone = killWhenDone;
	m_rectAct = 0;
	m_clock.restart();

	return 0;
}