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
 *  An effect on a characteristic of a fighter.
 *
 */

#pragma once
class EffectOnCharacteristic {
 public:
  EffectOnCharacteristic(const int &brut = 0, const double &ratio = 1.0);
  ~EffectOnCharacteristic();

 public:
  /**
   * \brief Return the ratio of the bonus	.
   *
   * \return double object.
   */
  double getRatio() const;
  /**
   * \brief Return the brut bonus	.
   *
   * \return int object.
   */
  int getBrut() const;
  /**
   * \brief Return the number of turn stayed	.
   *
   * \return int object.
   */
  int getNumberOfTurn() const;

  /**
   * \brief Modify the ratio of the bonus	.
   *
   * \param ratio The new value.
   * \return int object.
   */
  int setRatio(const double &ratio);
  /**
   * \brief Modify the brut bonus	.
   *
   * \param brut The new value.
   * \return int object.
   */
  int setBrut(const int &brut);
  /**
   * \brief Modify the number of turn stayed	.
   *
   * \param turn The new value.
   * \return int object.
   */
  int setNumberOfTurn(const int &turn);

  /**
   * \brief Update the effect	.
   *
   * \return int object.
   */
  int update();

 private:
  double m_ratio;
  int m_brut;
  int m_numberOfTurn;
};
