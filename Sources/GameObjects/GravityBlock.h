#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
using namespace sf;
class GravityBlock
{
public:
	GravityBlock(Texture* texture, Vector2f position);
	
	void update(float deltaTime);
	void draw(RenderWindow& window);
	
	Collider getCollider() { return Collider(body); }
	bool getFall() { return isFall; }
	void setFall(bool fall) { isFall = fall; }
private:
	float velocity;
	RectangleShape body;
	bool isFall ;
};