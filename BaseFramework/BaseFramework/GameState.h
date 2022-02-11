#pragma once
#include "States/StateBase.h"
namespace BaseFramework
{
	class GameState :
		public StateBase
	{
	public:
		GameState(Game& game);
		virtual void handleEvent(sf::Event e) override;
		virtual void handleInput() override;
		virtual void update(float deltaTime) override;
		virtual void render(sf::RenderTarget& renderTarget) override;
	};
}
