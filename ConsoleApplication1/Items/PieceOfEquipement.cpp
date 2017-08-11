#include "PieceOfEquipement.h"
#include "../Error/ValueException.h"



PieceOfEquipement::PieceOfEquipement()
{
}


PieceOfEquipement::~PieceOfEquipement()
{
}


// Return the position of the piece of equipement
PieceOfEquipement::e_POEPosition PieceOfEquipement::getPosition() const
{
	return m_position;
}

// Modify the position of the piece of equipement
int PieceOfEquipement::setPosition(const PieceOfEquipement::e_POEPosition &pos)
{
	if (pos < 0 || pos > PieceOfEquipement::e_POEPosition::POE_TOTAL)
		THROW_VALUE("Impossible value of equipement position : " + std::to_string(pos));

	m_position = pos;

	return 0;
}