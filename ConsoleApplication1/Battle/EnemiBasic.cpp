#include "EnemiBasic.h"
#include "B_Event.h"
#include "B_EventAttack.h"
#include "Battle.h"
#include "../Game.h"



EnemiBasic::EnemiBasic()
{
}


EnemiBasic::EnemiBasic(const Fighter &f) : Fighter(f)
{

}


EnemiBasic::~EnemiBasic()
{
}


// Take a decision for the next battle action
std::shared_ptr<B_Event> EnemiBasic::chooseEvent(Game *g)
{
	std::uniform_int_distribution<int> distribution(1, g->getRealBattle().getAllies().getNumberTeamMateAlive());
	int n(distribution(m_generator));

	for (unsigned int i(0); i < g->getRealBattle().getAllies().getTeam().size(); i++)
	{
		if (!g->getRealBattle().getAllies().getTeam().at(i)->isDead())
			n--;

		if (n == 0)
		{
			B_EventAttack evt(this->getName() + " attaque !");
			evt.getRealEnemyDestination().push_back(g->getRealBattle().getRealAllies().getRealTeam().at(i));
			evt.getRealSource() = std::make_shared<EnemiBasic>(*this);
			evt.getRealSound() = std::make_shared<sf::SoundBuffer>(g->getRealRessourceManager().at(Game::e_ressourcesLayer::RESSOURCES_BATTLE).getTheSoundBuffer(0));

			return std::make_shared<B_EventAttack>(evt);
		}
	}

	return std::make_shared<B_Event>(B_Event());
}