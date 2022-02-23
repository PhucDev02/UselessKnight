#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObjects/Engine.h"
#include "GameManager/ResourceManager.h"
using namespace sf;
class Application {
private:
	void Init();
	void Update(float deltaTime);
	void Render();
	
	//all object of game
	Image icon;
	Engine engine;
public:
	void Run();
	~Application();
	Application();

	RenderWindow* window;
};