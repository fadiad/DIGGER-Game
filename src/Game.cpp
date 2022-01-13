#include"Game.h"

Game::Game()
	:GAMEOVER(false), m_level(1), m_totalScore(0)
					,DiggerLife(3), m_diamond_counter(0)
{
	srand((unsigned int)(time(NULL)));
	m_mapfile.open("Board.txt");
	if (!m_mapfile.is_open())
	{
		std::cerr << "Cannot open 'Borard.txt''\n";
		exit(EXIT_FAILURE);
	}
	loadTextures();
}
//========================
void Game::run(sf::RenderWindow& window)
{
	while (LOAD_MAP_FROM_FILE() && DiggerLife > 0)
	{
		CONVERT_TO_ANIMATIONS();
		while (!GAMEOVER)
		{
			window.clear(sf::Color(96, 140, 48)); 
			check_if_esc_pressed(window);
			Update_Digger_Status();
			GIVE_MONSTER_DIGGER_POSITION();
			MOVE_ALL_OPJECTS(window);
			EraseDiamond();
			Monsters_Collision();
			if (CHICK_LOSE(window))
				break;
			DiamondCollision();
			if (m_diamond_counter == 0)
			{
				LEVEL_FINISHED(window);
				break;
			}
			draw(window);
			window.display();
		}
	}
}
//========================
bool Game::LOAD_MAP_FROM_FILE()
{
	std::string line;

	if (!(std::getline(m_mapfile, line)))
		return false;

	m_map.clear();
	std::stringstream settings(line);
	settings >> m_size_row;
	settings >> m_size_col;
	m_size = m_size_row;
	settings >> m_maxTime;

	m_scale = (float)800/m_size;
	for (int i = 0; i < m_size; i++)
	{
		getline(m_mapfile, line);
		m_map.push_back(line);
	}
	return true;
}
//========================
void Game::CONVERT_TO_ANIMATIONS()
{
	clearAll();
	sf::Vector2f pos;
	for (size_t row = 0; row < m_map.size(); row++)
	{
		for (size_t col = 0; col < m_map.size(); col++)
		{
			pos = { col * m_scale,row * m_scale };
			if (m_map[row][col] == DIGGER)
			{
				m_start_digger_pos = pos;
				m_moveables.push_back(std::make_unique<Digger>(DIGGERTX, pos, m_scale));
			}
			else if (m_map[row][col] == MONSTER)
				m_moveables.push_back(std::make_unique<Monster>(MONSTERTX, pos, m_scale));
			else if (m_map[row][col] == DIAMOND)
			{
				m_diamond_counter = m_diamond_counter + 1;
				m_unmoveables.push_back(std::make_unique<Diamond>(DIAMONDTX, pos, m_scale));
			}
			else if (m_map[row][col] == ROCK)
				m_unmoveables.push_back(std::make_unique<Rock>(ROCKTX, pos, m_scale));
			else if (m_map[row][col] == WALL)
				m_unmoveables.push_back(std::make_unique<Wall>(WALLTX, pos, m_scale));
		}
	}
	m_timer.restart();
}
//========================
void Game::check_if_esc_pressed(sf::RenderWindow& window)
{
	sf::Event gameEvent; window.pollEvent(gameEvent);
	if (sf::Event::KeyReleased)
		if (gameEvent.key.code == sf::Keyboard::Escape)
			GAMEOVER = true;
}
//========================
void Game::Update_Digger_Status()
{
	for (const auto& movObj : m_moveables)
		if (movObj->GET_OPJ_TYPE() == DIGGER)
		{
			DiggerLife = movObj->Get_Life();
			DiggerPos = movObj->get_position();
			return;
		}
}
//========================
void Game::GIVE_MONSTER_DIGGER_POSITION()
{
	for (const auto& movObj : m_moveables)
		movObj->Update_Vec_To_Chase(DiggerPos);
}
//========================
void Game::MOVE_ALL_OPJECTS(sf::RenderWindow& window)
{
	for (const auto& movObj : m_moveables)
		movObj->move(window, m_unmoveables);
}
//========================
void Game::EraseDiamond()
{
	for (size_t i = 0; i < m_unmoveables.size(); i++)
		if (m_unmoveables[i]->GET_OPJ_TYPE() == DIAMOND)
			if (!m_unmoveables[i]->is_alive())
			{
				m_totalScore = m_totalScore + 15;
				m_unmoveables.erase(m_unmoveables.begin()+i);
			}
}
//========================
void Game::Monsters_Collision()
{
	for (const auto& digg : m_moveables)
		if (digg->GET_OPJ_TYPE() == DIGGER)
			for (const auto& mons : m_moveables)
				if (mons->GET_OPJ_TYPE() == MONSTER)
					if (digg->GET_GLO_POUNDS().intersects(mons->GET_GLO_POUNDS()))
					{
						digg->Decrease_Life();
						digg->set_position(m_start_digger_pos);
					}	
}
//========================
bool Game::CHICK_LOSE(sf::RenderWindow& window)
{
	if (DiggerLife < 1 || m_timer.getElapsedTime().asSeconds()>m_maxTime * 60)
	{
		GAMEOVER = true;
		window.clear(sf::Color::Black);
		window.draw(losespr);
		window.display();
		Sleep(1000);
		return true;
	}
	return false;
}
//========================
bool Game::DiamondCollision()
{
	for (const auto& movObj : m_moveables)
	{
		if (movObj->GET_OPJ_TYPE() == DIGGER)
			for (const auto& others : m_unmoveables)
			{
				if (others->GET_OPJ_TYPE() == DIAMOND)
					if (movObj->GET_GLO_POUNDS().intersects(others->GET_GLO_POUNDS()))
						if (eat.getElapsedTime().asSeconds() < 0.00000001)
							continue;
						else
						{
							others->decrease_life();
							m_diamond_counter = m_diamond_counter - 1;
							eat.restart();
						}
			}
			return false;	
	}
}
//========================
bool Game::LEVEL_FINISHED(sf::RenderWindow& window)
{
	m_totalScore = m_totalScore + 20;
	m_level++;
	window.clear(sf::Color::Black);
	window.draw(levelfsprite);
	window.display();	
	youWIN(window);
	Sleep(1000);
	return true;
}
//========================
void Game::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_moveables.size(); i++)
	{
		if (m_moveables[i]->GET_OPJ_TYPE() == DIGGER)
			m_moveables[i]->setRectTexture();// once its digger / other its monster
		m_moveables[i]->draw(window);
	}
	for (size_t j = 0; j < m_unmoveables.size(); j++)
		m_unmoveables[j]->draw(window);
	status1.draw(window, m_timer, m_maxTime, DiggerLife, m_totalScore, m_level);
}
//========================
void Game::loadTextures()
{
	DIGGERTX.loadFromFile(DIGGERIMAGE);
	DIAMONDTX.loadFromFile(DIAMONDIMAGE);
	ROCKTX.loadFromFile(ROCKIMAGE);
	MONSTERTX.loadFromFile(MONSTERIMAGE);
	WALLTX.loadFromFile(WALLIMAGE);	
	loseimage.loadFromFile(LOSE);
	losespr.setTexture(loseimage);
	winimage.loadFromFile(WIN);
	losespr.setPosition({300,300});
	winspr.setTexture(winimage);
	winspr.setPosition({ 160,300 });
	levelfinished.loadFromFile(LEVELFINISHED);
	levelfsprite.setTexture(levelfinished);
	levelfsprite.setPosition({220,300 });
}
//========================
void Game::clearAll()
{
	m_moveables.clear();
	m_unmoveables.clear();
}
//========================
void Game::youWIN(sf::RenderWindow& window)
{	
	if (m_level == 5) // finished all the levels 
	{
		window.clear(sf::Color::Black);
		window.draw(winspr);
		window.display();
		Sleep(1000);
		exit(EXIT_SUCCESS);
	}
}











