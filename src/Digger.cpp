#include "Digger.h"

sf::Vector2f Digger::get_next_step(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		return { -SPEED, 0 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		return { SPEED, 0 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		return { 0, -SPEED };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		return { 0, SPEED };
	}
	return { 0,0 };
}
