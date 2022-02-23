#include "VictoryState.h"

VictoryState::VictoryState()
{
	background.setTexture(*DATA->getTexture("BackgroundMenu"));
	background.setPosition(0, 0);
	//text

	text.setFont(*DATA->getFont("Pangolin"));
	text.setCharacterSize(60);
	text.setString(L"Khá phết :3");
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(screenWidth / 2, 2 * screenHeight / 3);
	text.setOutlineThickness(1.0f);
	//menu button | | | | | |
	menu.setTexture(DATA->getTexture("MenuButton"));
	menu.setSize(Vector2f(100, 100));
	menu.setOrigin(50, 50);
	menu.setPosition(4 * screenWidth / 7, screenHeight / 2);
	//map
	restart.setTexture(DATA->getTexture("RestartButton"));
	restart.setSize(Vector2f(100, 100));
	restart.setOrigin(50, 50);
	restart.setPosition(3 * screenWidth / 7, screenHeight / 2);
}

void VictoryState::update(float deltaTime, State& state, RenderWindow& window)
{
	Vector2f mouse = (Vector2f)Mouse::getPosition(window);

	if (menu.getGlobalBounds().contains(mouse))
	{
		menu.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = State::MENU;
		}
	}
	else menu.setScale(1.0f, 1.0f);

	if (restart.getGlobalBounds().contains(mouse))
	{
		restart.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			state = State::PLAYING;
		}
	}
	else restart.setScale(1.0f, 1.0f);
}

void VictoryState::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(menu);
	window.draw(restart);
	window.draw(text);
}

void VictoryState::setString(int s)
{
	text.setString(L"Bạn đã thắng\nSố lần chết:" + to_string(s));
}
