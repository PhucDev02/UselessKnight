#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
using namespace sf;
class Platform
{
public:
	Platform(sf:: Texture* texture,Vector2f position);
	Platform() {};
	void draw(RenderWindow& window);
	Collider getCollider() { return Collider(body); }
private:
	RectangleShape body;
};