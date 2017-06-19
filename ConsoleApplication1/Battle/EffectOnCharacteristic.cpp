#include "EffectOnCharacteristic.h"



EffectOnCharacteristic::EffectOnCharacteristic(const int &brut, const double &ratio)
{
	m_brut = brut;
	m_ratio = ratio;
}


EffectOnCharacteristic::~EffectOnCharacteristic()
{
}


// Return the ratio of the bonus
double EffectOnCharacteristic::getRatio() const
{
	return m_ratio;
}


// Return the brut bonus
int EffectOnCharacteristic::getBrut() const
{
	return m_brut;
}


// Return the number of turn stayed
int EffectOnCharacteristic::getNumberOfTurn() const
{
	return m_numberOfTurn;
}


// Modify the ratio of the bonus
int EffectOnCharacteristic::setRatio(const double &ratio)
{
	m_ratio = ratio;

	return 0;
}


// Modify the brut bonus
int EffectOnCharacteristic::setBrut(const int &brut)
{
	m_brut = brut;

	return 0;
}


// Modify the number of turn stayed
int EffectOnCharacteristic::setNumberOfTurn(const int &turn)
{
	m_numberOfTurn = turn;

	return 0;
}


// Update the effect
int EffectOnCharacteristic::update()
{
	if (m_numberOfTurn == 0)
		return 1;

	m_numberOfTurn = m_numberOfTurn - ((m_numberOfTurn > 0) ? 1 : 0);

	return 0;
}