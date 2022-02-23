#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "../GameConfigure.h"
#include "../GameManager/ResourceManager.h"
#include <iostream>
using namespace sf;
class VictoryState
{
private:
	RectangleShape restart, menu;
	Sprite background;
	Text text;
public:
	VictoryState();
	void update(float deltaTime, State& state, RenderWindow& window);
	void draw(RenderWindow& window);
	void setString(int s);
};