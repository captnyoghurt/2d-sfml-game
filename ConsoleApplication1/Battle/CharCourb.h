#pragma once


class CharCourb
{
public:
	CharCourb();
	~CharCourb();

public:
	// Return the brut coeff
	double getBrut() const;
	// Return the simple coeff
	double getSimple() const;
	// Return the square coeff
	double getSquare() const;
	// Return the cube coeff
	double getCube() const;

	// Modify the brut coeff
	int setBrut(const double &brut);
	// Modify the simple coeff
	int setSimple(const double &simple);
	// Modify the square coeff
	int setSquare(const double &square);
	// Modify the cube coeff
	int setCube(const double &cube);

	// Return the value of the courb at a level
	double result(const int &level) const;

private:
	double m_brut;
	double m_simple;
	double m_square;
	double m_cube;
};

