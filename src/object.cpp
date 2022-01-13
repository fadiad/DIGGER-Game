#include "object.h"
//=======================
object::object(const sf::Texture& texture,
			   const sf::Vector2f pos, 
			   const float size,
			   const	OPJECTS_SYMBOLS type)
  : m_scale(size),
	m_texture(texture), 
	m_type(type)
{
	m_object.setPosition(pos);
	m_object.setSize({ m_scale,m_scale });
	m_object.setTexture(&m_texture);
}
//=======================
void object::draw(sf::RenderWindow& window)
{
	window.draw(m_object);
}
