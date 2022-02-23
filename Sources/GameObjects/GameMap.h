#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include<vector>
#include "Platform.h"
#include "GravityBlock.h"
#include "HiddenBlock.h"
#include "CheckPoint.h"
#include "../GameConfigure.h"
#include "../GameManager/ResourceManager.h"
#include "Door.h"
#include "Bot.h"
#include "CensorBlock.h"
#include "Player.h"
using namespace sf;
class GameMap
{
private:
	vector<Platform> platforms;
	vector<HiddenBlock> hiddenBlocks;
	vector<Bot> bots;
	vector<CensorBlock> censorBlocks;
	vector<GravityBlock> gravityBlocks;
	CheckPoint checkPoint;
	Door door;
	Sprite background;
public:
	GameMap();
	void init();
	void update(float deltaTime, Player& player);
	void draw(RenderWindow& window,Player player);
	bool checkWin(Player player);
};
