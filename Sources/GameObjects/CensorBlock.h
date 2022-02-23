#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
#include "Player.h"
using namespace sf;
class CensorBlock
{
public:
	CensorBlock(Texture* texture, Vector2f position);

	void update(float deltaTime,Player& player);
	void draw(RenderWindow& window);

	Collider getCollider() { return Collider(body); }
private:
	float velocity;
	RectangleShape body;
	bool isFall;
};