#include "GameMenuState.hpp"
#include "GameEngine.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

namespace GameEngine
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
	void GameMenuState::Pause()
	{
	}
	void GameMenuState::Resume()
	{
	}
	void GameMenuState::Event(sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_gameEngine.NextState(GameEngine::BuildState<MainMenuState>(m_gameEngine, true));
				break;

			case sf::Keyboard::Return:
				m_gameEngine.LastState();
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
	void GameMenuState::Update()
	{
	}
	void GameMenuState::Draw(sf::RenderWindow& window)
	{
		window.clear();
		window.draw(shape);
		window.display();
	}
}