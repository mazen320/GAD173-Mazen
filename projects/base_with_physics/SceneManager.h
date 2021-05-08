#pragma once
#include <Scene.h>
#include <vector>
#include <iostream>
#include <app.h>

class SceneManager
{
private:
	int currentSceneID;
	std::vector<Scene*> scenes;

public:
	SceneManager();
	~SceneManager();

	void LoadScene(int sceneID);
	void addScene(Scene* scene);
	void RemoveScene(int sceneID);

	void Load();
	void Update();
	void Render(sf::RenderWindow& window);

	inline const int& GetActiveScene() { return currentSceneID; }
};

