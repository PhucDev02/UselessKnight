#pragma once
#include "SFML/Graphics.hpp"
#include "../GameManager/ResourceManager.h"
#include "Player.h"
class Door
{
private:
	RectangleShape door;
public:
	Door(Vector2f position);
	Door() {};
	bool checkCollision(Player player);
	void draw(RenderWindow& window);
};