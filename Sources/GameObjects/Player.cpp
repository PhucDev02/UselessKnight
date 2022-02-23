#include "Player.h"
Player::Player(){}
Player::Player(Texture* texture, Vector2u imageCount, float switchTime,float speed) 
:animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	jumpHeight = 195;
	row = 0; //idle
	faceRight = 1;
	canJump = 1;
	isLive = 1;
	//set View
	playerView = View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight));
	//setBody
	body.setPosition(200, 100);
	body.setOrigin(animation.uvRect.width/2,animation.uvRect.height/2);
	body.setSize(Vector2f(texture->getSize().x/4,texture->getSize().y/5));
	body.setTexture(texture);
	lastCheckPoint = body.getPosition();
}
void Player::update(float deltaTime)
{
	velocity.x = 0.0f;
	if (sf::Keyboard::isKeyPressed(Keyboard::A)|| Keyboard::isKeyPressed(Keyboard::Left))
	{
		velocity.x -= speed ;
	}
	if (sf::Keyboard::isKeyPressed(Keyboard::D)||Keyboard::isKeyPressed(Keyboard::Right))
	{
		velocity.x += speed;
	}
	//set Animation if run
	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (velocity.x > 0.0f)
		{
			faceRight = 1;
		}
		else faceRight = 0;
	}
	//jump

	if (canJump==1 && (Keyboard::isKeyPressed(Keyboard::W)||Keyboard::isKeyPressed(Keyboard::Up)))
	{
		//DATA->getMusic("")
		//DATA->playSound("jump");
		canJump = 0;
		velocity.y =- sqrt(2.0f * 981.0f * jumpHeight);
	}
	velocity.y += 981.0f * deltaTime;
	//set animation if jump
	if (velocity.y < 0 && canJump == 0)
	{
		row = 2; //jumping
	}
	else 
		if (velocity.y > 0 && canJump == 0 && row != 1)
		{
			row = 3; //falling
		}
	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity*deltaTime);
	if (body.getPosition().y + animation.uvRect.height / 2 >= screenHeight)
	{
		isLive = 0;
		//canJump = 1;
		//body.setPosition(Vector2f(body.getPosition().x, screenHeight - animation.uvRect.height / 2));
	}
	//update View
	if (body.getPosition().x - screenWidth / 2 <= 0 )
		playerView.setCenter(screenWidth / 2, screenHeight / 2);
	else if(body.getPosition().x + screenWidth / 2 >= mapWidth)
		playerView.setCenter(mapWidth-screenWidth / 2, screenHeight / 2);
	else 
		playerView.setCenter(body.getPosition().x, screenHeight / 2);
	//life
}
void Player::draw(RenderWindow& window)
{
	if (isLive == 1)
	{
		window.setView(playerView);
		window.draw(body);
	}
}

void Player::OnCollision(Vector2f direction)
{
	if (direction.x!= 0.0f)
	{
		canJump = 0;
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//player standing on block
		velocity.y = 0.0f;
		canJump = 1;
	}
	else if (direction.y > 0.0f)
	{
		//block on top of player
		velocity.y = 0.0f;
	}
}

void Player::respawn()
{
	velocity.y = 0;
	isLive = 1;
	faceRight = 1;
	body.setPosition(lastCheckPoint);
}

Collider Player::getCollider()
{
	return Collider(body);
}

void Player::setLastCheckPoint(Vector2f position)
{
	lastCheckPoint = position;
}
