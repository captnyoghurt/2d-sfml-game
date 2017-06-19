#include <SFML/Graphics.hpp>
#include <string>
#include "constants.h"
#include "Game.h"
#include "initialization.h"

#include <iostream>

int main()
{
	initialization();
	Game game(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);

	if (initiate_events("data/keyev.conf", game) != 0)
		return -2;

	int ret = game.start();

	return ret;
}