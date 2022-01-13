#include "status.h"

status::status()
{
	// font:
	if (!m_fonts.loadFromFile(Font2))
		std::cout << "Cannot find FONT2" << std::endl;

	// icons:
	if (!m_textures[0].loadFromFile(CLOCK))
		std::cout << "Cannot find clock.png!" << std::endl;
	m_icons[0].setTexture(&m_textures[0]);
	m_icons[0].setPosition({ 0,840 });
	m_icons[0].setSize({ 60,60 });
	//===================
	if (!m_textures[1].loadFromFile(HEART))
		std::cout << "Cannot find heart.png!" << std::endl;
	m_icons[1].setTexture(&m_textures[1]);
	m_icons[1].setPosition({ 230,840 });
	m_icons[1].setSize({ 60,60 });
	//===================
	if (!m_textures[2].loadFromFile(SCORE))
		std::cout << "Cannot find bitcoin.png!" << std::endl;
	m_icons[2].setTexture(&m_textures[2]);
	m_icons[2].setPosition({ 480,840 });
	m_icons[2].setSize({ 60,60 });
	//===================
	if (!m_textures[3].loadFromFile(LEVEL))
		std::cout << "Cannot find clock.png!" << std::endl;
	m_icons[3].setTexture(&m_textures[3]);
	m_icons[3].setPosition({ 730,840 });
	m_icons[3].setSize({ 60,60 });
	//=================================
	// texts:
	The_situation[0].setPosition({ 15,800 });
	The_situation[0].setFont(m_fonts);
	The_situation[0].setFillColor(sf::Color::Black);
	The_situation[0].setCharacterSize(25);
	//===================
	The_situation[1].setPosition({ 250,800 });
	The_situation[1].setFont(m_fonts);
	The_situation[1].setFillColor(sf::Color::Black);
	The_situation[1].setCharacterSize(25);
	//===================
	The_situation[2].setPosition({ 500,800 });
	The_situation[2].setFont(m_fonts);
	The_situation[2].setFillColor(sf::Color::Black);
	The_situation[2].setCharacterSize(25);
	//===================
	The_situation[3].setPosition({ 750,800 });
	The_situation[3].setFont(m_fonts);
	The_situation[3].setFillColor(sf::Color::Black);
	The_situation[3].setCharacterSize(25);
}

void status::draw(sf::RenderWindow& window, sf::Clock& timer, int level_time, int life, int score, int lvl)
{
	sf::Time time = timer.getElapsedTime();
	std::string remaining_time =  std::to_string(59* level_time - (int)time.asSeconds() % 60);

	// fill the string by data:
	The_situation[0].setString(remaining_time);
	The_situation[1].setString(std::to_string(life));
	The_situation[2].setString(std::to_string(score));
	The_situation[3].setString(std::to_string(lvl));

	// drow data :
	for (size_t i = 0; i < 5; i++)
		window.draw(m_icons[i]);
	for (size_t i = 0; i < 5; i++)
		window.draw(The_situation[i]);
}
