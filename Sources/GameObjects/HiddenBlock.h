#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
using namespace sf;
class HiddenBlock
{
public:
	HiddenBlock(sf::Texture* texture, Vector2f position);
	
	void draw(RenderWindow& window);
	
	Collider getCollider() { return Collider(body); }
	bool getHidden() { return isHidden; }
	void setHidden(bool hidden) { isHidden = hidden; }
private:
	RectangleShape body;
	bool isHidden ;
};