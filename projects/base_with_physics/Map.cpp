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


	for (int i = 0; i < TOTALCELLS; i++) {
		tilesAnimator[i].Init();
		tilesAnimator[i].Load("data/spritesheet.png");
	}
	
}

void Map::mapLoad()
{
	for (size_t y = 0; y < TOTAL_CELLS_Y; y++)
	{
		for (size_t x = 0; x < TOTAL_CELLS_X; x++)
		{
			int i = x + y * TOTAL_CELLS_X;
			if (map[i] == 0)
			{
				tiles[i].setTexture(*removeTexture);
				tilesAnimator[i].beginAnimation = false;
			}

			if (map[i] == 1)
			{
				tiles[i].setTexture(*tileTexture);
				tilesAnimator[i].startAnimation(sf::Vector2i(0, 0), sf::Vector2i(9, 9), 100);

			}

			if (map[i] == 2)
			{
				tiles[i].setTexture(*tileTexture2);
			}

			if (map[i] == 3)
			{
				tiles[i].setTexture(*tileTexture3);
			}

			tilesAnimator[i].spriteSheet.setPosition(sf::Vector2f(GRID_OFFSET_X + x * CELL_SIZE, GRID_OFFSET_Y + y * CELL_SIZE));
			tiles[i].setPosition(sf::Vector2f(GRID_OFFSET_X + x * CELL_SIZE, GRID_OFFSET_Y + y * CELL_SIZE));
			
		}
	}
}


void Map::guiLoad(sf::RenderWindow& window)
{
	ImGui::Begin("Select A Tile");

	if (ImGui::Button("Remove Object"))
	{
		selectedTile = 0;
	}

	if (ImGui::ImageButton(*tileTexture, sf::Vector2f(CELL_SIZE, CELL_SIZE)))
	{
		selectedTile = 1;
	}

	if (ImGui::ImageButton(*tileTexture2, sf::Vector2f(CELL_SIZE, CELL_SIZE)))
	{
		selectedTile = 2;
	}

	if (ImGui::ImageButton(*tileTexture3, sf::Vector2f(CELL_SIZE, CELL_SIZE)))
	{
		selectedTile = 3;
	}
	ImGui::End();
}


void Map::tileUpdate(sf::RenderWindow& m_window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
		mousePosition.x >= GRID_OFFSET_X && mousePosition.x <= GRID_OFFSET_X + H_SIZE &&
		mousePosition.y >= GRID_OFFSET_Y && mousePosition.y <= GRID_OFFSET_Y + V_SIZE)
	{
		int mouseonCellX = (mousePosition.x - GRID_OFFSET_X) / CELL_SIZE;
		int mouseonCellY = (mousePosition.y - GRID_OFFSET_Y) / CELL_SIZE;

		int i = mouseonCellX + mouseonCellY * TOTAL_CELLS_X;

		std::cout << "INDEX: " << i << std::endl;
		std::cout << "MOUSE POS: " << mousePosition.x << " " << mousePosition.y << " "
			<< mouseonCellX << " " << mouseonCellY << std::endl;

		if (selectedTile == 0)
		{
			tiles[i].setTexture(*removeTexture);
			map[i] = 0;
			tilesAnimator[i].beginAnimation = false;
		}
		if (selectedTile == 1)
		{
			tiles[i].setTexture(*tileTexture);
			tilesAnimator[i].startAnimation(sf::Vector2i(0, 0), sf::Vector2i(9, 9), 100);
			map[i] = 1;
		}

		if (selectedTile == 2)
		{
			tiles[i].setTexture(*tileTexture2);
			map[i] = 2;
		}
		if (selectedTile == 3)
		{
			tiles[i].setTexture(*tileTexture3);
			map[i] = 3;
		}
	}

	for (size_t i = 0; i < TOTALCELLS; i++)
	{
		tilesAnimator[i].Update();
	}
}


void Map::Render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < TOTALCELLS; i++)
	{
		window.draw(tiles[i]);
		
		tilesAnimator[i].Render(window);
	}
}