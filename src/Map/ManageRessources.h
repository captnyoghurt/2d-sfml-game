/** / SFML /
 *  @file
 *  @author  Paul Coignet
 *  @date    11 / 11 / 2017
 *  @version 0.1
 *
 *  @brief Class header.
 *
 *  @section DESCRIPTION
 *
 *  Save and manage the different ressources.
 *
 */

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <list>

class ManageRessources {
 public:
  ManageRessources();
  ~ManageRessources();

 public:
  /**
   * \brief Return all the fonts	.
   *
   * \return std::list<sf::Font> object.
   */
  std::list<sf::Font> getFonts() const;
  /**
   * \brief Return all the images	.
   *
   * \return std::list<sf::Image> object.
   */
  std::list<sf::Image> getImages() const;
  /**
   * \brief Return all the textures	.
   *
   * \return std::list<sf::Texture> object.
   */
  std::list<sf::Texture> getTextures() const;
  /**
   * \brief Return all the sound buffers	.
   *
   * \return std::list<sf::SoundBuffer> object.
   */
  std::list<sf::SoundBuffer> getSoundBuffers() const;

  /**
   * \brief Return a font	.
   *
   * \return sf::Font& object.
   */
  sf::Font& getTheFont(int n);
  /**
   * \brief Return a image	.
   *
   * \return sf::Image& object.
   */
  sf::Image& getTheImage(int n);
  /**
   * \brief Return a texture	.
   *
   * \return sf::Texture& object.
   */
  sf::Texture& getTheTexture(int n);
  /**
   * \brief Return a sound buffer	.
   *
   * \return sf::SoundBuffer& object.
   */
  sf::SoundBuffer& getTheSoundBuffer(int n);

  /**
   * \brief Return all the fonts with modifying possibilities	.
   *
   * \return std::list<sf::Font>& object.
   */
  std::list<sf::Font>& getRealFonts();
  /**
   * \brief Return all the images with modifying possibilities	.
   *
   * \return std::list<sf::Image>& object.
   */
  std::list<sf::Image>& getRealImages();
  /**
   * \brief Return all the textures with modifying possibilities	.
   *
   * \return std::list<sf::Texture>& object.
   */
  std::list<sf::Texture>& getRealTextures();
  /**
   * \brief Return all the sound buffers with modifying possibilities	.
   *
   * \return std::list<sf::SoundBuffer>& object.
   */
  std::list<sf::SoundBuffer>& getRealSoundBuffers();

  /**
   * \brief Add a font ressource	.
   *
   * \return std::list<sf::Font>::iterator object.
   */
  std::list<sf::Font>::iterator addFont(sf::Font f);
  std::list<sf::Font>::iterator addFont();
  /**
   * \brief Add an image ressource	.
   *
   * \return std::list<sf::Image>::iterator object.
   */
  std::list<sf::Image>::iterator addImage(sf::Image img);
  std::list<sf::Image>::iterator addImage();
  /**
   * \brief Add a texture ressource	.
   *
   * \return std::list<sf::Texture>::iterator object.
   */
  std::list<sf::Texture>::iterator addTexture(sf::Texture texture);
  std::list<sf::Texture>::iterator addTexture();
  /**
   * \brief Add a sound buffer	.
   *
   * \return std::list<sf::SoundBuffer>::iterator object.
   */
  std::list<sf::SoundBuffer>::iterator addSoundBuffer(sf::SoundBuffer sbuffer);
  std::list<sf::SoundBuffer>::iterator addSoundBuffer();

  /**
   * \brief Delete a font ressource	.
   *
   * \return int object.
   */
  int deleteFont(std::list<sf::Font>::iterator it);
  /**
   * \brief Delete an image ressource	.
   *
   * \return int object.
   */
  int deleteImage(std::list<sf::Image>::iterator it);
  /**
   * \brief Delete a texture ressource	.
   *
   * \return int object.
   */
  int deleteTexture(std::list<sf::Texture>::iterator it);
  /**
   * \brief Delete a sound buffer	.
   *
   * \return int object.
   */
  int deleteSoundBuffer(std::list<sf::SoundBuffer>::iterator it);

  /**
   * \brief Clear all the ressources	.
   *
   * \return int object.
   */
  int clear();

 private:
  std::list<sf::Font> m_fonts;
  std::list<sf::Image> m_images;
  std::list<sf::Texture> m_textures;
  std::list<sf::SoundBuffer> m_soundBuffers;
};
