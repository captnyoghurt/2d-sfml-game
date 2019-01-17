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
 *  Camera of the map.
 *
 */

#pragma once

class Camera {
 public:
  explicit Camera(bool blocked = true);
  Camera(const int &x, const int &y, const int &w, const int &h, const int &mx,
         const int &my, bool blocked = true);
  Camera(const Camera &c);
  ~Camera();

  Camera &operator=(const Camera &c);

 public:
  /**
   * \brief Return if the camera is blocked at the borders	.
   *
   * \return bool object.
   */
  bool getBlocked() const;
  /**
   * \brief Return the abciss of the Tile	.
   *
   * \return int object.
   */
  int getX() const;
  /**
   * \brief Return the y position of the Tile	.
   *
   * \return int object.
   */
  int getY() const;
  /**
   * \brief Return the width of the Tile	.
   *
   * \return int object.
   */
  int getWidth() const;
  /**
   * \brief Return the height of the Tile	.
   *
   * \return int object.
   */
  int getHeight() const;
  /**
   * \brief Return the maxX of the camera	.
   *
   * \return int object.
   */
  int getMaxX() const;
  /**
   * \brief Return the maxY of the camera	.
   *
   * \return int object.
   */
  int getMaxY() const;

  /**
   * \brief Modify if the camera is blocked at the borders	.
   *
   * \param b The new value.
   * \return bool object.
   */
  bool setBlocked(bool b);
  /**
   * \brief Modify the abciss of the Tile	.
   *
   * \param x The new value.
   * \return int object.
   */
  int setX(const int &x);
  /**
   * \brief Modify the y position of the Tile	.
   *
   * \param y The new value.
   * \return int object.
   */
  int setY(const int &y);
  /**
   * \brief Modify the width of the Tile	.
   *
   * \param w The new value.
   * \return int object.
   */
  int setWidth(const int &w);
  /**
   * \brief Modify the height of the Tile	.
   *
   * \param h The new value.
   * \return int object.
   */
  int setHeight(const int &h);
  /**
   * \brief Modify the maxX of the camera	.
   *
   * \param mapWidth The new value.
   * \return int object.
   */
  int setMaxX(int mapWidth);
  /**
   * \brief Modify the maxY of the camera	.
   *
   * \param mapHeight The new value.
   * \return int object.
   */
  int setMaxY(int mapHeight);

  /**
   * \brief Move the camera to a direction	.
   *
   * \return int object.
   */
  int move(const int &dx, const int &dy);

 private:
  bool m_blocked;
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_maxX;
  int m_maxY;
};
