#pragma once

#include "moveable.h"
//===================
#include <cstdlib>
#include <time.h>

class Monster : public moveable
{
public:
	Monster(const sf::Texture& texture, const sf::Vector2f pos, const float size)
		:moveable(texture, pos, (float)(size * 0.85),MONSTER, MONSTERLIVES){} 
	~Monster(){}

	sf::Vector2f get_next_step(sf::RenderWindow& window) override;
private:
	int m_life;
	sf::Vector2f lastMove;	// vector of the last  move
	sf::Clock sameMove ;    // timer  of move  duration
};