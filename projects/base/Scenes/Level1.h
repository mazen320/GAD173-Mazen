#pragma once
#include <app.h>
#include <Scene.h>

class Level1 : public Scene
{
public:
	Level1();
	~Level1();

	void Init() override;
	void Load() override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
};

