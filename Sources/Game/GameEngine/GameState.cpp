#include "GameState.hpp"
#include "GameEngine.hpp"
#include "GameMenuState.hpp"

namespace gameEngine
{
	GameState::GameState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		Out("game created");

		std::unique_ptr<gui::Label> l1 = std::make_unique<gui::Label>("Game", *AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"), 96, sf::Text::Regular, sf::Color::White, sf::Vector2f(0, -400));
		
		m_layout.AddWidget(std::move(l1));
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
		m_layout.onEvent(event);

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

		m_gameEngine.Window().draw(m_layout);

		m_gameEngine.Window().display();
	}
}