#include "PieceOfEquipement.h"
#include "../Error/ValueException.h"



PieceOfEquipement::PieceOfEquipement() :
	Item()
{
	m_position = PieceOfEquipement::e_POEPosition::POE_TOTAL;
	m_mateId = TeamMate::e_MateId::MATE_ID_ALL;
	m_equiped = false;
}

PieceOfEquipement::PieceOfEquipement(const Item &item, const e_POEPosition &pos, const TeamMate::e_MateId &mid) : 
	Item(item)
{
	setPosition(pos);
	setMateId(mid);
	m_equiped = false;
}

PieceOfEquipement::PieceOfEquipement(const PieceOfEquipement &poe)
{
	setId(poe.getId());
	setName(poe.getName());
	setDescription(poe.getDescription());
	setPriceBuy(poe.getPriceBuy());
	setPriceSell(poe.getPriceSell());
	setType(poe.getType());
	setPosition(poe.getPosition());
	setMateId(poe.getMateId());
	m_equiped = false;
}


PieceOfEquipement::~PieceOfEquipement()
{
}


PieceOfEquipement& PieceOfEquipement::operator=(const PieceOfEquipement &poe)
{
	setId(poe.getId());
	setName(poe.getName());
	setDescription(poe.getDescription());
	setPriceBuy(poe.getPriceBuy());
	setPriceSell(poe.getPriceSell());
	setType(poe.getType());
	setPosition(poe.getPosition());
	setMateId(poe.getMateId());

	return *this;
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


// Return if the piece is equiped
bool PieceOfEquipement::getEquiped() const
{
	return m_equiped;
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


// Modify if the piece is equiped
int PieceOfEquipement::setEquiped(const bool &b)
{
	m_equiped = b;

	return 0;
}