#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(int sceneID)
{
	currentSceneID = sceneID;
}

void SceneManager::addScene(Scene* scene)
{
	scenes.push_back(scene);
}

void SceneManager::RemoveScene(int sceneID)
{
}

void SceneManager::Load()
{
}

void SceneManager::Update()
{
	
	scenes[currentSceneID]->Update();
}

void SceneManager::Render(sf::RenderWindow& window)
{
	scenes[currentSceneID]->Render(window);
}
