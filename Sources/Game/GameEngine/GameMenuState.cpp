#include "GameMenuState.hpp"
#include "GameEngine.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

namespace gameEngine
{
	GameMenuState::GameMenuState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		shape.setPointCount(3);
		shape.setRadius(100);
		shape.setFillColor(sf::Color::Blue);
		Out("game menu created");
	}

	GameMenuState::~GameMenuState()
	{
		Out("game menu destroyed");
	}
	void GameMenuState::onPause()
	{
	}
	void GameMenuState::onResume()
	{
	}
	void GameMenuState::onEvent(sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_next = std::pair<std::string, std::unique_ptr<State>>("MAIN_MENU", GameEngine::BuildState<MainMenuState>(m_gameEngine, true));
				m_gameEngine.DeleteState("GAME");
				break;

			case sf::Keyboard::Return:
				m_gameEngine.ResumeLastState();
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
	void GameMenuState::onUpdate()
	{
	}
	void GameMenuState::onDraw()
	{
		m_gameEngine.Window().clear();
		m_gameEngine.Window().draw(shape);
		m_gameEngine.Window().display();
	}
}