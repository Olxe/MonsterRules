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
	LevelManager levelManager;
	levelManager.LoadLevel(Level::LEVEL_1);

	GameEngine::GameEngine m_gameEngine(*Window::WindowManager::Instance()->GetWindow());
	m_gameEngine.NextState(GameEngine::GameEngine::BuildState<GameEngine::MainMenuState>(m_gameEngine));

	while (m_gameEngine.Running()) {
		m_gameEngine.Update();
		m_gameEngine.Draw();
	}
}