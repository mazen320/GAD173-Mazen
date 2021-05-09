#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Scene
{
private:
	bool isLoaded = false;
	bool isRunning = false;

public:
	Scene();
	~Scene();

	virtual void Init();
	virtual void Load();
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);

	inline bool IsLoaded() { return isLoaded; }
};
