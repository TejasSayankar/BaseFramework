#pragma once

#include<memory>
#include<string>
#include<stack>
#include<SFML/Graphics.hpp>

#include "../Input/Keyboard.h"
#include "../Input/Mouse.h"
#include "../States/StateBase.h"

namespace BaseFramework
{
	class Game
	{
	public: 
		Game(int width, int height, std::string title);

		void run();

		void pushState(std::unique_ptr<StateBase> state);
		void popState();
		void exitGame();

		Keyboard& getKeyboard();
		Mouse& getMouse();

		const sf::RenderWindow& getWindow() const;

	private:
		void handleEvent();
		void tryPop();

		StateBase& getCurrentState();

		sf::RenderWindow _window;
		std::stack<std::unique_ptr<StateBase>> _states;
		bool _shouldPop = false;

		std::unique_ptr<Keyboard> _keyboard;
		std::unique_ptr<Mouse> _mouse;
	};
}