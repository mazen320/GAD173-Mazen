#include "SpriteAnimator.h"
#include <kage2dutil/texture_manager.h>
#include <iostream>

#define SPRITE_WIDTH 56
#define SPRITE_HEIGHT 56

SpriteAnimator::SpriteAnimator() :
	spriteSheetTexture(nullptr)
{
}

SpriteAnimator::~SpriteAnimator()
{
}

void SpriteAnimator::Init()
{
}

void SpriteAnimator::Load(std::string filename)
{
	indexX = 0;
	indexY = 0;

	int x = SPRITE_WIDTH * indexX;
	int y = SPRITE_HEIGHT * indexY;

	spriteSheetTexture = kage::TextureManager::getTexture(filename);
	spriteSheet.setTexture(*spriteSheetTexture);
	spriteSheet.setTextureRect(sf::IntRect(x, y, SPRITE_WIDTH, SPRITE_HEIGHT));
}

void SpriteAnimator::Update()
{
	sf::Time time = clock.getElapsedTime();

	if (time.asMilliseconds() > frameSpeed)
	{
		int x = SPRITE_WIDTH * currentFrame.x;
		int y = SPRITE_HEIGHT * currentFrame.y;

		spriteSheet.setTextureRect(sf::IntRect(x, y, SPRITE_WIDTH, SPRITE_HEIGHT));
		currentFrame.x++;

		if (currentFrame.x > endFrame.x)
		{
			currentFrame.x = 0;
		}
		clock.restart();
	}
}

void SpriteAnimator::Render(sf::RenderWindow& window)
{
	if (beginAnimation == true)
	{
		window.draw(spriteSheet);
	}
}

void SpriteAnimator::startAnimation(sf::Vector2i startFrame, sf::Vector2i endFrame, int frameSpeed)
{
	this->startFrame = startFrame;
	this->endFrame = endFrame;
	this->frameSpeed = frameSpeed;

	beginAnimation = true;
	currentFrame = startFrame;
}
