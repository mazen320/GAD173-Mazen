#pragma once
#include <SFML/Graphics.hpp>

#define TOTALCELLS (TOTAL_CELLS_X * TOTAL_CELLS_Y)

//Amount of cells in each axis
#define TOTAL_CELLS_X 9
#define TOTAL_CELLS_Y 10

//Changing these will move the grid's position
#define GRID_OFFSET_X 300
#define GRID_OFFSET_Y 100

//Grid's size
#define GRID_SIZE_X 11
#define GRID_SIZE_Y 10

//Horizontal size
#define H_SIZE (CELL_SIZE * TOTAL_CELLS_X)

//Vertical size
#define V_SIZE (CELL_SIZE * TOTAL_CELLS_Y)

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

