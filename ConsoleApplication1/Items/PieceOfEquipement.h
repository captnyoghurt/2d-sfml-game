#pragma once

#include "Item.h"
#include "../Battle/TeamMate.h"

class PieceOfEquipement :
	public Item
{
public:
	enum e_POEPosition {POE_SHOES = 0b00000001, POE_LEGS = 0b00000010, POE_BELT = 0b00000100, POE_CHEST = 0b00001000, POE_HAT = 0b00010000, 
		POE_ACCESSORY = 0b00100000, POE_RIGHT_HAND = 0b01000000, POE_LEFT_HAND = 0b10000000, POE_TOTAL = 0b11111111};

public:
	PieceOfEquipement();
	PieceOfEquipement(const Item &item, const e_POEPosition &pos, const TeamMate::e_MateId &mid);
	PieceOfEquipement(const PieceOfEquipement &poe);
	~PieceOfEquipement();

	PieceOfEquipement& operator=(const PieceOfEquipement &poe);
public:
	// Return the position of the piece of equipement
	e_POEPosition getPosition() const;
	// Return the mate id possible
	TeamMate::e_MateId getMateId() const;
	// Return if the piece is equiped
	bool getEquiped() const;

	// Modify the position of the piece of equipement
	int setPosition(const e_POEPosition &pos);
	// Return the mate id possible
	int setMateId(const TeamMate::e_MateId &mid);
	// Modify if the piece is equiped
	int setEquiped(const bool &b);

private:
	e_POEPosition m_position;
	TeamMate::e_MateId m_mateId;
	bool m_equiped;
};

