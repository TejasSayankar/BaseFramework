#pragma once
#include<SFML/Graphics.hpp>

namespace BaseFramework
{
	class Game;

	class StateBase
	{
	public:

		//delete copy constructor and copy assignment

		StateBase(Game& game) : _game(&game) {}
		StateBase(const StateBase&) = delete;
		StateBase& operator = (const StateBase&) = delete;
		virtual ~StateBase() = default;

		virtual void handleEvent(sf::Event e) = 0;
		virtual void handleInput() = 0;
		virtual void update(float deltaTime) = 0;
		//virtual void fixedUpdate(float deltaTime) = 0; ////check it if not necessary remove it
		virtual void render(sf::RenderTarget& renderTarget) = 0;
	protected:
		Game* _game;
	};
}
