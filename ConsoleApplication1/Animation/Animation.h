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
*  The class is an animation to display.
*
*/

#pragma once

#include <SFML\Graphics.hpp>
#include "../Map/ManageSurfaces.h"


class Animation
{
public:
	Animation(int refreshTime, const std::vector<sf::Rect<short>>& rects, std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator surf);
	Animation(int refreshTime, const std::vector<sf::Rect<short>>& rects, std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator surf, int loop, bool killWhenDone = false);
	Animation(int refreshTime, const std::vector<sf::Rect<short>>& rects, std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator surf, int endX, int endY, int manDist, int loop = -1, bool killWhenDone = false);
	~Animation();

public:
	/**
	* \brief Return if the animation moves	.
	*
	* \return bool object.
	*/
	bool getMoving() const;
	/**
	* \brief Return if the animation is finished	.
	*
	* \return bool object.
	*/
	bool getFinished() const;
	/**
	* \brief Return if the animation is supposed to be killed when its done	.
	*
	* \return bool object.
	*/
	bool getKillWhenDone() const;
	/**
	* \brief Return the remaining number of loop	.
	*
	* \return int object.
	*/
	int getNbLoop() const;
	/**
	* \brief Return the animation refresh time	.
	*
	* \return int object.
	*/
	int getRefreshTime() const;
	/**
	* \brief Return the distance walked by the animation at each call	.
	*
	* \return int object.
	*/
	int getManathanDistance() const;
	/**
	* \brief Return the destination position X	.
	*
	* \return int object.
	*/
	int getEndX() const;
	/**
	* \brief Return the destination position Y	.
	*
	* \return int object.
	*/
	int getEndY() const;
	/**
	* \brief Return the location of the sprites rect	.
	*
	* \return std::vector<sf::Rect<short>> object.
	*/
	std::vector<sf::Rect<short>> getRectSprites() const;

	/**
	* \brief Modify the animation refresh time	.
	*
	* \param t The new value.
	* \return int object.
	*/
	int setRefreshTime(const int &t);

	/**
	* \brief Return the surface used	.
	*
	* \return std::list<std::pair<ManageSurfaces::e_thing, object.
	*/
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getRealSurface();

	/**
	* \brief Stop instantly the animation	.
	*
	* \return int object.
	*/
	int stop();
	/**
	* \brief Stop after the end of the animation	.
	*
	* \return int object.
	*/
	int stopAfter();
	/**
	* \brief Kill instantly the animation	.
	*
	* \return int object.
	*/
	int kill();
	/**
	* \brief Update the animation	.
	*
	* \return int object.
	*/
	int update();
	/**
	* \brief Start the animation	.
	*
	* \return int object.
	*/
	int start(int endX, int endY, int manDist, int loop = -1, bool killWhenDone = false);
	int start(int loop = -1, bool killWhenDone = false);

private:
	bool m_moving;
	bool m_finished;
	bool m_killWhenDone;
	int m_nbLoop;
	int m_refreshTime;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_surface;
	int m_manathanDistance;
	int m_endX;
	int m_endY;
	sf::Clock m_clock;
	std::vector<sf::Rect<short>> m_rectSprites;
	int m_rectAct;
};
