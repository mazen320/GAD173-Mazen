#pragma once

#include "app.h"
#include "Grid.h"
#include "Map.h"
#include "SpriteAnimator.h"
#include "saveLoad.h"

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	sf::Sprite *m_backgroundSprite;

	Map map;
	Grid grid;




};
