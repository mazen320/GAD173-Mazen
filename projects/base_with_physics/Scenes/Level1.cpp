#include "Level1.h"
#include "SceneManager.h"
#include <iostream>
#include "saveLoad.h"

Level1::Level1()
{
}

Level1::~Level1()
{
}

void Level1::Init()
{
}

void Level1::Load()
{
	saveLoad::Load("data/Saves/Map.txt", map.map);
	map.tileLoad();
	map.mapLoad();
}

void Level1::Update()
{
	std::cout << "ME LEVEL 1" << std::endl;
}

void Level1::Render(sf::RenderWindow& window)
{
	map.Render(window);
	grid.Draw(window);
	map.tileUpdate(window);
}
