#include "GameMap.h"
GameMap::GameMap()
{
	init();
}

void GameMap::init()
{
	int a[16][125] = map1;

	background.setTexture(*DATA->getTexture("Background"));
	background.setPosition(0, 0);

	platforms.clear();
	hiddenBlocks.clear();
	gravityBlocks.clear();
	bots.clear();
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 125; j++)
		{
			if (a[i][j] == 1)
				platforms.push_back(Platform(DATA->getTexture("Platform"), Vector2f((j * 48) + 24, i * 48 + 24)));
			if (a[i][j] == 2)
				hiddenBlocks.push_back(HiddenBlock(DATA->getTexture("Platform"), Vector2f((j * 48) + 24, i * 48 + 24)));
			if (a[i][j] == 4)
				gravityBlocks.push_back(GravityBlock(DATA->getTexture("Platform"), Vector2f((j * 48) + 24, i * 48 + 24)));
			if (a[i][j] == 5)
				platforms.push_back(Platform(DATA->getTexture("Tree"), Vector2f((j * 48) + 24, i * 48 + 24)));
			if (a[i][j]== 9 )
				censorBlocks.push_back(CensorBlock(DATA->getTexture("Platform"), Vector2f((j * 48) + 24, i * 48 + 24)));
		}
	}
	door = Door(Vector2f(122*48,13*48));
	bots.push_back(Bot(DATA->getTexture("Snake"), Vector2f((18 * 48) + 24, (10 * 48) + 24)));
	bots.push_back(Bot(DATA->getTexture("Snake"), Vector2f((43 * 48) + 24, (10 * 48) + 24)));
	bots.push_back(Bot(DATA->getTexture("Snake"), Vector2f((68*48)+24, (10*48)+24)));
	//checkpoint
	checkPoint = CheckPoint(DATA->getTexture("CheckPoint"), Vector2f(69 * 48 + 24, 7 * 48 + 24));
}

bool GameMap::checkWin(Player player)
{
	if (door.checkCollision(player)) {
		init();
		return 1;
	}
	else return 0;
}

void GameMap::update(float deltaTime, Player& player)
{
	Vector2f direction;
	for (int i = 0; i < platforms.size(); i++)
	{
		if (platforms[i].getCollider().checkCollision(player.getCollider(), direction))
		{
			player.OnCollision(direction);
		}
	}
	for (int i = 0; i < hiddenBlocks.size(); i++)
	{
		if (hiddenBlocks[i].getCollider().checkCollisionHiddenBlock(player.getCollider()) == 0 && hiddenBlocks[i].getHidden() == 1)
		{
			hiddenBlocks[i].setHidden(0);
		}
		if (hiddenBlocks[i].getHidden() == 0)
			if (hiddenBlocks[i].getCollider().checkCollision(player.getCollider(), direction))
			{
				player.OnCollision(direction);
			}
	}
	for (int i = 0; i < gravityBlocks.size(); i++)
	{
		if (gravityBlocks[i].getCollider().checkCollisionGravityBlock(player.getCollider()))
		{
			gravityBlocks[i].setFall(1);
		}
		if (gravityBlocks[i].getFall() == 1)
		{
			gravityBlocks[i].update(deltaTime);
		}
	}
	for (int i = 0; i < bots.size(); i++)
	{
		bots[i].update(deltaTime, player);
	}
	for (int i = 0; i < censorBlocks.size(); i++)
	{
		censorBlocks[i].update(deltaTime, player);
	}
	checkPoint.update(deltaTime, player);
}

void GameMap::draw(RenderWindow& window,Player player)
{
	window.draw(background);
	for (int i = 0; i < platforms.size(); i++)
		platforms[i].draw(window);
	for (int i = 0; i < hiddenBlocks.size(); i++)
		hiddenBlocks[i].draw(window);
	//gravityBlock cho vao thi bi loi lnk2019

	for (int i = gravityBlocks.size() - 1; i >= 0; i--)
		gravityBlocks[i].draw(window);
	for (int i = 0; i < bots.size(); i++)
		bots[i].draw(window,player);
	for (int i = 0; i < censorBlocks.size(); i++)
		censorBlocks[i].draw(window);
	checkPoint.draw(window);
	door.draw(window);
}
