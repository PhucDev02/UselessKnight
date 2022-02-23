#include "Bot.h"

Bot::Bot(Texture* texture, Vector2f position)
	:animation(texture, Vector2u(8, 1),0.1f )
{
	body.setPosition(position);
	origin = position;
	body.setOrigin(animation.uvRect.width / 2, animation.uvRect.height / 2);
	body.setSize(Vector2f(texture->getSize().x / 8, texture->getSize().y / 1));
	body.setTexture(texture);
	velocity.x = -100;
	velocity.y = 0;
	faceRight = 0;
	range = 100;
}

void Bot::update(float deltaTime, Player& player)
{
	if (player.getBody().getGlobalBounds().intersects(body.getGlobalBounds()))
	{
		player.setIsLive(0);
	}
	if (abs(origin.x - body.getPosition().x)>range)
	{
		velocity.x *= -1;
	}
	if (velocity.x < 0) faceRight = 0;
	else faceRight = 1;
	//velocity.y += 981.0f * deltaTime;
	animation.update(0, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Bot::draw(RenderWindow& window, Player player)
{
	if (abs(body.getPosition().x - player.getPosition().x)-200<screenWidth)
	{
		window.draw(body);
	}
}

void Bot::OnCollision(Vector2f direction)
{
	if (direction.x != 0.0f)
	{
		velocity.x *= (-1);
	}
	if (direction.y < 0.0f)
	{
		// standing on block
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
	}
}

Collider Bot::getCollider()
{
	return Collider(body);
}
