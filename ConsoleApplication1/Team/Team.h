#pragma once

#include <vector>
#include "../Animation/Animation.h"
#include "Character.h"
#include "../Battle/TeamBattle.h"
#include "../Map/Physic/Hitbox.h"
#include "../Items/Inventory.h"

class Team
{
public:
	enum e_teamMode {NONE, WALK, COMBAT};
	enum e_teamDirection{UP, DOWN, RIGHT, LEFT, UNKNOWN};

public:
	explicit Team(Game &g);
	~Team();

public:
	// Return if it is moving
	bool getMoving() const;
	// Return if the camera should follow
	bool getCameraFollowing() const;
	// Return the abciss of the team
	unsigned short getX() const;
	// Return the y position of the team
	unsigned short getY() const;
	// Return the width of the team
	short getWidth() const;
	// Return the height of the team
	short getHeight() const;
	// Return the mode
	e_teamMode getMode() const;
	// Return the current direction
	e_teamDirection getDirection() const;
	// Return the team
	std::vector<Character> getTeam() const;
	// Return animations
	std::vector<std::list<Animation>::iterator> getAnimations() const;
	// Return the walk stand surface
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getWalkStand() const;
	// Return the hitbox
	Hitbox getHitbox() const;
	// Return the inventory
	Inventory getInventory() const;
	// Return the maxX of the team
	short getMaxX() const;
	// Return the maxY of the team
	short getMaxY() const;
	// Return the team battle
	TeamBattle getTeamBattle() const;

	// Return the team with modifying possibilities
	std::vector<Character>& getRealTeam();
	// Return animations with modifying possibilities
	std::vector<std::list<Animation>::iterator>& getRealAnimations();
	// Return the walk stand surface with modifying possibilities
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealWalkStand();
	// Return the hitbox with modifying possibilities
	Hitbox& getRealHitbox();
	// Return the inventory with modifying possibilities
	Inventory& getRealInventory();
	// Return the team battle with modifying possibilities
	TeamBattle& getRealTeamBattle();

	// Modify if it is moving
	int setMoving(const bool &b);
	// Modify if the camera should follow
	int setCameraFollowing(const bool &b);
	// Modify the abciss of the team
	int setX(const unsigned short &x);
	// Modify the y position of the team
	int setY(const unsigned short &y);
	// Modify the width of the team
	int setWidth(const short &w);
	// Modify the height of the team
	int setHeight(const short &h);
	// Modifying mode
	int setMode(e_teamMode m);
	// Modify the current direction
	int setDirection(e_teamDirection dir);
	// Modify all the dimensions
	int setDimension(const unsigned short &x, const unsigned short &y, const short &w, const short &h);
	// Modify the maxX of the team
	int setMaxX(short mapWidth);
	// Modify the maxY of the team
	int setMaxY(short mapHeight);
	// Modify the walk stand surface
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator setWalkStand(std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator l);

	// Move the team
	int move(const short &dx, const short &dy, e_teamDirection direction = UNKNOWN);
	int stopMoving(Team::e_teamDirection dir = UNKNOWN);
	//int moveWithCamera(const short &dx, const short &dy, Camera &c, e_teamDirection direction = UNKNOWN);
	// Update the movement
	int update(Camera &c, ManageHitbox &hm);
	// Load the TeamBattle
	int loadTeamBattle(Game &g);

private:
	std::vector<Character> m_team;
	TeamBattle m_teamBattle;
	e_teamMode m_mode;
	e_teamDirection m_direction;
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator m_walkStand;
	std::vector<std::list<Animation>::iterator> m_movementAnimation;
	sf::Clock m_clock;
	std::shared_ptr<Hitbox> m_hitbox;
	Inventory m_inventory;
	bool m_defined;
	bool m_moving;
	bool m_cameraFollowing;
	unsigned short m_x;
	unsigned short m_y;
	short m_speedX;
	short m_speedY;
	short m_width;
	short m_height;
	short m_maxX;
	short m_maxY;
};

