#include "example.h"
#include "Scenes/Level1.h"
#include "Scenes/MainMenu.h"

Example::Example(): App()
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

	sceneManager.addScene(new MainMenu());
	sceneManager.addScene(new Level1());	

	sceneManager.Load();

	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Scene Loader");

	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	if (ImGui::Button("Main Menu"))
	{
		sceneManager.LoadScene(0);
	}
	if (ImGui::Button("Level 1"))
	{
		sceneManager.LoadScene(1);
		ImGui::EndMenu;
	}

	ImGui::End();

	sceneManager.Update();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);

	sceneManager.Render(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

