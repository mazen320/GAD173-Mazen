#include "example.h"
#include "Grid.h"
#include "Map.h"
#include <iostream>


Map::Map()
{
}


Map::~Map()
{
}


void Map::tileLoad()
{
	removeTexture = kage::TextureManager::getTexture("data/delete.png");
	tileTexture = kage::TextureManager::getTexture("data/grass2.jpg");
	tileTexture2 = kage::TextureManager::getTexture("data/grass1.jpg");
	tileTexture3 = kage::TextureManager::getTexture("data/test.jpg");
}


void Map::mapLoad()
{
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
}


void Map::guiLoad(sf::RenderWindow& window)
{

	ImGui::Begin("Kage2D");

	if (ImGui::Button("Exit"))
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
}


void Map::tileUpdate(sf::RenderWindow& window)
{
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


void Map::Render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 90; i++)
	{
		window.draw(tiles[i]);
	}
}