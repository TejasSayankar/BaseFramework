#include <SFML/Graphics.hpp>
#include "Game/GameBase.h"
using namespace BaseFramework;

int main()
{
	
	GameBase game(1280, 720, "Game");
	game.run();
	return 0;
}