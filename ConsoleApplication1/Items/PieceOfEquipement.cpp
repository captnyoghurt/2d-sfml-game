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


// Return the mate id possible
TeamMate::e_MateId PieceOfEquipement::getMateId() const
{
	return m_mateId;
}


// Modify the position of the piece of equipement
int PieceOfEquipement::setPosition(const PieceOfEquipement::e_POEPosition &pos)
{
	if (pos < 0 || pos > PieceOfEquipement::e_POEPosition::POE_TOTAL)
		THROW_VALUE("Impossible value of equipement position : " + std::to_string(pos));

	m_position = pos;

	return 0;
}


// Return the mate id possible
int PieceOfEquipement::setMateId(const TeamMate::e_MateId &mid)
{
	if (mid < 0 || mid > TeamMate::e_MateId::MATE_ID_ALL)
		THROW_VALUE("Impossible value of mate id : " + std::to_string(mid));

	m_mateId = mid;

	return 0;
}