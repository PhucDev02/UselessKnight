#include "GravityBlock.h"

GravityBlock::GravityBlock(Texture* texture, Vector2f position)
{
	Vector2f size = (Vector2f)texture->getSize();
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	isFall = 0;
	velocity = 0;
}

void GravityBlock::update(float deltaTime)
{
	if (isFall == 1)
	{
		velocity += 100.0f;
		body.move(0, velocity*deltaTime);
	}
}

void GravityBlock::draw(RenderWindow& window)
{
	if (body.getPosition().y < 900)
	{
		window.draw(body);
	}
}
