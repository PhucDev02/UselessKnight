#pragma once
#include "SFML/Graphics.hpp"
class GameStateBase
{
public:
	GameStateBase();
	virtual ~GameStateBase();
	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow) = 0;

	static GameStateBase* createState();
};