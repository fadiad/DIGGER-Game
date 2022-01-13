#include "Monster.h"

sf::Vector2f Monster::get_next_step(sf::RenderWindow& window)
{
	if (sameMove.getElapsedTime().asSeconds() > 0.6)
	{
		if ((rand()% 2) == 0)
		{
			if (vec2chase.y > get_position().y)
			{
				lastMove = { 0,SPEED };
				sameMove.restart();
			}
			else
				if (vec2chase.y < get_position().y)
				{
					lastMove = { 0,-SPEED };
					sameMove.restart();
				}
		}
		else
		{
			if (vec2chase.x > get_position().x)
			{
				lastMove = { SPEED,0 };
				sameMove.restart();
			}
			else
				if (vec2chase.x < get_position().x)
				{
					lastMove = { -SPEED,0 };
					sameMove.restart();
				}
		}

	}
	return lastMove;
}