#include "Grid.h"

Grid::Grid()
{
	for (size_t i = 0; i < GRID_SIZE_X; i++)
	{
		horizontal_lines[i].setSize(sf::Vector2f(H_SIZE, 2));
		horizontal_lines[i].setPosition(sf::Vector2f(GRID_OFFSET_X,
													 GRID_OFFSET_Y + i * CELL_SIZE));
	}
	for (size_t i = 0; i < GRID_SIZE_Y; i++)
	{
		vertical_lines[i].setSize(sf::Vector2f(2, V_SIZE));
		vertical_lines[i].setPosition(sf::Vector2f(GRID_OFFSET_X + i * CELL_SIZE,
													 GRID_OFFSET_Y));
	}
}

Grid::~Grid()
{
}

void Grid::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < GRID_SIZE_X; i++)
	{
		window.draw(horizontal_lines[i]);
	}
	for (size_t i = 0; i < GRID_SIZE_Y; i++)
	{
		window.draw(vertical_lines[i]);
	}
}