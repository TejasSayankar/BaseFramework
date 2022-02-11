#include "Entity.h"

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
