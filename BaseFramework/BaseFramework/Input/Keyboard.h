#pragma once
#include<SFML/Graphics.hpp>

namespace BaseFramework
{
	enum class ButtonState
	{
		NONE,
		BUTTON_PRESSED,
		BUTTON_HELD,
		BUTTON_RELEASED,
	};
	class Keyboard
	{
	public:
		Keyboard();
		Keyboard(Keyboard&&) = delete;
		Keyboard& operator = (Keyboard&&) = delete;
		Keyboard(Keyboard&) = delete;
		Keyboard& operator = (Keyboard&) = delete;

		void update(sf::Event e);

		bool isKeyPressed(sf::Keyboard::Key key) const;
		bool isKeyHeld(sf::Keyboard::Key key) const;
		bool isKeyReleased(sf::Keyboard::Key key) const;

	private:
		std::map<sf::Keyboard::Key, ButtonState> _keyMappings;
	};

}

