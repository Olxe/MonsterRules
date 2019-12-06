#include "GameState.hpp"
#include "../GameEngine.hpp"
#include "GameMenuState.hpp"

namespace gameEngine
{
	GameState::GameState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
		, m_la_fps(nullptr)
		, m_timeToUpdateGui(1.f)
	{
		Out("game created");

		std::unique_ptr<gui::Label> l1 = std::make_unique<gui::Label>("Game", *AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"), 96, sf::Text::Regular, sf::Color::White, sf::Vector2f(0, -400));
		std::unique_ptr<gui::Label> la_fps = std::make_unique<gui::Label>("FPS", *AssetManager::Instance()->GetFont("Resources/Fonts/Arial.ttf"), 16, sf::Text::Regular, sf::Color::White, sf::Vector2f(-900, -500));
		m_la_fps = la_fps.get();

		m_layout.AddWidget(std::move(l1));
		m_layout.AddWidget(std::move(la_fps));
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
				this->setNext(GameEngine::BuildState<GameMenuState>(m_gameEngine, false));
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
		float deltaTime = m_clock.restart().asSeconds();
		m_timeToUpdateGui += deltaTime;

		m_world.Update(deltaTime);

		if (m_timeToUpdateGui > 0.5f) {
			m_la_fps->setText("FPS " + std::to_string(int(1.f / deltaTime)));
			m_timeToUpdateGui = 0.f;
		}
	}

	void GameState::onDraw()
	{
		m_gameEngine.Window().clear();

		m_world.Draw(m_gameEngine.Window());
		m_gameEngine.Window().draw(m_layout);

		m_gameEngine.Window().display();
	}
}