#include "GameState.hpp"
#include "GameEngine.hpp"
#include "GameMenuState.hpp"

namespace gameEngine
{
	GameState::GameState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		rect.setSize(sf::Vector2f(100, 100));
		rect.setFillColor(sf::Color::Red);
		Out("game created");
	}

	GameState::~GameState()
	{
		Out("game destroyed");
	}
	void GameState::onPause()
	{
	}
	void GameState::onResume()
	{
	}
	void GameState::onEvent(sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_next = std::pair<std::string, std::unique_ptr<State>>("GAME_MENU", GameEngine::BuildState<GameMenuState>(m_gameEngine, false));
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
	void GameState::onUpdate()
	{
	}
	void GameState::onDraw()
	{
		m_gameEngine.Window().clear();
		m_gameEngine.Window().draw(rect);
		m_gameEngine.Window().display();
	}
}