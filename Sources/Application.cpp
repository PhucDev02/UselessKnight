#include"Application.h"
Application::Application()
{
}
void Application::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Close);
	window->setFramerateLimit(144);
	window->setVerticalSyncEnabled(false);
	icon.loadFromFile("Assets/Graphics/Icon.png");
	window->setIcon(498, 498, icon.getPixelsPtr());
	engine.init();
}
void Application::Update(float deltaTime)
{
	//update sth
	engine.update(deltaTime,*this->window);
}
void Application::Render()
{
	window->clear();
	//draw sth
	engine.draw(*window);
	//
	window->display();
}
Application::~Application()
{
	if (window != nullptr)
		delete window;
}
void Application::Run()
{
	Init();
	sf::Clock clock;
	float deltaTime = 0.f;
	while (window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		Event event;
		while (window->pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				
				window->close();
			}
			if (event.type == Event::Closed)
				window->close();
		}
		Update(deltaTime);
		Render();
	}
}