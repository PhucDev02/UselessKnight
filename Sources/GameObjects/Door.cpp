#include"Door.h"

Door::Door(Vector2f position)
{
	door.setTexture(DATA->getTexture("DoorOpen"));
	door.setPosition(position);
	door.setSize(Vector2f(78,96));
}

bool Door::checkCollision(Player player)
{
	if (player.getBody().getGlobalBounds().intersects(door.getGlobalBounds()))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Door::draw(RenderWindow& window)
{
	window.draw(door);
}
