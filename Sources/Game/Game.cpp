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

	gameEngine::GameEngine m_gameEngine(*Window::WindowManager::Instance()->GetWindow());
	m_gameEngine.Run("MAIN_MENU", gameEngine::GameEngine::BuildState<gameEngine::MainMenuState>(m_gameEngine));

	while (m_gameEngine.Running()) {
		m_gameEngine.NextState();
		m_gameEngine.Update();
		m_gameEngine.Draw();
	}
}

void Game::Slot_f()
{
	Out("Slot");
}

void Game::Signal_f(const std::string& test)
{
	Out("Signal");
}
