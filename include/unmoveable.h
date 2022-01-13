#pragma once
#include "object.h"

class unmoveable : public object
{
public:
	unmoveable() {}
	unmoveable(const sf::Texture& texture,
			  const sf::Vector2f pos,
			  const float size,
			  const OPJECTS_SYMBOLS type)
			 :object(texture, pos, size, type)
	{
		m_life = 1;
	}

	~unmoveable(){};
	//============================
	void decrease_life(){m_life--;}
	bool is_alive() const {return m_life > 0;}
	int m_life ;
};

