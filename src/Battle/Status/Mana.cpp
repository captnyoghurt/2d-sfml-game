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
 *  Mana of a fighter.
 *
 */

#include "Mana.h"
#include "../../constants.h"
#include "Spell.h"

Mana::Mana() {
  m_maxPoints = MANA_MAX_POINTS;
  m_points = m_maxPoints;
}

Mana::Mana(const Mana &mana) {
  m_maxPoints = mana.getMaxPoints();
  m_points = mana.getPoints();
}

Mana::Mana(const int &max) {
  m_maxPoints = max;
  m_points = max;
}

Mana::~Mana() {}

Mana &Mana::operator=(const Mana &mana) {
  m_maxPoints = mana.getMaxPoints();
  m_points = mana.getPoints();

  return *this;
}

// Return the number of mana points
int Mana::getPoints() const { return m_points; }

// Return the maximum number of mana points
int Mana::getMaxPoints() const { return m_maxPoints; }

// Modify the number of mana points
int Mana::setPoints(const int &p) {
  if (p >= 0 && p <= m_maxPoints) {
    m_points = p;
    return 0;
  }
  return -1;
}

// Modify the maximum number of mana points
int Mana::setMaxPoints(const int &maxp) {
  if (maxp < 0) return -1;

  m_maxPoints = maxp;

  if (m_points > m_maxPoints) m_points = m_maxPoints;

  return 0;
}

// Say if a spell can be used
bool Mana::canCastSpell(const Spell &sp) {
  //[TODO]

  return true;
}

// Say if there is enought mana point
bool Mana::enoughFor(const int &points) { return (m_points >= points); }

// Use some mana points
int Mana::use(const int &points) {
  if (!enoughFor(points)) return -1;

  m_points -= points;

  return 0;
}
int Mana::use(const Spell &sp) {
  if (!canCastSpell(sp)) return -1;

  //[TODO]

  return 0;
}

// Get some mana
int Mana::recharge(const int &points) {
  m_points = MIN(m_points + points, m_maxPoints);

  return 0;
}