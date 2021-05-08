#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class SpriteAnimator
{
private:
	sf::Texture* spriteSheetTexture;

	sf::Clock clock;

	int indexX = 0;
	int indexY = 0;

	sf::Vector2i startFrame;
	sf::Vector2i currentFrame;
	sf::Vector2i endFrame;

	int frameSpeed;

public:
	sf::Sprite spriteSheet;

	bool beginAnimation = false;

	SpriteAnimator();
	~SpriteAnimator();

	void Init();
	void Load(std::string filename);
	void Update();
	void Render(sf::RenderWindow& window);

	void startAnimation(sf::Vector2i startFrame, sf::Vector2i endFrame, int frameSpeed);


};

