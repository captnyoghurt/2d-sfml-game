#include "ManageRessources.h"



ManageRessources::ManageRessources()
{
}


ManageRessources::~ManageRessources()
{
	clear();
}


// Return all the fonts
std::list<sf::Font> ManageRessources::getFonts() const
{
	return m_fonts;
}


// Return all the images
std::list<sf::Image> ManageRessources::getImages() const
{
	return m_images;
}


// Return all the textures
std::list<sf::Texture> ManageRessources::getTextures() const
{
	return m_textures;
}


// Return all the sound buffers
std::list<sf::SoundBuffer> ManageRessources::getSoundBuffers() const
{
	return m_soundBuffers;
}


// Return a font
sf::Font& ManageRessources::getTheFont(int n)
{
	int i(0);

	for (auto it(m_fonts.begin()); it != m_fonts.end(); ++it, i++)
		if(i == n)
			return *it;
	return *m_fonts.begin();
}


// Return a image
sf::Image& ManageRessources::getTheImage(int n)
{
	int i(0);

	for (auto it(m_images.begin()); it != m_images.end(); ++it, i++)
		if (i == n)
			return *it;
	return *m_images.begin();
}


// Return a texture
sf::Texture& ManageRessources::getTheTexture(int n)
{
	int i(0);

	for (auto it(m_textures.begin()); it != m_textures.end(); ++it, i++)
		if (i == n)
			return *it;
	return *m_textures.begin();
}


// Return a sound buffer
sf::SoundBuffer& ManageRessources::getTheSoundBuffer(int n)
{
	int i(0);

	for (auto it(m_soundBuffers.begin()); it != m_soundBuffers.end(); ++it, i++)
		if (i == n)
			return *it;
	return *m_soundBuffers.begin();
}


// Return all the fonts with modifying possibilities
std::list<sf::Font>& ManageRessources::getRealFonts()
{
	return m_fonts;
}


// Return all the images with modifying possibilities
std::list<sf::Image>& ManageRessources::getRealImages()
{
	return m_images;
}

// Return all the textures with modifying possibilities
std::list<sf::Texture>& ManageRessources::getRealTextures()
{
	return m_textures;
}


// Return all the sound buffers with modifying possibilities
std::list<sf::SoundBuffer>& ManageRessources::getRealSoundBuffers()
{
	return m_soundBuffers;
}


// Add a font ressource
std::list<sf::Font>::iterator ManageRessources::addFont(sf::Font f)
{
	m_fonts.push_back(f);
	auto it(m_fonts.end());
	--it;

	return it;
}
std::list<sf::Font>::iterator ManageRessources::addFont()
{
	m_fonts.push_back(sf::Font());
	auto it(m_fonts.end());
	--it;

	return it;
}


// Add an image ressource
std::list<sf::Image>::iterator ManageRessources::addImage(sf::Image img)
{
	m_images.push_back(img);
	auto it(m_images.end());
	--it;

	return it;
}
std::list<sf::Image>::iterator ManageRessources::addImage()
{
	m_images.push_back(sf::Image());
	auto it(m_images.end());
	--it;

	return it;
}


// Add a texture ressource
std::list<sf::Texture>::iterator ManageRessources::addTexture(sf::Texture texture)
{
	m_textures.push_back(texture);
	auto it(m_textures.end());
	--it;

	return it;
}
std::list<sf::Texture>::iterator ManageRessources::addTexture()
{
	m_textures.push_back(sf::Texture());
	auto it(m_textures.end());
	--it;

	return it;
}


// Add a sound buffer
std::list<sf::SoundBuffer>::iterator ManageRessources::addSoundBuffer(sf::SoundBuffer sbuffer)
{
	m_soundBuffers.push_back(sbuffer);
	auto it(m_soundBuffers.end());
	--it;

	return it;
}
std::list<sf::SoundBuffer>::iterator ManageRessources::addSoundBuffer()
{
	m_soundBuffers.push_back(sf::SoundBuffer());
	auto it(m_soundBuffers.end());
	--it;

	return it;
}


// Delete a font ressource
int ManageRessources::deleteFont(std::list<sf::Font>::iterator it)
{
	m_fonts.erase(it);

	return 0;
}


// Delete an image ressource
int ManageRessources::deleteImage(std::list<sf::Image>::iterator it)
{
	m_images.erase(it);

	return 0;
}


// Delete a texture ressource
int ManageRessources::deleteTexture(std::list<sf::Texture>::iterator it)
{
	m_textures.erase(it);

	return 0;
}


// Delete a sound buffer
int ManageRessources::deleteSoundBuffer(std::list<sf::SoundBuffer>::iterator it)
{
	m_soundBuffers.erase(it);

	return 0;
}


// Clear all the ressources
int ManageRessources::clear()
{
	int ret = 0;
	m_fonts.clear();
	m_images.clear();
	m_textures.clear();
	m_soundBuffers.clear();

	return ret;
}