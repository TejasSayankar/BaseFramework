#include "Game.h"
#include "../GameState.h"

namespace BaseFramework
{
	Game::Game(int width, int height, std::string title)
	{
		_window.create(sf::VideoMode(width, height), title);
		_keyboard = std::make_unique<Keyboard>();
		_mouse = std::make_unique<Mouse>();

		// Start game state
		pushState(std::make_unique<GameState>(*this));
	}

	void Game::run()
	{
		sf::Clock timer;
		float newTime, deltaTime;
		float currentTime = timer.getElapsedTime().asSeconds();
		while (_window.isOpen() && !_states.empty())
		{
			newTime = timer.getElapsedTime().asSeconds();
			deltaTime = newTime - currentTime;

			if (deltaTime > 0.25f)
			{
				deltaTime = 0.25f;
			}

			currentTime = newTime;

			StateBase& state = getCurrentState();
			state.handleInput();
			state.update(deltaTime);

			
			_window.clear();
			state.render(_window);
			_window.display();

			handleEvent();
			tryPop();
		}
	}

	void Game::pushState(std::unique_ptr<StateBase> state)
	{
		_states.push(std::move(state));
	}

	void Game::popState()
	{
		_shouldPop = true;
	}

	void Game::exitGame()
	{

	}

	Keyboard& Game::getKeyboard()
	{
		return *_keyboard;
	}

	Mouse& Game::getMouse()
	{
		return *_mouse;
	}

	const sf::RenderWindow& Game::getWindow() const
	{
		return _window;
	}

	void Game::handleEvent()
	{
		sf::Event e;

		while (_window.pollEvent(e))
		{
			getCurrentState().handleEvent(e);
			switch (e.type)
			{
			case sf::Event::Closed:
				_window.close();
				break;

			default:
				break;
			}
		}
	}

	void Game::tryPop()
	{
		if (_shouldPop)
		{
			_states.pop();
		}
	}

	StateBase& Game::getCurrentState()
	{
		return *_states.top();
	}
}