#pragma once
#include "app.h"
#include "Grid.h"

class Map
{
public:
	Map();
	~Map();

	void mapLoad();
	void tileLoad();
	void guiLoad(sf::RenderWindow& window);
	void tileUpdate(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

	// This is the list of textures
	sf::Texture* tileTexture;
	sf::Texture* tileTexture2;
	sf::Texture* tileTexture3;
	sf::Texture* removeTexture;

	sf::Sprite tiles[TOTAL_CELLS_X * TOTAL_CELLS_Y];

	int selectedTile = 0;

	int map[TOTAL_CELLS_X * TOTAL_CELLS_Y] =
	{
		1, 2, 3, 1, 2, 3, 1, 2, 3,
		1, 2, 3, 1, 2, 3, 1, 2, 3,
		1, 2, 3, 1, 2, 3, 1, 2, 3,
		1, 2, 3, 1, 2, 3, 1, 2, 3,
		1, 2, 3, 1, 2, 3, 1, 2, 3,
		1, 2, 3, 1, 2, 3, 1, 2, 3,
		1, 2, 3, 1, 2, 3, 1, 2, 3,
		1, 2, 3, 1, 2, 3, 1, 2, 3,
		1, 2, 3, 1, 2, 3, 1, 2, 3,
		1, 2, 3, 1, 2, 3, 1, 2, 3
	};

};

