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
 *  Layer of tile in the map.
 *
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

using namespace sf;

class Layer {
 public:
  Layer();
  Layer(int w, int h, int tw, int th);
  ~Layer();

 public:
  /**
   * \brief Return all the tile of the layer	.
   *
   * \return std::vector< object.
   */
  std::vector<std::vector<Tile> > getLayer() const;
  /**
   * \brief Return the width of the layer	.
   *
   * \return int object.
   */
  int getWitdth() const;
  /**
   * \brief Return the height of the layer	.
   *
   * \return int object.
   */
  int getHeight() const;
  /**
   * \brief Return the width of each tile	.
   *
   * \return int object.
   */
  int getTileW() const;
  /**
   * \brief Return the height of each tile	.
   *
   * \return int object.
   */
  int getTileH() const;
  /**
   * \brief Return the tile asked (x,y) from the layer	.
   *
   * \return Tile& object.
   */
  Tile &getTile(int x, int y);

  /**
   * \brief Modify the width of the layer	.
   *
   * \param w The new value.
   * \return int object.
   */
  int setWitdth(const int &w);
  /**
   * \brief Modify the height of the layer	.
   *
   * \param h The new value.
   * \return int object.
   */
  int setHeight(const int &h);
  /**
   * \brief Modify the width and the height	.
   *
   * \param h The new value.
   * \return int object.
   */
  int resize(const int &w, const int &h);
  /**
   * \brief Modify the width of each tile	.
   *
   * \param w The new value.
   * \return int object.
   */
  int setTileW(const int &w);
  /**
   * \brief Modify the height of each tile	.
   *
   * \param h The new value.
   * \return int object.
   */
  int setTileH(const int &h);
  /**
   * \brief Modify the tile asked (x,y) from the layer	.
   *
   * \param t The new value.
   * \return int object.
   */
  int setTile(int x, int y, const Tile &t);

  /**
   * \brief Print the layer thanks to the tileset	.
   *
   * \return int object.
   */
  int printLayer(Texture tileset, RenderWindow &win, int xCam, int yCam,
                 int wCam, int hCam);

 private:
  std::vector<std::vector<Tile> > m_layer;
  int m_tileW;
  int m_tileH;
  int m_width;
  int m_height;
};
