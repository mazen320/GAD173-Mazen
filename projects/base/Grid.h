#pragma once
#include <SFML/Graphics.hpp>

//Amount of cells in each axis
#define TOTAL_CELLS_X 9
#define TOTAL_CELLS_Y 10

//Changing these will move the grid's position
#define GRID_OFFSET_X 0
#define GRID_OFFSET_Y 0

//Grid's size
#define GRID_SIZE_X 11
#define GRID_SIZE_Y 10

//Horizontal size
#define H_SIZE_X 506
#define H_SIZE_Y 2

//Vertical size
#define V_SIZE_X 2
#define V_SIZE_Y 560

//Cell size, so textures are 56x56
#define CELL_SIZE 56

class Grid
{
public: 
	Grid();
	~Grid();

	void Draw(sf::RenderWindow& window);
	sf::RectangleShape horizontal_lines[GRID_SIZE_X];
	sf::RectangleShape vertical_lines[GRID_SIZE_Y];
};

