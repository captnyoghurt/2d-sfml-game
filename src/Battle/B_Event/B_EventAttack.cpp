/**
*  @file
*  @author  Paul Coignet
*  @date    11 / 11 / 2017
*  @version 0.1
*
*  @brief Class header.
*
*  @section DESCRIPTION
*
*  Make an attack.
*
*/

#include "B_EventAttack.h"
#include "../../constants.h"
#include "../../Battle/Battle.h"
#include "../../Error/ValueException.h"


B_EventAttack::B_EventAttack(const std::string &description)
{
	m_numberAllyDestination = 0;
	m_numberEnemyDestination = 1;

	m_description = description;
}


B_EventAttack::~B_EventAttack()
{
}

extern sf::SoundBuffer GLOB_sbuffer;
// Do the event
int B_EventAttack::execute(Battle *bat, ManageSound& snd)
{
	// [TODO]
	// L'attaque
	// /!\ S'il y a un effet miroir sur le receveur

	// Check if destinations are chosen
	if (m_enemyDestination.size() < (unsigned)m_numberEnemyDestination
		|| m_allyDestination.size() < (unsigned)m_numberAllyDestination)
		THROW_VALUE("Not enough destination " + std::to_string(m_enemyDestination.size()) + "/" + std::to_string(m_allyDestination.size()));

	// <debuging>
	bat->getRealBattleEventManager().setWaiting(false);

	if (m_enemyDestination.at(0)->getHealth().getPoints() <= 0)
	{
		if (!m_enemyDestination.at(0)->isTeamMate())
		{
			std::vector< std::shared_ptr<Fighter> >&fighters = bat->getRealEnemies().getRealTeam();

			for (unsigned int i(0); i < fighters.size(); i++)
				if (fighters.at(i)->getHealth().getPoints() > 0)
				{
					m_enemyDestination.at(0) = fighters.at(i);
					break;
				}
		}
		else
		{
			std::vector< std::shared_ptr<TeamMate> >&fighters = bat->getRealAllies().getRealTeam();

			for (unsigned int i(0); i < fighters.size(); i++)
				if (fighters.at(i)->getHealth().getPoints() > 0)
				{
					m_enemyDestination.at(0) = fighters.at(i);
					break;
				}
		}
	}

	if (m_sound != nullptr)
		snd.addSound(*m_sound);

	m_enemyDestination.at(0)->getRealHealth().use(MAX(1,
		m_source->getCharacteristics().at(Characteristic::e_characteristics::ATTACK_PHYSIC).getValue() -
		m_enemyDestination.at(0)->getCharacteristics().at(Characteristic::e_characteristics::DEFENSE_PHYSIC).getValue()
	));

	return 0;
}