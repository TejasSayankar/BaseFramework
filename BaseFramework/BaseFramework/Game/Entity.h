#pragma once
#include <SFML/Graphics.hpp>
namespace BaseFramework
{
	class Entity
	{
	public:
		Entity();
		~Entity();
		sf::Vector2f getPosition();
	private:
		sf::Vector2f _position;
	};
}

