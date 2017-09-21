#pragma once

#include "Fighter.h"
#include "CharCourb.h"

class TeamMate : public Fighter
{
public:
	enum e_MateId {MATE_ID_CHAR1 = 0b00001, MATE_ID_CHAR2 = 0b00010, MATE_ID_CHAR3 = 0b00100, MATE_ID_CHAR4 = 0b01000, MATE_ID_CHAR5 = 0b10000, MATE_ID_ALL = 0b11111};

public:
	TeamMate();
	TeamMate(const TeamMate &tm);
	~TeamMate();

public:
	// Return the courbs
	std::vector<CharCourb> getCourbs() const;

	// Return the courbs with modifying possibilities
	std::vector<CharCourb>& getRealCourb();

	// Take a decision for the next battle action
	virtual std::shared_ptr<B_Event> chooseEvent(Game *g);
	// True if the fighter is in reality a TeamMate
	virtual bool isTeamMate() const;

private:
	std::vector<CharCourb> m_courbs;
};

