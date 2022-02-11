#pragma once
#include <SFML/Graphics.hpp>
#include "Keyboard.h"

namespace BaseFramework
{
	class Mouse
	{
	public:
		Mouse();
		Mouse(Mouse&&) = delete;
		Mouse& operator = (Mouse&&) = delete;
		Mouse(Mouse&) = delete;
		Mouse& operator = (Mouse&) = delete;

		void update(sf::Event e);
		bool isMousePressed(sf::Mouse::Button button) const;
		bool isMouseHeld(sf::Mouse::Button button) const;
		bool isMouseReleased(sf::Mouse::Button button) const;

	private:
		std::map<sf::Mouse::Button, ButtonState> _mouseMappings;
	};
}
