#pragma once
#include "object.h"
#include "unmoveable.h"

class moveable : public object
{
public:
	moveable(){}
	moveable(const sf::Texture& texture,
             const sf::Vector2f     pos,
             const float           size,
             const OPJECTS_SYMBOLS      type, 
             const int             life)
		:object(texture, pos, size, type), m_life(life){}

	~moveable() {}
     //================================
    // Decreases object live 
    void Decrease_Life(){m_life--;}
    //================================
    // Update digger position for mov.. to make monster chase him
    void Update_Vec_To_Chase(const sf::Vector2f pos){vec2chase = pos;}
    //================================
	// Set movable objects texture 
   void setRectTexture(){m_object.setTextureRect(sf::IntRect(0, 0, 50, 50));}
   //================================
   // Move the moveables objects : polymorphism
   virtual void move(sf::RenderWindow& window, 
              const std::vector<std::unique_ptr<unmoveable>>& unmov);
   //================================
   // Chick if digger/monster is alive
   bool IsAlive() const {return m_life > 0;}
   //================================
   // return lives 
   int  Get_Life() const {return m_life;}
   //================================
   // speed of object movement
   static constexpr float SPEED = 7;
  
protected: 

    sf::Vector2f vec2chase; // Digger position
    int m_life;
	// chick if could go step 
	bool collides(const std::vector<std::unique_ptr<unmoveable>>& statics) const;
	// get coordinates of new step  : polymorphism
	virtual sf::Vector2f get_next_step(sf::RenderWindow& window) = 0; 
};
