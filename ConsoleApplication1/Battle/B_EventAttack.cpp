#include "B_EventAttack.h"
#include "../Battle/Battle.h"


B_EventAttack::B_EventAttack(const std::string &description)
{
	m_numberAllyDestination = 0;
	m_numberEnemyDestination = 1;

	m_description = description;
}


B_EventAttack::~B_EventAttack()
{
}

// Do the event
int B_EventAttack::execute(Battle *bat)
{
	// [TODO]
	// L'attaque
	// /!\ S'il y a un effet miroir sur le receveur

	// Check if destinations are chosen
	if (m_enemyDestination.size() < (unsigned)m_numberEnemyDestination
		|| m_allyDestination.size() < (unsigned)m_numberAllyDestination)
		return -1;

	// <debuging>
	bat->getRealBattleEventManager().setWaiting(false);
	
	m_enemyDestination.at(0)->getRealHealth().use(
		m_source->getCharacteristics().at(Characteristic::e_characteristics::ATTACK_PHYSIC).getValue() -
		m_enemyDestination.at(0)->getCharacteristics().at(Characteristic::e_characteristics::DEFENSE_PHYSIC).getValue()
	);

	return 0;
}