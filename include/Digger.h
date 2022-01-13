#pragma once
#include "moveable.h"

class Digger : public moveable
{
public:
	Digger() {}
	Digger(const sf::Texture& texture, const sf::Vector2f& pos, const float size)
		:moveable(texture, pos, (float)(size * 0.85), DIGGER, DIGGERLIVES) {}

	~Digger() {}

	// this function returns the direction that the user want to go to 
	// to make digger move after that  :
	sf::Vector2f get_next_step(sf::RenderWindow& window) override;
};
