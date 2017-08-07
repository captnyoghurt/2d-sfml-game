#include "ManageSound.h"
#include "../Map/ManageRessources.h"
#include "../Error/RessourceException.h"



ManageSound::ManageSound()
{
}


ManageSound::~ManageSound()
{
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
	m_sounds.push_back(std::make_shared<sf::Sound>(sf::Sound(s)));

	return 0;
}
int ManageSound::addSound(const sf::SoundBuffer &sbuffer)
{
	m_sounds.push_back(std::make_shared<sf::Sound>(sf::Sound(sbuffer)));

	return 0;
}
int ManageSound::addSound(const std::string &filename, ManageRessources &ress)
{
	auto sbuffer = ress.addSoundBuffer();

	if (!sbuffer->loadFromFile(filename))
		THROW_RESSOURCE("BufferSound in manager", filename);

	m_sounds.push_back(std::make_shared<sf::Sound>(sf::Sound(*sbuffer)));

	return 0;
}