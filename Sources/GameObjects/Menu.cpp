#include "Menu.h"
//#include <iostream>
Menu::Menu()
{
	background.setTexture(*DATA->getTexture("BackgroundMenu"));
	background.setPosition(0, 0);
	//
	ani1 = Animation(DATA->getTexture("Player"), Vector2u(4, 5), 0.1f);
	ani2 = Animation(DATA->getTexture("Flower"), Vector2u(8, 1), 0.1f);
	ani3 = Animation(DATA->getTexture("Snake"), Vector2u(8,1), 0.05f);

	deco1.setTexture(DATA->getTexture("Player"));
	deco1.setPosition(5 * screenWidth / 16-25, 4 * screenHeight / 5-115);
	deco1.setSize(Vector2f(48,65));

	deco2.setTexture(DATA->getTexture("Flower"));
	deco2.setPosition(8 * screenWidth / 16 - 29, 4 * screenHeight / 5-110);
	deco2.setSize(Vector2f(60, 60));

	deco3.setTexture(DATA->getTexture("Snake"));
	deco3.setPosition(11 * screenWidth / 16 - 29, 4 * screenHeight / 5-98);
	deco3.setSize(Vector2f(48, 48));
	//
	play.setTexture(DATA->getTexture("PlayButton"));
	play.setSize(Vector2f(140,140));
	play.setOrigin(70,70);
	play.setPosition(screenWidth / 2, screenHeight / 2);
	//
	howToPlay.setTexture(DATA->getTexture("HowToPlayButton"));
	howToPlay.setSize(Vector2f(100, 100));
	howToPlay.setOrigin(50, 50);
	howToPlay.setPosition(5*screenWidth / 16, 4 * screenHeight /5 );
	//
	about.setTexture(DATA->getTexture("AboutButton"));
	about.setSize(Vector2f(100, 100));
	about.setOrigin(50, 50);
	about.setPosition(8*screenWidth / 16, 4 * screenHeight / 5);
	//
	setting.setTexture(DATA->getTexture("SettingButton"));
	setting.setSize(Vector2f(100, 100));
	setting.setOrigin(50, 50);
	setting.setPosition(11*screenWidth / 16, 4*screenHeight / 5);
}
void Menu::update(float deltaTime,State &state,RenderWindow &window)
{
	Vector2f mouse = (Vector2f)Mouse::getPosition(window);
	if (play.getGlobalBounds().contains(mouse))
	{
		play.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = State::PLAYING;
		}
	}
	else play.setScale(1.0f, 1.0f);
	if (setting.getGlobalBounds().contains(mouse))
	{
		setting.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = State::SETTING;
		}
	}
	else setting.setScale(1.0f, 1.0f);
	if (about.getGlobalBounds().contains(mouse))
	{
		about.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = State::ABOUT;
		}
	}
	else about.setScale(1.0f, 1.0f);
	if (howToPlay.getGlobalBounds().contains(mouse))
	{
		howToPlay.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = State::HOW_TO_PLAY;
		}
	}
	else howToPlay.setScale(1.0f, 1.0f);
	ani1.update(1, deltaTime, 1);
	ani2.update(0, deltaTime, 1);
	ani3.update(0, deltaTime, 0);
	deco1.setTextureRect(ani1.uvRect);
	deco2.setTextureRect(ani2.uvRect);
	deco3.setTextureRect(ani3.uvRect);
}
void Menu::draw(RenderWindow &window)
{
	window.draw(background);
	window.draw(play);
	window.draw(setting);
	window.draw(about);
	window.draw(howToPlay);
	window.draw(deco1);
	window.draw(deco2);
	window.draw(deco3);
}
