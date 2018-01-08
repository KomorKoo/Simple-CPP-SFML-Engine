#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.hpp"

class ResourceHolder {
	public:
		ResourceManager<sf::Texture>	 textures;
		ResourceManager<sf::SoundBuffer> sounds;
		ResourceManager<sf::Font>		 fonts;

	public:
		static ResourceHolder& get();

	private:
		ResourceHolder();
};