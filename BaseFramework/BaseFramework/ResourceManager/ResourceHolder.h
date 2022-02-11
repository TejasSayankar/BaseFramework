#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"

namespace BaseFramework
{
	class ResourceHolder
	{
	public:
		static ResourceHolder& getInstance();
		ResourceHolder(ResourceHolder&&) = delete;
		ResourceHolder& operator = (ResourceHolder&&) = delete;
		ResourceHolder(ResourceHolder&) = delete;
		ResourceHolder& operator = (ResourceHolder&) = delete;

		ResourceManager<sf::Texture> textures;
		ResourceManager<sf::Font> fonts;
		ResourceManager<sf::SoundBuffer> soundBuffers;

	private:
		ResourceHolder();
	};

}
