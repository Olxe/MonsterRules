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
	Window::CRenderWindow& window = *Window::WindowManager::Instance()->GetWindow();
	gameEngine::GameEngine m_gameEngine(window);
	m_gameEngine.Run(gameEngine::GameEngine::BuildState<gameEngine::MainMenuState>(m_gameEngine, true));

	while (m_gameEngine.Running()) {
		Window::WindowManager::Instance()->Update();
		m_gameEngine.NextState();
		m_gameEngine.Update();
		m_gameEngine.Draw();
	}
}