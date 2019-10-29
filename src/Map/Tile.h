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
 *  A tile with a specific size and hitbox.
 *  Key element of a map.
 *
 */

#pragma once
#include <vector>

class Tile {
 public:
  Tile();
  Tile(unsigned short x, unsigned short y, short w, short h);
  Tile(const Tile &t);
  ~Tile();

  Tile &operator=(const Tile &t);

 public:
  /**
   * \brief Return if the tile is empty or not	.
   *
   * \return bool object.
   */
  bool getEmpty() const;
  /**
   * \brief Return the abciss of the Tile	.
   *
   * \return unsigned object.
   */
  unsigned short getX() const;
  /**
   * \brief Return the y position of the Tile	.
   *
   * \return unsigned object.
   */
  unsigned short getY() const;
  /**
   * \brief Return the width of the Tile	.
   *
   * \return short object.
   */
  short getWidth() const;
  /**
   * \brief Return the height of the Tile	.
   *
   * \return short object.
   */
  short getHeight() const;
  /**
   * \brief Return the proprietes of the Tile	.
   *
   * \return std::vector<int> object.
   */
  std::vector<int> getProprieties() const;

  /**
   * \brief Modify if the tile is empty or not	.
   *
   * \param b The new value.
   * \return int object.
   */
  int setEmpty(const bool &b);
  /**
   * \brief Modify the abciss of the Tile	.
   *
   * \param x The new value.
   * \return int object.
   */
  int setX(const unsigned short &x);
  /**
   * \brief Modify the y position of the Tile	.
   *
   * \param y The new value.
   * \return int object.
   */
  int setY(const unsigned short &y);
  /**
   * \brief Modify the width of the Tile	.
   *
   * \param w The new value.
   * \return int object.
   */
  int setWidth(const short &w);
  /**
   * \brief Modify the height of the Tile	.
   *
   * \param h The new value.
   * \return int object.
   */
  int setHeight(const short &h);
  /**
   * \brief Modify the proprietes of the Tile	.
   *
   * \param props The new value.
   * \return int object.
   */
  int setProprieties(const std::vector<int> &props);

 private:
  std::vector<int> m_proprieties;
  bool m_empty;
  unsigned short m_x;
  unsigned short m_y;
  short m_width;
  short m_height;
};
