#include"Platform.h"

Platform::Platform(sf::Texture* texture, Vector2f position)
{
	Vector2f size = (Vector2f)texture->getSize();
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}

void Platform::draw(RenderWindow& window)
{
	window.draw(body);
}
