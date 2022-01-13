#pragma once

#include <SFML/Graphics.hpp>
#include <iostream> 
//====================
#include "moveable.h"
#include "Digger.h"
#include "Monster.h"
//====================
#include "unmoveable.h"
#include "Diamond.h"
#include "Wall.h"
#include "Rock.h"
//====================
#include"status.h"
#include "Settings.h"
//====================
#include <fstream>	
#include <vector>	
#include <string>	
#include <sstream>
#include <memory>	
#include <windows.h> 
#include <time.h>
#include <cstdlib>


class Game
{
public:
	Game();													// Constructor
	~Game() {}												// Distructor
	void run(sf::RenderWindow& window);						// the pasic function of the game 
	void draw(sf::RenderWindow& window);					// show all  
private:
	//========================
	// Objects :
	status status1;											// this opj used to drow the statuses
	Digger m_digger;										// the digger 
	Diamond m_diamond;										// the diamond 
	//========================								//========================
	void Update_Digger_Status();							// update digger life and pos
	void GIVE_MONSTER_DIGGER_POSITION();					// to let the monsters follow the digger
	void MOVE_ALL_OPJECTS(sf::RenderWindow& window);		// move digger and monsters 
	void CONVERT_TO_ANIMATIONS();							// convert the symbols to anemations 
	void clearAll();										// clear vecctors
	void loadTextures();									// load all the textures
	void Monsters_Collision();								// chick collision bettween digger and monster 
	void EraseDiamond();									// if digger has tuch the diamond erase the diamond 
	void check_if_esc_pressed(sf::RenderWindow& window);	// if the player pressed Esc end the game 
	void youWIN(sf::RenderWindow& window);					// last step 
	//========================								//========================
	// integers :
	int m_totalScore;										// the total score 								
	int m_size;												// map size 
	int m_size_row;											// map row size 
	int m_size_col;											// map columen size 
	int m_maxTime;											// level max time
	int m_level;											// level number
	int DiggerLife;											// digger lives 
	int m_diamond_counter;									// its counter that tells how many diamonds is in the map 	
	//========================								//========================
	// Textures :
	sf::Texture DIGGERTX;									// digger texture 
	sf::Texture MONSTERTX;									// monster texture 
	sf::Texture ROCKTX;										// rock texture 
	sf::Texture WALLTX;										// wall texture 
	sf::Texture DIAMONDTX;									// diamond texture 
	sf::Event event_taken;									// event taken
	sf::Clock m_timer;										// level timer
	sf::Clock eat;											// 0.5 seconds space of erase the diamond
	sf::Vector2f DiggerPos;									// diger position 
	sf::Sprite losespr;										// sprite of lose image
	sf::Texture loseimage;									// texture of lose imag
	sf::Sprite winspr;										// sprite of win image
	sf::Texture winimage;									// texture of win imag
	sf::Sprite levelfsprite;								// sprite of level image
	sf::Texture levelfinished;								// texture of level imag
	sf::Vector2f m_start_digger_pos;						// keep the start position fot the digger
	//========================								//========================
	// Bool :
	bool LEVEL_FINISHED(sf::RenderWindow& window);			// finish the level
	bool DiamondCollision();								// check digger has collision with the diamons 
	bool CHICK_LOSE(sf::RenderWindow& window);				// chick if the player has lost 
	bool LOAD_MAP_FROM_FILE();								// load map from file
	bool GAMEOVER;											// used to check if the game has finished 
	//========================								//========================
	// Std :
	std::vector<std::unique_ptr<moveable>> m_moveables;		// vector of moveable smart pointers (digger and monster)
	std::vector<std::unique_ptr<unmoveable>> m_unmoveables;	// vector of unmoveable smart pointers (diamond , wall and rock)
	std::vector<std::string> m_map;							// keep the map in m_map
	std::ifstream m_mapfile;									// this ifstream to take information from Board.txt
	//========================								//========================
	// floats :
	float m_scale;											// keep th size of the png pics
};