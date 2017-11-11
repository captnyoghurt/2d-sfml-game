#pragma once

#include <deque>
#include <memory>
#include <string>
#include <SFML/Audio.hpp>
#include "../Fighter.h"
#include "../../Sound/ManageSound.h"


class Battle;

class B_Event
{
public:
	B_Event();
	~B_Event();

public:
	// Return the description of the event in the fight
	std::string getDescription() const;
	// Return the number of destination for "ally" team
	int getNumberAllyDestination() const;
	// Return the number of destination for "enemy" team
	int getNumberEnemyDestination() const;

	// Modify the description of the event in the fight
	int setDescription(const std::string &description);
	// Modify the number of destination for "ally" team
	int setNumberAllyDestination(const int &n);
	// Modify the number of destination for "enemy" team
	int setNumberEnemyDestination(const int &n);

	// Return the ally destination with modifying possibilities
	std::deque< std::shared_ptr<Fighter> >& getRealAllyDestination();
	// Return the enemy destination with modifying possibilities
	std::deque< std::shared_ptr<Fighter> >& getRealEnemyDestination();
	// Return the source of the event with modifying possibilities
	std::shared_ptr<Fighter>& getRealSource();
	// Return the sound buffer with modifying possitilities
	std::shared_ptr<sf::SoundBuffer>& getRealSound();

	// Return if the deque for ally is full
	bool isAllyDestinationFull() const;
	// Return if the deque for enemy is full
	bool isEnemyDestinationFull() const;

	// Do the event
	virtual int execute(Battle *bat, ManageSound& snd);
protected:
	std::string  m_description;
	int m_numberAllyDestination;
	int m_numberEnemyDestination;
	std::deque< std::shared_ptr<Fighter> > m_allyDestination;
	std::deque< std::shared_ptr<Fighter> > m_enemyDestination;
	std::shared_ptr<Fighter> m_source;
	std::shared_ptr<sf::SoundBuffer> m_sound;
};

