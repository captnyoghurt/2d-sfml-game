#include "ManageSound.h"
#include "../Map/ManageRessources.h"
#include "../Error/RessourceException.h"



ManageSound::ManageSound()
{
}


ManageSound::~ManageSound()
{
	clear();
}


// Return the list of sounds
std::list<std::shared_ptr<sf::Sound>> ManageSound::getSounds() const
{
	return m_sounds;
}


// Return the stack of musics
std::stack<std::shared_ptr<sf::Music>> ManageSound::getMusics() const
{
	return m_musics;
}


// Return the list of sounds with modifying possibilities
std::list<std::shared_ptr<sf::Sound>>& ManageSound::getRealSounds()
{
	return m_sounds;
}


// Return the stack of musics with modifying possibilities
std::stack<std::shared_ptr<sf::Music>>& ManageSound::getRealMusics()
{
	return m_musics;
}


// Add a new sound
int ManageSound::addSound(sf::Sound s)
{
	m_sounds.push_back(std::make_shared<sf::Sound>(s));
	m_sounds.back()->play();

	return 0;
}
int ManageSound::addSound(const sf::SoundBuffer &sbuffer)
{
	m_sounds.push_back(std::make_shared<sf::Sound>(sbuffer));
	m_sounds.back()->play();

	return 0;
}
int ManageSound::addSound(const std::string &filename, ManageRessources &ress)
{
	auto sbuffer = ress.addSoundBuffer();

	if (!sbuffer->loadFromFile(filename))
		THROW_RESSOURCE("BufferSound in manager", filename);

	m_sounds.push_back(std::make_shared<sf::Sound>(*sbuffer));
	m_sounds.back()->play();

	return 0;
}


// Add a new music
int ManageSound::addMusic(const std::string &filename, bool loop)
{
	if (!m_musics.empty())
		m_musics.top()->stop();

	m_musics.push(std::make_shared<sf::Music>());

	if (!m_musics.top()->openFromFile(filename))
		THROW_RESSOURCE("Music in manager", filename);

	m_musics.top()->setLoop(loop);

	return 0;
}


// Delete the top music
int ManageSound::deleteMusic()
{
	if (m_musics.empty())
		THROW_GAME("Empty stack of music");

	sf::Music::Status played(m_musics.top()->getStatus());

	m_musics.top()->stop();

	m_musics.pop();

	if (m_musics.empty())
		return 1;

	if(played == sf::Music::Status::Playing)
		m_musics.top()->play();

	return 0;
}


// Update the manager
int ManageSound::update()
{
	// Delete all the stopped sounds

	for (auto it(m_sounds.begin()); it != m_sounds.end(); it++)
	{
		if ((*it)->getStatus() == sf::Sound::Status::Stopped)
		{
			it = m_sounds.erase(it);
			it--;
		}
	}

	return 0;
}


// Clear all the sounds and music
int ManageSound::clear()
{
	m_sounds.clear();
	
	while (!m_musics.empty())
		m_musics.pop();

	return 0;
}