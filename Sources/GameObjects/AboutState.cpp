#include "AboutState.h"
AboutState::AboutState()
{

	background.setTexture(*DATA->getTexture("BackgroundMenu"));
	background.setPosition(0, 0);
	//
	text.setFont(*DATA->getFont("Pangolin"));
	text.setCharacterSize(60);
	text.setString(L"Sản phẩm đầu tiên của minh :>");
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(screenWidth / 2, 2 * screenHeight / 3);
	text.setOutlineThickness(1.0f);
	//
	close.setTexture(DATA->getTexture("CloseButton"));
	close.setSize(Vector2f(80, 80));
	close.setOrigin(40, 40);
	close.setPosition(1100, 68);
	//
	fb.setTexture(DATA->getTexture("Icon"));
	fb.setSize(Vector2f(90, 90));
	fb.setOrigin(45, 45);
	fb.setPosition(screenWidth/2, 668);
}

void AboutState::update(float deltaTime, State& state, RenderWindow& window)
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
	if (fb.getGlobalBounds().contains(mouse))
	{
		fb.setScale(1.2f, 1.2f);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			//ShellExecute(0, 0, L"http://www.google.com", 0, 0, SW_SHOWNORMAL);
		}
	}
	else fb.setScale(1.0f, 1.0f);
}

void AboutState::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(close);
	window.draw(text);
	window.draw(fb);
}
