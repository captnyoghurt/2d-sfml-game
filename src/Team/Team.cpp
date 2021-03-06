#include "Team.h"
#include <memory>
#include "../Error/RessourceException.h"
#include "../Error/ValueException.h"
#include "../Game.h"
#include "../constants.h"

Team::Team(Game &g) {
  m_cameraFollowing = true;
  m_moving = true;
  m_defined = false;
  m_x = 0;
  m_y = 0;
  m_width = TEAM_WALK_WIDTH;
  m_height = TEAM_WALK_HEIGHT;
  m_maxX = 0;
  m_maxY = 0;
  m_movementAnimation.resize(Team::UNKNOWN);
  m_speedX = 0;
  m_speedY = 0;
  m_mode = Team::e_teamMode::WALK;
  m_direction = Team::e_teamDirection::DOWN;

  // Load the hitbox
  m_hitbox =
      std::make_shared<Hitbox>(g.getRealMap().getRealHitboxManager().addHitbox(
          Hitbox(-1, TEAM_WALK_HITBOX_X, TEAM_WALK_HITBOX_Y,
                 TEAM_WALK_HITBOX_WIDTH, TEAM_WALK_HITBOX_HEIGHT)));

  ///// Load inventory
  m_inventory.getRealItems().push_back(
      std::make_pair(g.getRealDatabaseJson().getFullItem(1), 2));
  m_inventory.getRealItems().push_back(
      std::make_pair(g.getRealDatabaseJson().getFullItem(2), 5));
  m_inventory.getRealItems().push_back(
      std::make_pair(g.getRealDatabaseJson().getFullItem(1), 8));

  // Load the textures
  auto texture = g.getRealRessourceManager()
                     .at(Game::e_ressourcesLayer::RESSOURCES_MAP)
                     .addTexture();
  if (!texture->loadFromFile(TEAM_BASIC_WALKSTAND))
    THROW_RESSOURCE("Walkstand of the team", TEAM_BASIC_WALKSTAND);

  setWalkStand(g.getRealSurfaceManager()
                   .at(LAYER_MAP_EVENEMENT)
                   .addSurface(ManageSurfaces::SPRITE,
                               std::make_shared<SurfaceSprite>()));
  std::dynamic_pointer_cast<SurfaceSprite>(m_walkStand->second)
      ->setTexture(*texture);
  std::dynamic_pointer_cast<SurfaceSprite>(m_walkStand->second)
      ->setTextureRect(sf::IntRect(0, 0, TEAM_WALK_WIDTH, TEAM_WALK_HEIGHT));
  std::dynamic_pointer_cast<SurfaceSprite>(m_walkStand->second)
      ->setDimensions(0, 0, TEAM_WALK_WIDTH, TEAM_WALK_HEIGHT);

  std::vector<sf::Rect<short>> animSprites(TEAM_WALK_FRAME_NUMBER);

  /// UP
  for (int i(0); i < TEAM_WALK_FRAME_NUMBER; ++i)
    animSprites.at(i) =
        sf::Rect<short>(i * TEAM_WALK_WIDTH, TEAM_WALK_UP_POSITION_Y,
                        TEAM_WALK_WIDTH, TEAM_WALK_HEIGHT);
  m_movementAnimation.at(Team::e_teamDirection::UP) =
      g.getRealAnimationManager().addAnimation(
          Animation(TEAM_WALK_ANIMATION_REFRESH, animSprites, m_walkStand));
  /// DOWN
  for (int i(0); i < TEAM_WALK_FRAME_NUMBER; ++i)
    animSprites.at(i) =
        sf::Rect<short>(i * TEAM_WALK_WIDTH, TEAM_WALK_DOWN_POSITION_Y,
                        TEAM_WALK_WIDTH, TEAM_WALK_HEIGHT);
  m_movementAnimation.at(Team::e_teamDirection::DOWN) =
      g.getRealAnimationManager().addAnimation(
          Animation(TEAM_WALK_ANIMATION_REFRESH, animSprites, m_walkStand));
  /// RIGHT
  for (int i(0); i < TEAM_WALK_FRAME_NUMBER; ++i)
    animSprites.at(i) =
        sf::Rect<short>(i * TEAM_WALK_WIDTH, TEAM_WALK_RIGHT_POSITION_Y,
                        TEAM_WALK_WIDTH, TEAM_WALK_HEIGHT);
  m_movementAnimation.at(Team::e_teamDirection::RIGHT) =
      g.getRealAnimationManager().addAnimation(
          Animation(TEAM_WALK_ANIMATION_REFRESH, animSprites, m_walkStand));
  /// LEFT
  for (int i(0); i < TEAM_WALK_FRAME_NUMBER; ++i)
    animSprites.at(i) =
        sf::Rect<short>(i * TEAM_WALK_WIDTH, TEAM_WALK_LEFT_POSITION_Y,
                        TEAM_WALK_WIDTH, TEAM_WALK_HEIGHT);
  m_movementAnimation.at(Team::e_teamDirection::LEFT) =
      g.getRealAnimationManager().addAnimation(
          Animation(TEAM_WALK_ANIMATION_REFRESH, animSprites, m_walkStand));
}

Team::~Team() {}

// Return if it is moving
bool Team::getMoving() const { return m_moving; }

// Return if the camera should follow
bool Team::getCameraFollowing() const { return m_cameraFollowing; }

unsigned short Team::getX() const { return m_x; }

// Return the y position of the Tile
unsigned short Team::getY() const { return m_y; }

// Return the width of the Tile
short Team::getWidth() const { return m_width; }

// Return the height of the Tile
short Team::getHeight() const { return m_height; }

// Return the mode
Team::e_teamMode Team::getMode() const { return m_mode; }

// Return the current direction
Team::e_teamDirection Team::getDirection() const { return m_direction; }

// Return the team
std::vector<Character> Team::getTeam() const { return m_team; }

// Return the team battle
TeamBattle Team::getTeamBattle() const { return m_teamBattle; }

// Return the team with modifying possibilities
std::vector<Character> &Team::getRealTeam() { return m_team; }

// Return animations with modifying possibilities
std::vector<std::list<Animation>::iterator> &Team::getRealAnimations() {
  return m_movementAnimation;
}

// Return animations
std::vector<std::list<Animation>::iterator> Team::getAnimations() const {
  return m_movementAnimation;
}

// Return the walk stand surface
std::list<
    std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
Team::getWalkStand() const {
  return m_walkStand;
}

// Return the hitbox
Hitbox Team::getHitbox() const { return *m_hitbox; }

// Return the inventory
Inventory Team::getInventory() const { return m_inventory; }

// Return the walk stand surface with modifying possibilities
std::list<
    std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator &
Team::getRealWalkStand() {
  return m_walkStand;
}

// Return the hitbox with modifying possibilities
Hitbox &Team::getRealHitbox() { return *m_hitbox; }

// Return the inventory with modifying possibilities
Inventory &Team::getRealInventory() { return m_inventory; }

// Return the team battle with modifying possibilities
TeamBattle &Team::getRealTeamBattle() { return m_teamBattle; }

// Return the maxX of the team
short Team::getMaxX() const { return m_maxX; }

// Return the maxY of the team
short Team::getMaxY() const { return m_maxY; }

// Modify if it is moving
int Team::setMoving(const bool &b) {
  m_moving = b;
  return 0;
}

// Modify if the camera should follow
int Team::setCameraFollowing(const bool &b) {
  m_cameraFollowing = b;
  return 0;
}

// Modify the abciss of the Team
int Team::setX(const unsigned short &x) {
  m_x = x;
  return 0;
}

// Modify the y position of the Team
int Team::setY(const unsigned short &y) {
  m_y = y;
  return 0;
}

// Modify the width of the Team
int Team::setWidth(const short &w) {
  if (w < 0) THROW_VALUE(std::to_string(w));

  m_width = w;
  return 0;
}

// Modify the height of the Team
int Team::setHeight(const short &h) {
  if (h < 0) THROW_VALUE(std::to_string(h));

  m_height = h;
  return 0;
}

// Modifying mode
int Team::setMode(Team::e_teamMode m) {
  m_mode = m;
  switch (m) {
    case NONE:
      m_walkStand->second->setEnable(false);
      for (unsigned int i(0); i < m_team.size(); i++)
        m_team.at(i).getRealCombatStand()->second->setEnable(false);
      break;
    case WALK:
      m_walkStand->second->setEnable(true);
      for (unsigned int i(0); i < m_team.size(); i++)
        m_team.at(i).getRealCombatStand()->second->setEnable(false);
      break;
    case COMBAT:
      m_walkStand->second->setEnable(false);
      for (unsigned int i(0); i < m_team.size(); i++)
        m_team.at(i).getRealCombatStand()->second->setEnable(true);
      break;
    default:
      THROW_VALUE("Unknown TeamMode " + std::to_string(m));
      break;
  }

  return 0;
}

// Modify the current direction
int Team::setDirection(Team::e_teamDirection dir) {
  if (m_direction != dir || !m_moving) {
    m_direction = dir;

    switch (dir) {
      case Team::UP:
        (m_movementAnimation.at(Team::UP))->start(-1);
        std::dynamic_pointer_cast<SurfaceSprite>(m_walkStand->second)
            ->setTextureRect(sf::IntRect(
                m_movementAnimation.at(Team::UP)->getRectSprites().at(0).left,
                m_movementAnimation.at(Team::UP)->getRectSprites().at(0).top,
                m_movementAnimation.at(Team::UP)->getRectSprites().at(0).width,
                m_movementAnimation.at(Team::UP)
                    ->getRectSprites()
                    .at(0)
                    .height));
        (m_movementAnimation.at(Team::DOWN))->stop();
        (m_movementAnimation.at(Team::LEFT))->stop();
        (m_movementAnimation.at(Team::RIGHT))->stop();
        break;
      case Team::DOWN:
        (m_movementAnimation.at(Team::UP))->stop();
        (m_movementAnimation.at(Team::DOWN))->start(-1);
        std::dynamic_pointer_cast<SurfaceSprite>(m_walkStand->second)
            ->setTextureRect(sf::IntRect(
                m_movementAnimation.at(Team::DOWN)->getRectSprites().at(0).left,
                m_movementAnimation.at(Team::DOWN)->getRectSprites().at(0).top,
                m_movementAnimation.at(Team::DOWN)
                    ->getRectSprites()
                    .at(0)
                    .width,
                m_movementAnimation.at(Team::DOWN)
                    ->getRectSprites()
                    .at(0)
                    .height));
        (m_movementAnimation.at(Team::LEFT))->stop();
        (m_movementAnimation.at(Team::RIGHT))->stop();
        break;
      case Team::LEFT:
        (m_movementAnimation.at(Team::UP))->stop();
        (m_movementAnimation.at(Team::DOWN))->stop();
        (m_movementAnimation.at(Team::LEFT))->start(-1);
        std::dynamic_pointer_cast<SurfaceSprite>(m_walkStand->second)
            ->setTextureRect(sf::IntRect(
                m_movementAnimation.at(Team::LEFT)->getRectSprites().at(0).left,
                m_movementAnimation.at(Team::LEFT)->getRectSprites().at(0).top,
                m_movementAnimation.at(Team::LEFT)
                    ->getRectSprites()
                    .at(0)
                    .width,
                m_movementAnimation.at(Team::LEFT)
                    ->getRectSprites()
                    .at(0)
                    .height));
        (m_movementAnimation.at(Team::RIGHT))->stop();
        break;
      case Team::RIGHT:
        (m_movementAnimation.at(Team::UP))->stop();
        (m_movementAnimation.at(Team::DOWN))->stop();
        (m_movementAnimation.at(Team::LEFT))->stop();
        (m_movementAnimation.at(Team::RIGHT))->start(-1);
        std::dynamic_pointer_cast<SurfaceSprite>(m_walkStand->second)
            ->setTextureRect(sf::IntRect(
                m_movementAnimation.at(Team::RIGHT)
                    ->getRectSprites()
                    .at(0)
                    .left,
                m_movementAnimation.at(Team::RIGHT)->getRectSprites().at(0).top,
                m_movementAnimation.at(Team::RIGHT)
                    ->getRectSprites()
                    .at(0)
                    .width,
                m_movementAnimation.at(Team::RIGHT)
                    ->getRectSprites()
                    .at(0)
                    .height));
        break;
      default:
        THROW_VALUE("Unknown team orientation " + std::to_string(dir));
        break;
    }
  }

  return 0;
}

// Modify all the dimensions
int Team::setDimension(const unsigned short &x, const unsigned short &y,
                       const short &w, const short &h) {
  int ret = setX(x) + setY(y) + setWidth(w) + setHeight(h);

  return ret;
}

// Modify the maxX of the team
int Team::setMaxX(short mapWidth) {
  m_maxX = ((mapWidth - m_width) < 0) ? 0 : mapWidth - m_width;

  return 0;
}

// Modify the maxY of the team
int Team::setMaxY(short mapHeight) {
  m_maxY = ((mapHeight - m_height) < 0) ? 0 : mapHeight - m_height;

  return 0;
}

// Modify the walk stand surface
std::list<
    std::pair<ManageSurfaces::e_thing, std::shared_ptr<Surface>>>::iterator
Team::setWalkStand(std::list<std::pair<ManageSurfaces::e_thing,
                                       std::shared_ptr<Surface>>>::iterator l) {
  if (m_defined) {
    setDimension(l->second->getX(), l->second->getY(), l->second->getWidth(),
                 l->second->getHeight());
    setMaxX(m_maxX + m_width);
    setMaxY(m_maxY + m_height);
  }
  m_defined = true;
  m_walkStand = l;

  return l;
}

// Move the team
int Team::move(const short &dx, const short &dy, e_teamDirection direction) {
  // [TODO]
  m_speedX = dx;  // Pixel per second
  m_speedY = dy;

  // Set direction
  if (direction != Team::e_teamDirection::UNKNOWN) {
    setDirection(direction);
  } else {
    if (dx > 0)
      setDirection(Team::e_teamDirection::RIGHT);
    else if (dx < 0)
      setDirection(Team::e_teamDirection::LEFT);
    else if (dy < 0)
      setDirection(Team::e_teamDirection::DOWN);
    else if (dy > 0)
      setDirection(Team::e_teamDirection::UP);
  }
  m_moving = true;

  return 0;
}

int Team::stopMoving(Team::e_teamDirection dir) {
  m_moving = false;
  if (dir == Team::UNKNOWN) {
    (m_movementAnimation.at(Team::UP))->stopAfter();
    (m_movementAnimation.at(Team::DOWN))->stopAfter();
    (m_movementAnimation.at(Team::LEFT))->stopAfter();
    (m_movementAnimation.at(Team::RIGHT))->stopAfter();
  } else
    (m_movementAnimation.at(dir))->stopAfter();

  if (dir != Team::UNKNOWN && m_direction != Team::UNKNOWN &&
      m_direction != dir)
    m_moving = true;
  else
    m_direction = Team::UNKNOWN;

  return 0;
}

// Update the movement
int Team::update(Camera &c, ManageHitbox &hm) {
  if (!m_moving ||
      (m_speedY != 0 && m_clock.getElapsedTime().asMicroseconds() <
                            1000000 * TEAM_MOVING_Y / ABSOLUTE(m_speedY)) ||
      (m_speedX != 0 && m_clock.getElapsedTime().asMicroseconds() <
                            1000000 * TEAM_MOVING_X / ABSOLUTE(m_speedX)))
    return 0;
  // std::cout << "** moving clock " <<
  // m_clock.getElapsedTime().asMicroseconds() << std::endl;
  ///
  m_clock.restart();
  ///

  if (hm.willCollide(*m_hitbox,
                     (m_speedX != 0) ? TEAM_MOVING_X * SIGNE(m_speedX) : 0,
                     (m_speedY != 0) ? TEAM_MOVING_Y * SIGNE(m_speedY) : 0) >
      ManageHitbox::e_CollisionType::COLLISION_NONE)
    return 0;

  if (m_speedX != 0) {
    if (m_x + TEAM_MOVING_X * SIGNE(m_speedX) <= 0)
      m_x = 0;
    else if (m_x + TEAM_MOVING_X * SIGNE(m_speedX) >= m_maxX)
      m_x = m_maxX;
    else
      m_x += (TEAM_MOVING_X * SIGNE(m_speedX));
  }
  if (m_speedY != 0) {
    if (m_y + TEAM_MOVING_Y * SIGNE(m_speedY) <= 0)
      m_y = 0;
    else if (m_y + TEAM_MOVING_Y * SIGNE(m_speedY) >= m_maxY)
      m_y = m_maxY;
    else
      m_y += (TEAM_MOVING_Y * SIGNE(m_speedY));
  }

  m_hitbox->setX(m_x + TEAM_WALK_HITBOX_X);
  m_hitbox->setY(m_y + TEAM_WALK_HITBOX_Y);

  m_walkStand->second->setX(m_x);
  m_walkStand->second->setY(m_y);

  if (m_x + m_width / 2 < CAMERA_WIDTH / 2)
    c.setX(0);
  else if (m_x + m_width / 2 > c.getMaxX() + (CAMERA_WIDTH / 2))
    c.setX(c.getMaxX());
  else
    c.setX(m_x + m_width / 2 - CAMERA_WIDTH / 2);
  if (m_y + m_height / 2 < CAMERA_HEIGHT / 2)
    c.setY(0);
  else if (m_y + m_height / 2 > c.getMaxY() + (CAMERA_HEIGHT / 2))
    c.setY(c.getMaxY());
  else
    c.setY(m_y + m_height / 2 - CAMERA_HEIGHT / 2);

  // std::cout << "moving to " << m_x << "/" << m_y << " - with - " <<
  // m_walkStand->second->getX() << "/" << m_walkStand->second->getY() << " --- "
  // << m_clock.getElapsedTime().asMicroseconds() << std::endl;

  m_clock.restart();

  return 1;
}

// Load the TeamBattle
int Team::loadTeamBattle(Game &g) {
  m_teamBattle.addMember(g.getRealDatabaseJson().getFullTeamMate(1));
  m_teamBattle.addMember(g.getRealDatabaseJson().getFullTeamMate(2));

  m_teamBattle.load(&g);

  return 0;
}