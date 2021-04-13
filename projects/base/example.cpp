#include "example.h"
#include "Grid.h"
#include <iostream>

Example::Example(): App(), grid() 
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	tileTexture = kage::TextureManager::getTexture("data/grass2.jpg");
	tileTexture2 = kage::TextureManager::getTexture("data/grass1.jpg");
	tileTexture3 = kage::TextureManager::getTexture("data/test.jpg");


	removeTexture = kage::TextureManager::getTexture("data/delete.png");


	for (size_t y = 0; y < 10; y++)
	{
		for (size_t x = 0; x < 9; x++)
		{
			int i = x + y * 9;

			if (map[i] == 0)
			{
				tiles[i].setTexture(*removeTexture);
			}
			if (map[i] == 1)
			{
				tiles[i].setTexture(*tileTexture);
			}
			if (map[i] == 2)
			{
				tiles[i].setTexture(*tileTexture2);
			}
			if (map[i] == 3)
			{
				tiles[i].setTexture(*tileTexture3);
			}
			tiles[i].setPosition(sf::Vector2f(GRID_OFFSET_X + x * CELL_SIZE,
											  GRID_OFFSET_Y + y * CELL_SIZE));
		}
	}

	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	if (ImGui::Button("Remove Object"))
	{
		selectedTile = 0;
	}
	if (ImGui::ImageButton(*tileTexture, sf::Vector2f(20, 20)))
	{
		selectedTile = 1;
	}
	if (ImGui::ImageButton(*tileTexture2, sf::Vector2f(20, 20)))
	{
		selectedTile = 2;
	}
	if (ImGui::ImageButton(*tileTexture3, sf::Vector2f(20, 20)))
	{
		selectedTile = 3;
	}

	ImGui::End();


	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
		mousePosition.x >= 0 && mousePosition.x <= 504 &&
		mousePosition.y >= 0 && mousePosition.y <= 5600)
	{
		int mouseonCellX = mousePosition.x / CELL_SIZE;
		int mouseonCellY = mousePosition.y / CELL_SIZE;

		int i = mouseonCellX + mouseonCellY * 9;

		//std::cout << i << std::endl; 

		std::cout << mousePosition.x << " " << mousePosition.y
			<< mouseonCellX << " " << mouseonCellY << std::endl;

		if (selectedTile == 0)
		{
			tiles[i].setTexture(*removeTexture);
			map[i] = 1;
		}
		if (selectedTile == 1)
		{
			tiles[i].setTexture(*tileTexture);
			map[i] = 1;
		}

		if (selectedTile == 2)
		{
			tiles[i].setTexture(*tileTexture2);
			map[i] = 1;
		}
		if (selectedTile == 3)
		{
			tiles[i].setTexture(*tileTexture3);
			map[i] = 1;
		}
	}
}


void Example::render()
{
	m_window.draw(*m_backgroundSprite);

	for (size_t i = 0; i < 90; i++)
		m_window.draw(tiles[i]);

	grid.Draw(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

