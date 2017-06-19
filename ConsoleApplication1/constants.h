#pragma once

#include <SFML/System.hpp>
#include <string>

#define ABSOLUTE(x)	(((x) > 0) ? (x) : (-x))
#define SIGNE(x)	(((x) > 0) ? 1 : -1)
#define MIN(x, y)	(((x) > (y)) ? (y) : (x))
#define MAX(x, y)	(((x) > (y)) ? (x) : (y))

// Window constants
extern std::string WINDOW_NAME;
extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern int WINDOW_X;
extern int WINDOW_Y;
extern int WINDOW_SLEEPTIME;
extern int WINDOW_FRAMERATES;

// Graphic constants

/// Map
extern std::string MAP_FONT_TEXT;
extern int MAP_MAX_LAYER;

/// TILE
extern int TILE_WIDTH;
extern int TILE_HEIGHT;

/// Camera
extern int CAMERA_WIDTH;
extern int CAMERA_HEIGHT;
extern int CAMERA_MOVING_X;
extern int CAMERA_MOVING_Y;

/// Team moving
extern int TEAM_MOVING_X;
extern int TEAM_MOVING_Y;
extern int TEAM_MOVING_NORMAL_SPEED_X;
extern int TEAM_MOVING_NORMAL_SPEED_Y;

/// Animation
extern int ANIMATION_REFRESHING;
extern int ANIMATION_NB_LAYER;

/// Menus
extern int MENUS_BORDER_X;
extern int MENUS_BORDER_Y;
extern int MENUS_GAP_BETWEEN_LINES; // px

// Team constants

/// Walk Stand
extern std::string TEAM_BASIC_WALKSTAND;
extern int TEAM_WALK_ANIMATION_REFRESH;
extern int TEAM_WALK_WIDTH;
extern int TEAM_WALK_HEIGHT;
extern int TEAM_WALK_FRAME_NUMBER;
extern int TEAM_WALK_UP_POSITION_Y;
extern int TEAM_WALK_DOWN_POSITION_Y;
extern int TEAM_WALK_RIGHT_POSITION_Y;
extern int TEAM_WALK_LEFT_POSITION_Y;
extern int TEAM_WALK_LAYER;

// Menu constants

/// Font
extern std::string MENU_FONT_NAME;

/// Surface
extern std::string MENU_SURFACE_NAME;
extern int MENU_SURFACE_BEGIN_X;
extern int MENU_SURFACE_BEGIN_Y;
extern int MENU_SURFACE_WIDTH;
extern int MENU_SURFACE_HEIGHT;

/// Simple menu
extern std::string MENU_SIMPLE_TEXT;
extern int MENU_SIMPLE_FONTSIZE;
extern int MENU_SIMPLE_HEIGHT;
extern int MENU_SIMPLE_WIDTH;
extern int MENU_SIMPLE_LAYER;

/// Dialog box
extern int MENU_DIALOG_BOX_FONTSIZE;
extern int MENU_DIALOG_BOX_GAP_BETWEEN_LINES;
extern int MENU_DIALOG_BOX_X;
extern int MENU_DIALOG_BOX_Y;
extern int MENU_DIALOG_BOX_WIDTH;
extern int MENU_DIALOG_BOX_HEIGHT;
extern int MENU_DIALOG_BOX_CHARACTER_BY_LINE;
extern int MENU_DIALOG_BOX_LAYER;

/// Bag
extern std::string MENU_BAG_TEXT;
extern int MENU_BAG_FONTSIZE;
extern int MENU_BAG_LAYER;

/// Cursor
//// Up
extern int MENU_SURFACE_CURSOR_UP_BEGIN_X;
extern int MENU_SURFACE_CURSOR_UP_BEGIN_Y;
extern int MENU_SURFACE_CURSOR_UP_WIDTH;
extern int MENU_SURFACE_CURSOR_UP_HEIGHT;
//// Down
extern int MENU_SURFACE_CURSOR_DOWN_BEGIN_X;
extern int MENU_SURFACE_CURSOR_DOWN_BEGIN_Y;
extern int MENU_SURFACE_CURSOR_DOWN_WIDTH;
extern int MENU_SURFACE_CURSOR_DOWN_HEIGHT;

/// Selected
extern int MENU_SURFACE_SELECTED_BEGIN_X;
extern int MENU_SURFACE_SELECTED_BEGIN_Y;
extern int MENU_SURFACE_SELECTED_WIDTH;
extern int MENU_SURFACE_SELECTED_HEIGHT;



// Battle constants

/// Health
extern int HEALTH_MAX_POINTS;

/// Skill Points
extern int SKILLPOINTS_MAX_POINTS;

/// Mana
extern int MANA_MAX_POINTS;