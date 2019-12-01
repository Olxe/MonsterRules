#include "GameState.hpp"
#include "GameEngine.hpp"
#include "MainMenuState.hpp"

namespace GameEngine
{
	GameState::GameState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		rect.setSize(sf::Vector2f(100, 100));
		rect.setFillColor(sf::Color::Red);
	}

	GameState::~GameState()
	{
	}
	void GameState::Pause()
	{
	}
	void GameState::Resume()
	{
	}
	void GameState::Event(sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_next = GameEngine::BuildState<MainMenuState>(m_gameEngine);
				break;

			default:
				break;
			}
			break;
		}

		default:
			break;
		}
	}
	void GameState::Update()
	{
	}
	void GameState::Draw(sf::RenderWindow& window)
	{
		window.clear();
		window.draw(rect);
		window.display();
	}
}