#include "example.h"
#include "Grid.h"
#include "Map.h"
#include <iostream>

Example::Example(): App(), grid(), map()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	map.tileLoad();
	map.mapLoad();

	return true;
}

void Example::update(float deltaT)
{
	ImGui::Begin("Kage2D");

	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}
	map.guiLoad(m_window);
	ImGui::End();

	map.tileUpdate(m_window);
}


void Example::render()
{
	m_window.draw(*m_backgroundSprite);

	map.Render(m_window);

	grid.Draw(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}