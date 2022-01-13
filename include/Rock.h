#pragma once

#include "unmoveable.h"

class Rock : public unmoveable
{
public:
	Rock(const sf::Texture& texture, const sf::Vector2f pos, const float size)
		:unmoveable(texture, pos, size, ROCK) {}
	~Rock() {}
};

