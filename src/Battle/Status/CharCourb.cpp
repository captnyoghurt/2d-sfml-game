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

#include "CharCourb.h"
#include "../../Error/ValueException.h"



CharCourb::CharCourb() :
	m_id(0),
	m_brut(0),
	m_simple(0),
	m_square(0),
	m_cube(0)
{
}


CharCourb::CharCourb(const int &brut, const int &simple, const int &square, const int &cube) :
	m_id(0),
	m_brut(brut),
	m_simple(simple),
	m_square(square),
	m_cube(cube)
{
	
}


CharCourb::CharCourb(const CharCourb &courb) :
	m_id(courb.getId()),
	m_brut(courb.getBrut()),
	m_simple(courb.getSimple()),
	m_square(courb.getSquare()),
	m_cube(courb.getCube())
{
	
}


CharCourb::~CharCourb()
{
}


CharCourb& CharCourb::operator=(const CharCourb &courb)
{
	m_id = courb.getId();
	m_simple = courb.getSimple();
	m_brut = courb.getBrut();
	m_square = courb.getSquare();
	m_cube = courb.getCube();

	return *this;
}


// Return the id
int CharCourb::getId() const
{
	return m_id;
}


// Return the brut coeff
double CharCourb::getBrut() const
{
	return m_brut;
}


// Return the simple coeff
double CharCourb::getSimple() const
{
	return m_simple;
}


// Return the square coeff
double CharCourb::getSquare() const
{
	return m_square;
}


// Return the cube coeff
double CharCourb::getCube() const
{
	return m_cube;
}


// Modify the id
int CharCourb::setId(const int &id)
{
	if (id < 0)
		THROW_VALUE("Wrong id value : " + std::to_string(id));

	m_id = id;

	return 0;
}


// Modify the brut coeff
int CharCourb::setBrut(const double &brut)
{
	m_brut = brut;

	return 0;
}


// Modify the simple coeff
int CharCourb::setSimple(const double &simple)
{
	m_simple = simple;

	return 0;
}


// Modify the square coeff
int CharCourb::setSquare(const double &square)
{
	m_square = square;

	return 0;
}


// Modify the cube coeff
int CharCourb::setCube(const double &cube)
{
	m_cube = cube;

	return 0;
}


// Return the value of the courb at a level
double CharCourb::result(const int &level) const
{
	if (level < 0)
		THROW_VALUE("Wrong level value : " + std::to_string(level));

	return (level*(level*(level*(m_cube) + m_square) + m_simple) + m_brut);
}