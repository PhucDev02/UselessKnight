#pragma once
#pragma once
#include"SFML/Graphics.hpp"
#include "../GameConfigure.h"
#include "../GameManager/ResourceManager.h"
#include "Animation.h"
#include "Collider.h"
#include "Player.h"
#include <math.h>
using namespace sf;
class Bot
{
private:
	RectangleShape body;
	Animation animation;
	Vector2f velocity;
	Vector2f origin;
	bool faceRight;
	float range;
public:

public:
	Bot(Texture* texture,Vector2f position);
	Bot() {};
	void update(float deltaTime, Player &player);
	void draw(RenderWindow& window,Player player);
	void OnCollision(Vector2f direction);
	RectangleShape getBody() { return body; }
	Collider getCollider();
};