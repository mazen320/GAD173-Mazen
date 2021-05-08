#pragma once
#include <app.h>
#include <Scene.h>
#include "Map.h"
#include "Grid.h"

class Level1 : public Scene
{
public:
	Level1();
	~Level1();

	Grid grid;

	void Init() override;
	void Load() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
};

