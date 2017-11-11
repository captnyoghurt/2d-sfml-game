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
*  A courb for characteristic evolution.
*
*/

#pragma once


class CharCourb
{
public:
	CharCourb();
	CharCourb(const int &brut, const int &simple, const int &square, const int &cube);
	CharCourb(const CharCourb &courb);
	~CharCourb();

	CharCourb& operator=(const CharCourb &courb);
public:
	/**
	* \brief Return the id	.
	*
	* \return int object.
	*/
	int getId() const;
	/**
	* \brief Return the brut coeff	.
	*
	* \return double object.
	*/
	double getBrut() const;
	/**
	* \brief Return the simple coeff	.
	*
	* \return double object.
	*/
	double getSimple() const;
	/**
	* \brief Return the square coeff	.
	*
	* \return double object.
	*/
	double getSquare() const;
	/**
	* \brief Return the cube coeff	.
	*
	* \return double object.
	*/
	double getCube() const;

	/**
	* \brief Modify the id	.
	*
	* \param id The new value.
	* \return int object.
	*/
	int setId(const int &id);
	/**
	* \brief Modify the brut coeff	.
	*
	* \param brut The new value.
	* \return int object.
	*/
	int setBrut(const double &brut);
	/**
	* \brief Modify the simple coeff	.
	*
	* \param simple The new value.
	* \return int object.
	*/
	int setSimple(const double &simple);
	/**
	* \brief Modify the square coeff	.
	*
	* \param square The new value.
	* \return int object.
	*/
	int setSquare(const double &square);
	/**
	* \brief Modify the cube coeff	.
	*
	* \param cube The new value.
	* \return int object.
	*/
	int setCube(const double &cube);

	/**
	* \brief Return the value of the courb at a level	.
	*
	* \return double object.
	*/
	double result(const int &level) const;

private:
	int m_id;
	double m_brut;
	double m_simple;
	double m_square;
	double m_cube;
};