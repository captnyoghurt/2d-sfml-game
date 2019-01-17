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
*  Manage all the sound in the game.
*
*/

#pragma once

#include <memory>
#include <list>
#include <stack>
#include <SFML/Audio.hpp>

class ManageRessources;

class ManageSound
{
public:
	ManageSound();
	~ManageSound();

public:
	/**
	* \brief Return the list of sounds	.
	*
	* \return std::list<std::shared_ptr<sf::Sound>> object.
	*/
	std::list<std::shared_ptr<sf::Sound>> getSounds() const;
	/**
	* \brief Return the stack of musics	.
	*
	* \return std::stack<std::shared_ptr<sf::Music>> object.
	*/
	std::stack<std::shared_ptr<sf::Music>> getMusics() const;

	/**
	* \brief Return the list of sounds with modifying possibilities	.
	*
	* \return std::list<std::shared_ptr<sf::Sound>>& object.
	*/
	std::list<std::shared_ptr<sf::Sound>>& getRealSounds();
	/**
	* \brief Return the stack of musics with modifying possibilities	.
	*
	* \return std::stack<std::shared_ptr<sf::Music>>& object.
	*/
	std::stack<std::shared_ptr<sf::Music>>& getRealMusics();

	/**
	* \brief Add a new sound	.
	*
	* \return int object.
	*/
	int addSound(sf::Sound s);
	int addSound(sf::SoundBuffer &sbuffer);
	int addSound(const std::string &filename, ManageRessources &ress);
	/**
	* \brief Add a new music	.
	*
	* \return int object.
	*/
	int addMusic(const std::string &filename, bool loop = true);

	/**
	* \brief Delete the top music	.
	*
	* \return int object.
	*/
	int deleteMusic();

	/**
	* \brief Update the manager	.
	*
	* \return int object.
	*/
	int update();
	/**
	* \brief Clear all the sounds and music	.
	*
	* \return int object.
	*/
	int clear();

public:
	std::list<std::shared_ptr<sf::Sound>> m_sounds;
	std::stack<std::shared_ptr<sf::Music>> m_musics;
	sf::Clock m_clock;
};
