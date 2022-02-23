#include "HowToPlayState.h"
HowToPlayState::HowToPlayState()
{

	background.setTexture(*DATA->getTexture("BackgroundMenu"));
	background.setPosition(0, 0);
	//
	text.setFont(*DATA->getFont("Pangolin"));
	text.setCharacterSize(50);
	text.setFillColor(Color::Green);
	text.setString(L"Bấm phím điều hướng hoặc WAD để di chuyển \nvà vượt qua các chướng ngại vật,chạm tới \ncánh cửa thật ở cuối map sẽ thắng :>.\nGame có nhiều tình tiết sẽ khiến bạn cay cú");
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(screenWidth / 2, 2 * screenHeight / 3);
	text.setOutlineThickness(1.0f);
	//
	close.setTexture(DATA->getTexture("CloseButton"));
	close.setSize(Vector2f(80, 80));
	close.setOrigin(40, 40);
	close.setPosition(1100, 68);
}

void HowToPlayState::update(float deltaTime, State& state, RenderWindow& window)
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
}

void HowToPlayState::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(close);
	window.draw(text);
}
