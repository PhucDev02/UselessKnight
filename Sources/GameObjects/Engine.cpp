#include "Engine.h"

void Engine::init()
{
	//set player
	player = Player(DATA->getTexture("Player"), Vector2u(4, 5), 0.1f, 200.0f);
	//background
	state = State::MENU;
	DATA->playMusic("gameMusic");
}

void Engine::update(float deltaTime,  RenderWindow& window)
{
	if (gameMap.checkWin(player))
	{
		gameMap.init();
		player.setLastCheckPoint(Vector2f(200, 100));
		player.setPosition(200, 100);
		state = State::VICTORY;
		victoryState.setString(3-gameOverState.lives);
		gameOverState.lives = 3;
	}
	if (player.getIsLive() == 0)
	{
		gameMap.init();
		player.respawn();
		gameOverState.lives--;
		state = State::GAME_OVER;
	}
	if (state == State::VICTORY)
	{
		window.setView(View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight)));
		victoryState.update(deltaTime,state,window);
	}
	if (state == State::ABOUT)
	{
		window.setView(View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight)));
		aboutState.update(deltaTime, state, window);
	}
	if (state == State::GAME_OVER)
	{
		window.setView(View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight)));
		gameOverState.update(deltaTime, state, window);
	}
	if (state == State::MENU)
	{
		//cout << "WA";
		window.setView(View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight)));
		menu.update(deltaTime,state,window);
	}
	if(state==State::PLAYING)
	{
		//cout << "PLAYING ";
		player.update(deltaTime);
		gameMap.update(deltaTime, player);
	}
	if (state == State::SETTING)
	{
		window.setView(View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight)));
		settingState.update(deltaTime, state, window);
	}
	if (state == State::HOW_TO_PLAY)
	{
		window.setView(View(Vector2f(screenWidth / 2, screenHeight / 2), Vector2f(screenWidth, screenHeight)));
		howToPlayState.update(deltaTime, state, window);
	}
}

void Engine::draw(RenderWindow& window)
{
	if (state == State::MENU)
	{
		menu.draw(window);
	}
	if (state == State::HOW_TO_PLAY)
	{
		howToPlayState.draw(window);
	}
	if (state == State::GAME_OVER)
	{
		gameOverState.draw(window);
	}
	if (state == State::VICTORY)
	{
		victoryState.draw(window);
	}
	if(state==State::PLAYING)
	{
		gameMap.draw(window,player);
		player.draw(window);
	}
	if (state == State::SETTING)
	{
		settingState.draw(window);
	}
	if (state == State::ABOUT)
	{
		aboutState.draw(window);
	}
}

void Engine::changeState(State state)
{
	this->state = state;
}
