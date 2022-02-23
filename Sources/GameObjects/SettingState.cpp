#include "SettingState.h"

SettingState::SettingState()
{
	background.setTexture(*DATA->getTexture("BackgroundMenu"));
	background.setPosition(0, 0);

	close.setTexture(DATA->getTexture("CloseButton"));
	close.setSize(Vector2f(80, 80));
	close.setOrigin(40, 40);
	close.setPosition(1100, 68);

	musicIcon.setTexture(DATA->getTexture("MusicOn"));
	musicIcon.setSize(Vector2f(100, 100));
	musicIcon.setOrigin(musicIcon.getSize() / 2.0f);
	musicIcon.setPosition(screenWidth / 5, 2 * screenHeight / 3);

	load.setTexture(DATA->getTexture("Load"));
	load.setSize(Vector2f(20, 40));
	load.setOrigin(load.getSize() / 2.0f);
	load.setPosition(870*screenWidth / 1200, 2 * screenHeight / 3);

	loadBar.setTexture(DATA->getTexture("LoadBar"));
	loadBar.setSize(Vector2f(574, 21));
	loadBar.setOrigin(loadBar.getSize() / 2.0f);
	loadBar.setPosition(screenWidth / 2, 2 * screenHeight / 3);
}

void SettingState::update(float deltaTime, State& state, RenderWindow& window)
{
	Vector2f mouse = (Vector2f)Mouse::getPosition(window);
	if (close.getGlobalBounds().contains(mouse))
	{
		close.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = State::MENU;
		}
	}
	else close.setScale(1.0f, 1.0f);
	if (load.getGlobalBounds().contains(mouse))
	{
		load.setScale(1.5f, 1.5f);
	}
	else load.setScale(1.0f, 1.0f);
	if (loadBar.getGlobalBounds().contains(mouse))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			load.setPosition(mouse.x, load.getPosition().y);
		}
	}
	//load
	if (load.getPosition().x < 330 * screenWidth / 1200) {
		load.setPosition(329 * screenWidth / 1200, load.getPosition().y);
		musicIcon.setTexture(DATA->getTexture("MusicOff"));
	}
	else
	{
		musicIcon.setTexture(DATA->getTexture("MusicOn"));
	}
	if (load.getPosition().x > 870 * screenWidth / 1200) {
		load.setPosition(870 * screenWidth / 1200, load.getPosition().y);
	}
	DATA->getMusic("gameMusic")->setVolume(((load.getPosition().x - 329) / 550) * 20);
	//
}

void SettingState::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(close);
	window.draw(loadBar);
	window.draw(musicIcon);
	window.draw(load);
}
