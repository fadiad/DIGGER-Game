#pragma once

#include "unmoveable.h"

class Diamond : public unmoveable
{
public:
	Diamond() {}
	Diamond(const sf::Texture& texture, const sf::Vector2f pos, const float size)
		:unmoveable(texture, pos, size, DIAMOND) {}
	~Diamond() {}
};



