#pragma once
#include "app.h"
#include "Grid.h"
#include "SpriteAnimator.h"

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

	sf::Sprite tiles[TOTALCELLS];
	SpriteAnimator tilesAnimator[TOTALCELLS];

	int selectedTile = 0;

	int map[TOTALCELLS] =
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

