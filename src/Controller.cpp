#include "Controller.h"

void Controller::run()
{
	sf::RenderWindow window(sf::VideoMode(800,920), "T H E   D I G G E R");
	window.setFramerateLimit(35);
	window.setMouseCursorVisible(false);

	while (window.isOpen())
	{
		if (ON)
		{
			Game game;
			game.run(window);
			ON = false;
		}
		else
			exit(EXIT_SUCCESS);
	}
}
