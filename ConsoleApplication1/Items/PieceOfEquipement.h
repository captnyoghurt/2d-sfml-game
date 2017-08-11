#pragma once

#include "Item.h"

class PieceOfEquipement :
	public Item
{
public:
	enum e_POEPosition {POE_SHOES = 0b00000001, POE_LEGS = 0b00000010, POE_BELT = 0b00000100, POE_CHEST = 0b00001000, POE_HAT = 0b00010000, 
		POE_ACCESSORY = 0b00100000, POE_RIGHT_HAND = 0b01000000, POE_LEFT_HAND = 0b10000000, POE_TOTAL = 0b11111111};

public:
	PieceOfEquipement();
	~PieceOfEquipement();

public:
	// Return the position of the piece of equipement
	e_POEPosition getPosition() const;

	// Modify the position of the piece of equipement
	int setPosition(const e_POEPosition &pos);

private:
	e_POEPosition m_position;
};

