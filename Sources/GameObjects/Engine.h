#pragma once
#include "GameMap.h"
#include "../GameConfigure.h"
#include "Animation.h"
#include "Player.h"
#include "GameMap.h"
#include "Menu.h"
#include "GameOverState.h"
#include "SettingState.h"
#include "VictoryState.h"
#include "AboutState.h"
#include "HowToPlayState.h"
#include "../GameManager/ResourceManager.h"
class Engine
{
public:
	Player player;
	GameMap gameMap;
	State state;
	//state
	Menu menu;
	AboutState aboutState;
	GameOverState gameOverState;
	VictoryState victoryState;
	SettingState settingState;
	HowToPlayState howToPlayState;
public:
	Engine() {};
	void init();
	void update(float deltaTime, RenderWindow& window);
	void draw(RenderWindow& window);
	void changeState(State state);
};