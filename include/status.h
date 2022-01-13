#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Settings.h"

class status
{
public:
	status();
	~status() {}

	// main function that recieves data and draw it on screen
	void draw(sf::RenderWindow& window, sf::Clock& timer, int level_time, int life, int score, int level);

private:
	sf::Clock m_timer;
	sf::Font m_fonts;
	sf::Text The_situation[5];
	sf::Texture m_textures[5];
	sf::RectangleShape m_icons[5];
};

