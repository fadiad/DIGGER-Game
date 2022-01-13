#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Settings.h"

class Controller
{
public:
	 Controller() {}
    ~Controller() {}
	//=============
	 void run();	// this is the function that runs all the game 

private:
	
	bool ON = true ;
	//=====================
	sf::RenderWindow window;
};