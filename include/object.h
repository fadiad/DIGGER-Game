#pragma once
#include "Settings.h"
#include <SFML/Graphics.hpp>

class object
{
public:
	object(){}
	object(const sf::Texture& texture,
		   const sf::Vector2f     pos,
		   const float           size, 
		   const OPJECTS_SYMBOLS     type);

	~object() = default;
	//================================
	// drow objects 
	void draw(sf::RenderWindow& window);
	//================================
	// set object textures
	void set_texture(const sf::Texture& texture){m_object.setTexture(&texture);}
	//================================
	// set position of object on the sf map
	void set_position(const sf::Vector2f& pos){m_object.setPosition(pos);}
	// return the position of the object on the sf map
	sf::Vector2f get_position() const {return m_object.getPosition();}
	//===============================
	sf::FloatRect GET_GLO_POUNDS(){return m_object.getGlobalBounds();}
	//================================
	// returns object's type
	OPJECTS_SYMBOLS GET_OPJ_TYPE(){return m_type;}
	//================================
	// set object size
	void SetScale(const float scale) {m_object.setSize({ scale,scale });}

protected:
	sf::Texture m_texture;
	sf::RectangleShape m_object;
	float m_scale;
	OPJECTS_SYMBOLS m_type;
	
};