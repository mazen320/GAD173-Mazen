#pragma once
#include <SFML/Graphics.hpp>


#define GRID_OFFSET_X 0
#define GRID_OFFSET_Y 0

#define GRID_SIZE_X 11
#define GRID_SIZE_Y 10

#define H_SIZE_X 506
#define H_SIZE_Y 2

#define V_SIZE_X 2
#define V_SIZE_Y 560

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

