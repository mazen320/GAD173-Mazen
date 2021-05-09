#pragma once
#include <app.h>
#include <Scene.h>
#include "Map.h"
#include "Grid.h"

class MainMenu : public Scene
{
public:
	MainMenu();
	~MainMenu();


	void Init() override;
	void Load() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
};

