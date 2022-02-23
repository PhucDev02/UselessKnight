#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "../GameConfigure.h"
#include "../GameManager/ResourceManager.h"
//#include <windows.h>
using namespace sf;
class HowToPlayState
{
private:
	RectangleShape close;
	Sprite background;
	Text text;
public:
	HowToPlayState();
	void update(float deltaTime, State& state, RenderWindow& window);
	void draw(RenderWindow& window);
};
