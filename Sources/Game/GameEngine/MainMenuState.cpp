#include "MainMenuState.hpp"
#include "GameEngine.hpp"
#include "GameState.hpp"

namespace GameEngine
{
	MainMenuState::MainMenuState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		shape.setRadius(100);
		shape.setFillColor(sf::Color::Green);
		Out("menu created");
	}

	MainMenuState::~MainMenuState()
	{
		Out("menu destroyed");
	}

	void MainMenuState::Pause()
	{
	}

	void MainMenuState::Resume()
	{
	}

	void MainMenuState::Event(sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_gameEngine.Quit();
				break;
				
			case sf::Keyboard::Return:
				m_gameEngine.NextState(GameEngine::BuildState<GameState>(m_gameEngine, true));
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

	void MainMenuState::Update()
	{
	}

	void MainMenuState::Draw(sf::RenderWindow& window)
	{
		window.clear();
		window.draw(shape);
		window.display();
	}
}