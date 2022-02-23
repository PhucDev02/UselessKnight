#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Player.h"
using namespace sf;
class CheckPoint
{
private:
	RectangleShape body;
	Animation animation;
	bool isChecked;
	Texture texture;
public:
	CheckPoint() {};
	CheckPoint(Texture* texture,Vector2f position);
	void draw(RenderWindow& window);
	void update(float deltaTime,Player& player);
	bool isCollide(Player player);
};