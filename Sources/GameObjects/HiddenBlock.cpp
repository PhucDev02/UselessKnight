#include "HiddenBlock.h"

HiddenBlock::HiddenBlock(Texture* texture,  Vector2f position)
{
	Vector2f size = (Vector2f)texture->getSize();
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	isHidden = 1;
}

void HiddenBlock::draw(RenderWindow& window)
{
	if(isHidden==0)
		window.draw(body);
}