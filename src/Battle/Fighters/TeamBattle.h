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
 *  The complete ally team.
 *
 */

#pragma once

#include <vector>
#include "TeamMate.h"

class Game;

class TeamBattle {
 public:
  TeamBattle();
  ~TeamBattle();

 public:
  /**
   * \brief Return the number of team mate alive	.
   *
   * \return int object.
   */
  int getNumberTeamMateAlive() const;
  /**
   * \brief Return the team mate vector	.
   *
   * \return std::vector< object.
   */
  std::vector<std::shared_ptr<TeamMate> > getTeam() const;

  /**
   * \brief Return the team mate vector with modifying possibilities	.
   *
   * \return std::vector< object.
   */
  std::vector<std::shared_ptr<TeamMate> >& getRealTeam();

  /**
   * \brief Add a new member	.
   *
   * \return int object.
   */
  int addMember(TeamMate m);

  /**
   * \brief Load the team battle	.
   *
   * \return int object.
   */
  int load(Game* g);
  /**
   * \brief Update the team batttle	.
   *
   * \return int object.
   */
  int update();

 private:
  int m_numberTeamMateAlive;
  std::vector<std::shared_ptr<TeamMate> > m_team;
};
