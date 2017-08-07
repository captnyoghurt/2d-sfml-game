#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
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

/// Ressources number texture
extern int RESSOURCE_TEXTURE_NUMBER_MENU;
extern int RESSOURCE_TEXTURE_NUMBER_LIFEBAR;

/// Ressources number font
extern int RESSOURCE_FONT_NUMBER_MONO;

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
extern int TEAM_WALK_HITBOX_X;
extern int TEAM_WALK_HITBOX_Y;
extern int TEAM_WALK_HITBOX_WIDTH;
extern int TEAM_WALK_HITBOX_HEIGHT;

/// Combat
extern int TEAM_BATTLE_MAX_NUMBER;

// Menu constants

/// Font
extern std::string MENU_FONT_NAME;
extern sf::Color MENU_FONT_COLOR;
extern sf::Color MENU_FONT_COLOR_DISABLED_CHOICE;

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
//// Right
extern int MENU_SURFACE_CURSOR_RIGHT_BEGIN_X;
extern int MENU_SURFACE_CURSOR_RIGHT_BEGIN_Y;
extern int MENU_SURFACE_CURSOR_RIGHT_WIDTH;
extern int MENU_SURFACE_CURSOR_RIGHT_HEIGHT;
//// Left
extern int MENU_SURFACE_CURSOR_LEFT_BEGIN_X;
extern int MENU_SURFACE_CURSOR_LEFT_BEGIN_Y;
extern int MENU_SURFACE_CURSOR_LEFT_WIDTH;
extern int MENU_SURFACE_CURSOR_LEFT_HEIGHT;

/// Selected
extern int MENU_SURFACE_SELECTED_BEGIN_X;
extern int MENU_SURFACE_SELECTED_BEGIN_Y;
extern int MENU_SURFACE_SELECTED_WIDTH;
extern int MENU_SURFACE_SELECTED_HEIGHT;


// Battle constants

/// General
extern std::string MENU_BATTLE_SURFACE_BAR;
extern std::string MENU_BATTLE_CHOICE_TEXT;
extern int BATTLE_MIN_LAYER;
extern int BATTLE_NUMBER_OF_LAYER;
extern int BATTLE_MAX_LAYER;
extern int BATTLE_KEY_EVENT_LAYER;

/// Health
extern std::string HEALTH_NAME;
extern int HEALTH_MAX_POINTS;
extern int HEALTH_SURFACE_BEGIN_X;
extern int HEALTH_SURFACE_BEGIN_Y;
extern int HEALTH_SURFACE_WIDTH;
extern int HEALTH_SURFACE_HEIGHT;
extern int HEALTH_TEXT_POSITION_X;
extern int HEALTH_TEXT_POSITION_Y;
extern int HEALTH_TEXT_WIDTH;
extern int HEALTH_TEXT_HEIGHT;
extern int HEALTH_IMAGE_POSITION_X;
extern int HEALTH_IMAGE_POSITION_Y;
extern int HEALTH_IMAGE_WIDTH;
extern int HEALTH_IMAGE_HEIGHT;

/// Skill Points
extern std::string SKILLPOINTS_NAME;
extern int SKILLPOINTS_MAX_POINTS;
extern int SKILLPOINTS_SURFACE_BEGIN_X;
extern int SKILLPOINTS_SURFACE_BEGIN_Y;
extern int SKILLPOINTS_SURFACE_WIDTH;
extern int SKILLPOINTS_SURFACE_HEIGHT;
extern int SKILLPOINTS_TEXT_POSITION_X;
extern int SKILLPOINTS_TEXT_POSITION_Y;
extern int SKILLPOINTS_TEXT_WIDTH;
extern int SKILLPOINTS_TEXT_HEIGHT;
extern int SKILLPOINTS_IMAGE_POSITION_X;
extern int SKILLPOINTS_IMAGE_POSITION_Y;
extern int SKILLPOINTS_IMAGE_WIDTH;
extern int SKILLPOINTS_IMAGE_HEIGHT;

/// Mana
extern std::string MANA_NAME;
extern int MANA_MAX_POINTS;
extern int MANA_SURFACE_BEGIN_X;
extern int MANA_SURFACE_BEGIN_Y;
extern int MANA_SURFACE_WIDTH;
extern int MANA_SURFACE_HEIGHT;
extern int MANA_TEXT_POSITION_X;
extern int MANA_TEXT_POSITION_Y;
extern int MANA_TEXT_WIDTH;
extern int MANA_TEXT_HEIGHT;
extern int MANA_IMAGE_POSITION_X;
extern int MANA_IMAGE_POSITION_Y;
extern int MANA_IMAGE_WIDTH;
extern int MANA_IMAGE_HEIGHT;

/// Team
extern std::string TEAM_BATTLE_CHAR1_NAME;
extern int TEAM_BATTLE_CHAR1_X;
extern int TEAM_BATTLE_CHAR1_Y;

extern std::string TEAM_BATTLE_CHAR2_NAME;
extern int TEAM_BATTLE_CHAR2_X;
extern int TEAM_BATTLE_CHAR2_Y;