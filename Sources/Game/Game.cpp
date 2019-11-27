#include "game.h"

Game::Game()
{
}

Game::~Game()
{  
	Window::WindowManager::DeleteInstance();
}

void Game::StartGame()
{
	LevelManager levelManager;
	levelManager.LoadLevel(Level::LEVEL_1);

	Window::CRenderWindow* window = Window::WindowManager::Instance()->GetWindow();

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window->isOpen())
	{
		Window::WindowManager::Instance()->Update();
		
		if (window->WindowFocus()) {
			//update
		}

		window->clear();
		window->draw(shape);
		window->display();
	}
}