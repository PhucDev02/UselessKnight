#include"Collider.h"
#include <iostream>
Collider::Collider(RectangleShape& body)
	:body(body)
{
}
Collider::~Collider()
{

}
bool Collider::checkCollision(Collider other, Vector2f& direction)
{
	Vector2f otherPosition = other.getPosition();
	Vector2f otherHalfSize = other.getHalfSize();
	Vector2f thisPosition = getPosition();
	Vector2f thisHalfSize = getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		if ((intersectX) > (intersectY)) // response at right or left
		{
			if (deltaX > 0.0f) //other at right
			{
				other.move(-intersectX, 0.0f);
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else
			{
				other.move(intersectX, 0.0f);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)//hidden=0
			{
				other.move(0.0f, -intersectY);
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else
			{
				other.move(0.0f, intersectY);
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		return true;
	}
	return false;

}

bool Collider::checkCollisionHiddenBlock(Collider other)
{
	Vector2f otherPosition = other.getPosition();
	Vector2f otherHalfSize = other.getHalfSize();
	Vector2f thisPosition = getPosition();
	Vector2f thisHalfSize = getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		if ((intersectX) > (intersectY)) // response at right or left
		{
			if (deltaX > 0.0f) //other at right
			{
			}
			else
			{
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
			}
			else
			{
				other.move(0.0f, -intersectY);
				return true;
			}
			return false;
		}
	}
}

bool Collider::checkCollisionGravityBlock(Collider other)
{
	Vector2f otherPosition = other.getPosition();
	Vector2f otherHalfSize = other.getHalfSize();
	Vector2f thisPosition = getPosition();
	Vector2f thisHalfSize = getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		return 1;
	}
	else return 0;
}
