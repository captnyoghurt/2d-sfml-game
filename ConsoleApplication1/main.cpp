#include <SFML/Graphics.hpp>
#include <string>
#include "constants.h"
#include "Game.h"
#include "initialization.h"

#include <iostream>
#include "Error/debugFunctions.h"

int main()
{
	int ret(0);

	try
	{
		deb_start();
		initialization();
		Game game(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);

		initiate_events("data/keyev.conf", game);

		ret = game.start();
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	deb_end();

	return ret;
}