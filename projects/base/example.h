#pragma once

#include "app.h"
#include "Grid.h"

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;

	sf::Texture *tileTexture;
	sf::Texture *tileTexture2;
	sf::Texture* removeTexture;

	sf::Sprite tiles[20];

	int selectedTile = 0;

	int map[20] = {
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	};

	Grid grid;
};
