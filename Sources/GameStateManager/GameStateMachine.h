#pragma once
#include "SFML/Graphics.hpp"
#include "GameStateBase.h"
#include <stack>
class GameStateMachine
{
private: 
	static GameStateMachine* instance;
	std::stack<GameStateBase*> stateStack;
	GameStateBase* activeState;
public:
	~GameStateMachine();
	static GameStateMachine* getInstance()
	{
		if (instance == nullptr)
			instance = new GameStateMachine();
		return instance;
	}
};
GameStateMachine* GameStateMachine::instance = nullptr;