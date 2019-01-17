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
*  Mother class of surfaces.
*
*/

#pragma once


class Surface
{
public:
	Surface();
	virtual ~Surface();

public:
	/**
	* \brief Return if it should be printed	.
	*
	* \return bool object.
	*/
	bool getEnable() const;
	/**
	* \brief Return the abciss of the Surface	.
	*
	* \return int object.
	*/
	int getX() const;
	/**
	* \brief Return the y position of the Surface	.
	*
	* \return int object.
	*/
	int getY() const;
	/**
	* \brief Return the width of the Surface	.
	*
	* \return int object.
	*/
	int getWidth() const;
	/**
	* \brief Return the height of the Surface	.
	*
	* \return int object.
	*/
	int getHeight() const;

	/**
	* \brief Modify if it should be printed	.
	*
	* \param e The new value.
	* \return int object.
	*/
	int setEnable(const bool &e);
	/**
	* \brief Modify the abciss of the Surface	.
	*
	* \param x The new value.
	* \return int object.
	*/
	int setX(const int &x);
	/**
	* \brief Modify the y position of the Surface	.
	*
	* \param y The new value.
	* \return int object.
	*/
	int setY(const int &y);
	/**
	* \brief Modify the width of the Surface	.
	*
	* \param w The new value.
	* \return int object.
	*/
	int setWidth(const int &w);
	/**
	* \brief Modify the height of the Surface	.
	*
	* \param h The new value.
	* \return int object.
	*/
	int setHeight(const int &h);
	/**
	* \brief Modify everything	.
	*
	* \param -1 The new value.
	* \return int object.
	*/
	int setDimensions(const int &x, const int &y, const int &w = -1, const int &h = -1);

private:
	bool m_enable;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};
