#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "../GameConfigure.h"
#include "../GameManager/ResourceManager.h"
using namespace sf;
class GameOverState
{
private:
	RectangleShape restart, menu;
	Sprite background,kewk;
	Text text,live;
public:
	GameOverState();
	void update(float deltaTime, State& state,RenderWindow & window);
	void draw(RenderWindow& window);
	int lives;
};