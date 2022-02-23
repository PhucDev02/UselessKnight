#include "CensorBlock.h"

CensorBlock::CensorBlock(Texture* texture, Vector2f position)
{
	Vector2f size = (Vector2f)texture->getSize();
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	isFall = 0;
	velocity = 0;
}

void CensorBlock::update(float deltaTime,Player& player)
{
	if (player.getBody().getPosition().x >= body.getPosition().x - 5 && player.getBody().getPosition().x <= body.getPosition().x + 5)
	{
		isFall = 1;
	}
	if (player.getBody().getGlobalBounds().intersects(body.getGlobalBounds()))
	{
		player.setIsLive(0);
	}
	if (isFall == 1)
	{
		velocity += 30.0f;
		body.move(0, velocity * deltaTime);
	}
}

void CensorBlock::draw(RenderWindow& window)
{
		window.draw(body);
}
