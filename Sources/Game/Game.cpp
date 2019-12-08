#include "game.h"

Game::Game()
{
}

Game::~Game()
{  
	Window::WindowManager::DeleteInstance();
}

void Game::Run()
{
	gameEngine::GameEngine m_gameEngine(*Window::WindowManager::Instance()->GetWindow());
	m_gameEngine.Run(gameEngine::GameEngine::BuildState<gameEngine::MainMenuState>(m_gameEngine));

	while (m_gameEngine.Running()) {
		Window::WindowManager::Instance()->Update();
		m_gameEngine.NextState();
		m_gameEngine.Update();
		m_gameEngine.Draw();
	}
}