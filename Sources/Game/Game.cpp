#include "game.h"

Game::Game()
{
	Window::CRenderWindow::Instance();
}

Game::~Game()
{  
	Window::CRenderWindow::DeleteInstance();
}

void Game::init()
{
	//CWindow::GetInstance()->Init();
    //m_world = new World();
}

void Game::StartGame()
{
	LevelManager levelManager;
	levelManager.LoadLevel(Level::LEVEL_1);

	//init();

	//CWindow* window = CWindow::GetInstance();

	//while (window->isOpen())
 //   {
	//	window->Update();

 //       if(window->GetIsWindowFocus()) m_world->Update(window->GetDeltaTime());

 //       m_world->Draw(*window);
 //   }
}