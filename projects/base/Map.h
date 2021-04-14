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

	sf::Texture* tileTexture;
	sf::Texture* tileTexture2;
	sf::Texture* tileTexture3;
	sf::Texture* removeTexture;

	sf::Sprite tiles[90];

	int selectedTile = 0;

	int map[90] =
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

