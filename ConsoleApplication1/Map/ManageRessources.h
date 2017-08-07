#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <list>

class ManageRessources
{
public:
	ManageRessources();
	~ManageRessources();

public:
	// Return all the fonts
	std::list<sf::Font> getFonts() const;
	// Return all the images
	std::list<sf::Image> getImages() const;
	// Return all the textures
	std::list<sf::Texture> getTextures() const;
	// Return all the sound buffers
	std::list<sf::SoundBuffer> getSoundBuffers() const;

	// Return a font
	sf::Font& getTheFont(int n);
	// Return a image
	sf::Image& getTheImage(int n);
	// Return a texture
	sf::Texture& getTheTexture(int n);
	// Return a sound buffer
	sf::SoundBuffer& getTheSoundBuffer(int n);

	// Return all the fonts with modifying possibilities
	std::list<sf::Font>& getRealFonts();
	// Return all the images with modifying possibilities
	std::list<sf::Image>& getRealImages();
	// Return all the textures with modifying possibilities
	std::list<sf::Texture>& getRealTextures();
	// Return all the sound buffers with modifying possibilities
	std::list<sf::SoundBuffer>& getRealSoundBuffers();

	// Add a font ressource
	std::list<sf::Font>::iterator addFont(sf::Font f);
	std::list<sf::Font>::iterator addFont();
	// Add an image ressource
	std::list<sf::Image>::iterator addImage(sf::Image img);
	std::list<sf::Image>::iterator addImage();
	// Add a texture ressource
	std::list<sf::Texture>::iterator addTexture(sf::Texture texture);
	std::list<sf::Texture>::iterator addTexture();
	// Add a sound buffer
	std::list<sf::SoundBuffer>::iterator addSoundBuffer(sf::SoundBuffer sbuffer);
	std::list<sf::SoundBuffer>::iterator addSoundBuffer();

	// Delete a font ressource
	int deleteFont(std::list<sf::Font>::iterator it);
	// Delete an image ressource
	int deleteImage(std::list<sf::Image>::iterator it);
	// Delete a texture ressource
	int deleteTexture(std::list<sf::Texture>::iterator it);
	// Delete a sound buffer
	int deleteSoundBuffer(std::list<sf::SoundBuffer>::iterator it);

	// Clear all the ressources
	int clear();
private:
	std::list<sf::Font> m_fonts;
	std::list<sf::Image> m_images;
	std::list<sf::Texture> m_textures;
	std::list<sf::SoundBuffer> m_soundBuffers;
};

