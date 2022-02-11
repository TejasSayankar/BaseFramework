#include "GameBase.h"

namespace BaseFramework
{
	GameBase::GameBase(int width, int height, std::string title)
	{
		_window.create(sf::VideoMode(width, height), title);
		_keyboard = std::make_unique<Keyboard>();
		_mouse = std::make_unique<Mouse>();
	}

	void GameBase::run()
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

	void GameBase::pushState(std::unique_ptr<StateBase> state)
	{
		_states.push(std::move(state));
	}

	void GameBase::popState()
	{
		_shouldPop = true;
	}

	void GameBase::exitGame()
	{
	}

	Keyboard& GameBase::getKeyboard()
	{
		return *_keyboard;
	}

	Mouse& GameBase::getMouse()
	{
		return *_mouse;
	}

	const sf::RenderWindow& GameBase::getWindow() const
	{
		return _window;
	}

	void GameBase::handleEvent()
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

	void GameBase::tryPop()
	{
		if (_shouldPop)
		{
			_states.pop();
		}
	}

	StateBase& GameBase::getCurrentState()
	{
		return *_states.top();
	}
}