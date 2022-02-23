#include "CheckPoint.h"

CheckPoint::CheckPoint(Texture* texture,Vector2f position)
	: animation(texture, Vector2u(7,1) ,0.2f)
{
	isChecked = 0;
	body.setPosition(position);
	body.setOrigin(animation.uvRect.width / 2, animation.uvRect.height / 2);
	body.setSize(Vector2f(texture->getSize().x / 7, texture->getSize().y / 1));
	body.setTexture(texture);
}

void CheckPoint::draw(RenderWindow& window)
{
	window.draw(body);
}

void CheckPoint::update(float deltaTime,Player &player)
{
	if (isCollide(player) == 1)
	{
		player.setLastCheckPoint(body.getPosition());
		isChecked = 1;
	}
	if (isChecked == 0)
	{
		body.setTextureRect(IntRect(0.0, 0.0, 48, 48));
	}
	else
	{
		animation.update(0,deltaTime,1);
		body.setTextureRect(animation.uvRect);
	}
}

bool CheckPoint::isCollide(Player player)
{
	if (body.getGlobalBounds().intersects(player.getBody().getGlobalBounds()))
	{
		return true;
	}
	return false;
}
