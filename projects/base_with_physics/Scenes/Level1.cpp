#include "Level1.h"
#include <iostream>

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
}

void Level1::Update()
{
	std::cout << "ME LEVEL 1" << std::endl;
}

void Level1::Render(sf::RenderWindow& window)
{
	grid.Draw(window);
}
