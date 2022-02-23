#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "../GameConfigure.h"
#include "../GameManager/ResourceManager.h"
using namespace sf;
class SettingState
{
private:
	RectangleShape loadBar, close,load,musicIcon;
	Sprite background, kewk;
	Text text, live;
public:
	SettingState();
	void update(float deltaTime, State& state, RenderWindow& window);
	void draw(RenderWindow& window);

};