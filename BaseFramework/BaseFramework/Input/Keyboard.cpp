#include "Keyboard.h"
#include <map>

namespace BaseFramework
{
	Keyboard::Keyboard()
	{
		for (int i = 0; i < sf::Keyboard::KeyCount; i++)
		{
			_keyMappings.insert(std::make_pair(static_cast<sf::Keyboard::Key>(i), ButtonState::NONE));
		}
	}
	void Keyboard::update(sf::Event e)
	{
		for (int i = 0; i < sf::Keyboard::KeyCount; i++)
		{
			if (_keyMappings[static_cast<sf::Keyboard::Key>(i)] == ButtonState::BUTTON_PRESSED)
			{
				_keyMappings[static_cast<sf::Keyboard::Key>(i)] = ButtonState::BUTTON_HELD;
			}
			else if (_keyMappings[static_cast<sf::Keyboard::Key>(i)] == ButtonState::BUTTON_RELEASED)
			{
				_keyMappings[static_cast<sf::Keyboard::Key>(i)] = ButtonState::NONE;
			}
		}

		switch (e.type)
		{
		case sf::Event::KeyPressed:
			_keyMappings[e.key.code] = ButtonState::BUTTON_PRESSED;
			break;
		case sf::Event::KeyReleased:
			_keyMappings[e.key.code] = ButtonState::BUTTON_RELEASED;
			break;
		default:
			break;
		}
	}
	bool Keyboard::isKeyPressed(sf::Keyboard::Key key) const
	{
		if (_keyMappings.at(key) == ButtonState::BUTTON_PRESSED)
		{
			return true;
		}
		return false;
	}
	bool Keyboard::isKeyHeld(sf::Keyboard::Key key) const
	{
		if (_keyMappings.at(key) == ButtonState::BUTTON_HELD)
		{
			return true;
		}
		return false;
	}
	bool Keyboard::isKeyReleased(sf::Keyboard::Key key) const
	{
		if (_keyMappings.at(key) == ButtonState::BUTTON_RELEASED)
		{
			return true;
		}
		return false;
	}
}