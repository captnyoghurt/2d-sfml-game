#include "EnemiBasic.h"
#include "B_Event.h"
#include "B_EventAttack.h"
#include "Battle.h"



EnemiBasic::EnemiBasic()
{
}


EnemiBasic::~EnemiBasic()
{
}


// Take a decision for the next battle action
std::shared_ptr<B_Event> EnemiBasic::chooseEvent(Battle &b)
{
	std::uniform_int_distribution<int> distribution(1, b.getAllies().getNumberTeamMateAlive());
	int n(distribution(m_generator));

	for (unsigned int i(0); i < b.getAllies().getTeam().size(); i++)
	{
		if (!b.getAllies().getTeam().at(i).isDead())
			n--;

		if (n == 0)
		{
			B_EventAttack evt(this->getName() + " attaque !");
			evt.getRealEnemyDestination().push_back(std::make_shared<TeamMate>(b.getRealAllies().getRealTeam().at(i)));
			evt.getRealSource() = std::make_shared<EnemiBasic>(*this);

			return std::make_shared<B_EventAttack>(evt);
		}
	}

	return std::make_shared<B_Event>(B_Event());
}