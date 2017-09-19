#include "CharCourb.h"
#include "../Error/ValueException.h"



CharCourb::CharCourb() :
	m_brut(0),
	m_simple(0),
	m_square(0),
	m_cube(0)
{
}


CharCourb::~CharCourb()
{
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