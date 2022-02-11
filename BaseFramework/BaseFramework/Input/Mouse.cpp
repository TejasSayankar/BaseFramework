#include "Mouse.h"

namespace BaseFramework
{
	Mouse::Mouse()
	{
		for (int i = 0; i < sf::Mouse::ButtonCount; i++)
		{
			_mouseMappings.insert(std::make_pair(static_cast<sf::Mouse::Button>(i), ButtonState::NONE));
		}
	}
	void Mouse::update(sf::Event e)
	{
		for (int i = 0; i < sf::Mouse::ButtonCount; i++)
		{
			if (_mouseMappings[static_cast<sf::Mouse::Button>(i)] == ButtonState::BUTTON_PRESSED)
			{
				_mouseMappings[static_cast<sf::Mouse::Button>(i)] = ButtonState::BUTTON_HELD;
			}
			else if (_mouseMappings[static_cast<sf::Mouse::Button>(i)] == ButtonState::BUTTON_RELEASED)
			{
				_mouseMappings[static_cast<sf::Mouse::Button>(i)] = ButtonState::NONE;
			}
		}
		
		switch (e.type)
		{
		case sf::Event::MouseButtonPressed:
			_mouseMappings[e.mouseButton.button] = ButtonState::BUTTON_PRESSED;
			break;
		case sf::Event::MouseButtonReleased:
			_mouseMappings[e.mouseButton.button] = ButtonState::BUTTON_RELEASED;
			break;
		default:
			break;
		}
	}
	bool Mouse::isMousePressed(sf::Mouse::Button button) const
	{
		if (_mouseMappings.at(button) == ButtonState::BUTTON_PRESSED)
		{
			return true;
		}
		return false;
	}
	bool Mouse::isMouseHeld(sf::Mouse::Button button) const
	{
		if (_mouseMappings.at(button) == ButtonState::BUTTON_HELD)
		{
			return true;
		}
		return false;
	}
	bool Mouse::isMouseReleased(sf::Mouse::Button button) const
	{
		if (_mouseMappings.at(button) == ButtonState::BUTTON_RELEASED)
		{
			return true;
		}
		return false;
	}
}