#pragma once

#include <SFML\Graphics.hpp>
#include "../Map/ManageSurfaces.h"


class Animation
{
public:
	Animation(int refreshTime, const std::vector<sf::Rect<short>> rects, std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator surf);
	Animation(int refreshTime, const std::vector<sf::Rect<short>> rects, std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator surf, int loop, bool killWhenDone = false);
	Animation(int refreshTime, const std::vector<sf::Rect<short>> rects, std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator surf, int endX, int endY, int manDist, int loop = -1, bool killWhenDone = false);
	~Animation();

public:
	// Return if the animation moves
	bool getMoving() const;
	// Return if the animation is finished
	bool getFinished() const;
	// Return if the animation is supposed to be killed when its done
	bool getKillWhenDone() const;
	// Return the remaining number of loop
	int getNbLoop() const;
	// Return the animation refresh time
	int getRefreshTime() const;
	// Return the distance walked by the animation at each call
	int getManathanDistance() const;
	// Return the destination position X
	int getEndX() const;
	// Return the destination position Y
	int getEndY() const;
	// Return the location of the sprites rect
	std::vector<sf::Rect<short>> getRectSprites() const;

	// Modify the animation refresh time
	int setRefreshTime(const int &t);

	// Return the surface used
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getRealSurface();

	// Stop instantly the animation
	int stop();
	// Stop after the end of the animation
	int stopAfter();
	// Kill instantly the animation
	int kill();
	// Update the animation
	int update();
	// Start the animation
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

