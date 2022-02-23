#pragma once
#include"SFML/Graphics.hpp"
#include "../GameConfigure.h"
#include "../GameManager/ResourceManager.h"
#include "Animation.h"
#include "Collider.h"
#include <math.h>
using namespace std;
using namespace sf;

class Player 
{
private:
	RectangleShape body;
	Animation animation;
	unsigned int row;
	Vector2f velocity,lastCheckPoint;
	View playerView;
	float speed,jumpHeight;
	bool canJump,faceRight,isLive;
public:

public:
	Player(Texture* texture, Vector2u imageCount, float switchTime,float speed);
	Player();
	void update(float deltaTime);
	void draw(RenderWindow& window);
	void OnCollision(Vector2f direction);
	void respawn();
	Vector2f getPosition() { return body.getPosition(); }
	Vector2f getVelocity() { return velocity; }
	bool getIsLive() { return isLive; }
	void setIsLive(bool isLive) { this->isLive = isLive; }
	RectangleShape getBody() { return body; }
	Collider getCollider();
	void setPosition(float x, float y) { body.setPosition(x, y); }
	void setVelocity(float x, float y) { velocity.x = x; velocity.y = y; }
	void setLastCheckPoint(Vector2f position);
};