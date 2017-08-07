#pragma once

#include <memory>
#include <list>
#include <stack>
#include <SFML/Audio.hpp>

class ManageSound
{
public:
	ManageSound();
	~ManageSound();

public:
	// Return the list of sounds
	std::list<std::shared_ptr<sf::Sound>> getSounds() const;
	// Return the stack of musics
	std::stack<std::shared_ptr<sf::Music>> getMusics() const;

	// Return the list of sounds with modifying possibilities
	std::list<std::shared_ptr<sf::Sound>>& getRealSounds();
	// Return the stack of musics with modifying possibilities
	std::stack<std::shared_ptr<sf::Music>>& getRealMusics();

public:
	std::list<std::shared_ptr<sf::Sound>> m_sounds;
	std::stack<std::shared_ptr<sf::Music>> m_musics;
};

