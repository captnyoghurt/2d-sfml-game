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
	// Return the id
	int getId() const;
	// Return the brut coeff
	double getBrut() const;
	// Return the simple coeff
	double getSimple() const;
	// Return the square coeff
	double getSquare() const;
	// Return the cube coeff
	double getCube() const;

	// Modify the id
	int setId(const int &id);
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
	int m_id;
	double m_brut;
	double m_simple;
	double m_square;
	double m_cube;
};