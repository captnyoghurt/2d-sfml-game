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
 *  A piece of equipement for a fighter.
 *
 */

#pragma once

#include "../Battle/Fighters/TeamMate.h"
#include "Item.h"

class PieceOfEquipement : public Item {
 public:
  enum e_POEPosition {
    POE_SHOES = 0b00000001,
    POE_LEGS = 0b00000010,
    POE_BELT = 0b00000100,
    POE_CHEST = 0b00001000,
    POE_HAT = 0b00010000,
    POE_ACCESSORY = 0b00100000,
    POE_RIGHT_HAND = 0b01000000,
    POE_LEFT_HAND = 0b10000000,
    POE_TOTAL = 0b11111111
  };

 public:
  PieceOfEquipement();
  PieceOfEquipement(const Item &item, const e_POEPosition &pos,
                    const TeamMate::e_MateId &mid);
  PieceOfEquipement(const PieceOfEquipement &poe);
  ~PieceOfEquipement();

  PieceOfEquipement &operator=(const PieceOfEquipement &poe);

 public:
  /**
   * \brief Return the position of the piece of equipement	.
   *
   * \return e_POEPosition object.
   */
  e_POEPosition getPosition() const;
  /**
   * \brief Return the mate id possible	.
   *
   * \return TeamMate::e_MateId object.
   */
  TeamMate::e_MateId getMateId() const;
  /**
   * \brief Return if the piece is equiped	.
   *
   * \return bool object.
   */
  bool getEquiped() const;

  /**
   * \brief Modify the position of the piece of equipement	.
   *
   * \param pos The new value.
   * \return int object.
   */
  int setPosition(const e_POEPosition &pos);
  /**
   * \brief Return the mate id possible	.
   *
   * \return int object.
   */
  int setMateId(const TeamMate::e_MateId &mid);
  /**
   * \brief Modify if the piece is equiped	.
   *
   * \param b The new value.
   * \return int object.
   */
  int setEquiped(const bool &b);

 private:
  e_POEPosition m_position;
  TeamMate::e_MateId m_mateId;
  bool m_equiped;
};
