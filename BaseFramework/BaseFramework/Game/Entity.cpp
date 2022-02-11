#include "Entity.h"

namespace BaseFramework
{
	Entity::Entity() : _position(sf::Vector2f())
	{
	}

	Entity::~Entity()
	{
	}

	sf::Vector2f Entity::getPosition()
	{
		return _position;
	}
}
