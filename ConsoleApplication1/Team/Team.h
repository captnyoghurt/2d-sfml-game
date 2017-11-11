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
*  The team on the map.
*
*/

#pragma once

#include <vector>
#include "../Animation/Animation.h"
#include "Character.h"
#include "../Battle/Fighters/TeamBattle.h"
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
	/**
	* \brief Return if it is moving	.
	*
	* \return bool object.
	*/
	bool getMoving() const;
	/**
	* \brief Return if the camera should follow	.
	*
	* \return bool object.
	*/
	bool getCameraFollowing() const;
	/**
	* \brief Return the abciss of the team	.
	*
	* \return unsigned object.
	*/
	unsigned short getX() const;
	/**
	* \brief Return the y position of the team	.
	*
	* \return unsigned object.
	*/
	unsigned short getY() const;
	/**
	* \brief Return the width of the team	.
	*
	* \return short object.
	*/
	short getWidth() const;
	/**
	* \brief Return the height of the team	.
	*
	* \return short object.
	*/
	short getHeight() const;
	/**
	* \brief Return the mode	.
	*
	* \return e_teamMode object.
	*/
	e_teamMode getMode() const;
	/**
	* \brief Return the current direction	.
	*
	* \return e_teamDirection object.
	*/
	e_teamDirection getDirection() const;
	/**
	* \brief Return the team	.
	*
	* \return std::vector<Character> object.
	*/
	std::vector<Character> getTeam() const;
	/**
	* \brief Return animations	.
	*
	* \return std::vector<std::list<Animation>::iterator> object.
	*/
	std::vector<std::list<Animation>::iterator> getAnimations() const;
	/**
	* \brief Return the walk stand surface	.
	*
	* \return std::list<std::pair<ManageSurfaces::e_thing, object.
	*/
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator getWalkStand() const;
	/**
	* \brief Return the hitbox	.
	*
	* \return Hitbox object.
	*/
	Hitbox getHitbox() const;
	/**
	* \brief Return the inventory	.
	*
	* \return Inventory object.
	*/
	Inventory getInventory() const;
	/**
	* \brief Return the maxX of the team	.
	*
	* \return short object.
	*/
	short getMaxX() const;
	/**
	* \brief Return the maxY of the team	.
	*
	* \return short object.
	*/
	short getMaxY() const;
	/**
	* \brief Return the team battle	.
	*
	* \return TeamBattle object.
	*/
	TeamBattle getTeamBattle() const;

	/**
	* \brief Return the team with modifying possibilities	.
	*
	* \return std::vector<Character>& object.
	*/
	std::vector<Character>& getRealTeam();
	/**
	* \brief Return animations with modifying possibilities	.
	*
	* \return std::vector<std::list<Animation>::iterator>& object.
	*/
	std::vector<std::list<Animation>::iterator>& getRealAnimations();
	/**
	* \brief Return the walk stand surface with modifying possibilities	.
	*
	* \return std::list<std::pair<ManageSurfaces::e_thing, object.
	*/
	std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator& getRealWalkStand();
	/**
	* \brief Return the hitbox with modifying possibilities	.
	*
	* \return Hitbox& object.
	*/
	Hitbox& getRealHitbox();
	/**
	* \brief Return the inventory with modifying possibilities	.
	*
	* \return Inventory& object.
	*/
	Inventory& getRealInventory();
	/**
	* \brief Return the team battle with modifying possibilities	.
	*
	* \return TeamBattle& object.
	*/
	TeamBattle& getRealTeamBattle();

	/**
	* \brief Modify if it is moving	.
	*
	* \param b The new value.
	* \return int object.
	*/
	int setMoving(const bool &b);
	/**
	* \brief Modify if the camera should follow	.
	*
	* \param b The new value.
	* \return int object.
	*/
	int setCameraFollowing(const bool &b);
	/**
	* \brief Modify the abciss of the team	.
	*
	* \param x The new value.
	* \return int object.
	*/
	int setX(const unsigned short &x);
	/**
	* \brief Modify the y position of the team	.
	*
	* \param y The new value.
	* \return int object.
	*/
	int setY(const unsigned short &y);
	/**
	* \brief Modify the width of the team	.
	*
	* \param w The new value.
	* \return int object.
	*/
	int setWidth(const short &w);
	/**
	* \brief Modify the height of the team.
	*
	* \param h The new value.
	* \return int object.
	*/
	int setHeight(const short &h);
	/**
	* \brief Modifying mode.
	*
	* \param m The new value.
	* \return int object.
	*/
	int setMode(e_teamMode m);
	/**
	* \brief Modify the current direction.
	*
	* \param dir The new value.
	* \return int object.
	*/
	int setDirection(e_teamDirection dir);
	/**
	* \brief Modify all the dimensions.
	*
	* \return int object.
	*/
	int setDimension(const unsigned short &x, const unsigned short &y, const short &w, const short &h);
	/**
	* \brief Modify the maxX of the team.
	*
	* \param mapWidth The new value.
	* \return int object.
	*/
	int setMaxX(short mapWidth);
	// 
	/**
	* \brief Modify the maxY of the team.
	*
	* \param mapHeight The new value.
	* \return int object.
	*/
	int setMaxY(short mapHeight);
	/**
	* \brief  Modify the walk stand surface.
	*
	* \param l The new value.
	* \return std::list<std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator object.
	*/
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