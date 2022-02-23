#pragma once
#include <SFML/Graphics.hpp>
#include "../GameConfigure.h"
#include "Animation.h"
#include "../GameManager/ResourceManager.h"
using namespace sf;
class Menu
{
private:
	RectangleShape play, about, howToPlay,setting,deco1,deco2,deco3;
	Animation ani1, ani2, ani3;
	Sprite background;
public:
	Menu();
	void update(float deltaTime,State &state,RenderWindow & window);
	void draw(RenderWindow& window);
};