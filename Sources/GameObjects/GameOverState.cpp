#include "GameOverState.h"

GameOverState::GameOverState()
{
	lives = 3;
	background.setTexture(*DATA->getTexture("BackgroundMenu"));
	background.setPosition(0, 0);
	//kewk
	kewk.setTexture(*DATA->getTexture("Kewk"));
	kewk.setOrigin((Vector2f)kewk.getTexture()->getSize() /2.0f);
	kewk.setPosition(rand() % screenWidth, rand() % screenHeight);
	//text
	text.setFont(*DATA->getFont("Pangolin"));
	text.setCharacterSize(60);
	text.setString(L"Ấn ENTER để chơi lại");
	text.setOrigin(text.getLocalBounds().width / 2,text.getLocalBounds().height / 2 );
	text.setPosition(screenWidth / 2, 2 * screenHeight / 3);
	text.setOutlineThickness(1.0f);
	//restart button
	restart.setTexture(DATA->getTexture("RestartButton"));
	restart.setSize(Vector2f(100,100));
	restart.setOrigin(50, 50);
	restart.setPosition(3*screenWidth / 7, screenHeight / 2);
	//menu button | | | | | |
	menu.setTexture(DATA->getTexture("MenuButton"));
	menu.setSize(Vector2f(100, 100));
	menu.setOrigin(50, 50);
	menu.setPosition(4*screenWidth / 7, screenHeight / 2);
}

void GameOverState::update(float deltaTime, State& state, RenderWindow& window)
{
	Vector2f mouse = (Vector2f)Mouse::getPosition(window);
	kewk.setPosition(mouse.x-200,mouse.y);
	
	if (restart.getGlobalBounds().contains(mouse))
	{
		restart.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = State::PLAYING;
		}
	}
	else restart.setScale(1.0f, 1.0f);
	if (menu.getGlobalBounds().contains(mouse))
	{
		menu.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = State::MENU;
		}
	}
	else menu.setScale(1.0f, 1.0f);
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		state = State::PLAYING;
	}
	text.setString(L"Bạn còn "+to_string(lives)+ L" mạng =))\nBấm ENTER để chơi lại");

}

void GameOverState::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(kewk);
	window.draw(restart);
	window.draw(menu);
	window.draw(text);
}
