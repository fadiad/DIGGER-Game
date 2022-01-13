#pragma once
#include "unmoveable.h"

class Wall : public unmoveable
{
public:
	Wall(const sf::Texture& texture, const sf::Vector2f pos, const float size)
		:unmoveable(texture, pos, size, WALL) {
		m_object.setFillColor(sf::Color::Yellow);
	}
	~Wall() {}
};

