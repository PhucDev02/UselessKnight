#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Collider
{
public:
	Collider(RectangleShape &body);
	~Collider();
	
	void move(float dx, float dy) {
		body.move(dx, dy);
	}

	bool checkCollision(Collider other,Vector2f& direction);
	bool checkCollisionHiddenBlock(Collider other);
	bool checkCollisionGravityBlock(Collider other);

	Vector2f getPosition() { return body.getPosition(); }
	Vector2f getHalfSize() 
	{
		return body.getSize() / 2.0f;
	}
private:
	RectangleShape& body;
};