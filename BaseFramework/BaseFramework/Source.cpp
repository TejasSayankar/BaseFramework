#include <SFML/Graphics.hpp>
#include "Game/GameBase.h"
using namespace BaseFramework;

int main()
{
	/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Is Set Up!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;*/
	GameBase game(1280, 720, "Game");
	game.run();
	return 0;
}