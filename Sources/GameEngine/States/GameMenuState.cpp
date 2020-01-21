#include "GameMenuState.hpp"
#include "../GameEngine.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "OptionState.hpp"

namespace gameEngine
{
	GameMenuState::GameMenuState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		Out("game menu created");
		sf::Vector2f windowSize = (sf::Vector2f)m_window.getSize();

		std::unique_ptr<gui::Label> l1 = std::make_unique<gui::Label>("Game menu", *AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"), 96, sf::Text::Regular, sf::Color::White, sf::Vector2f(windowSize.x / 2.f, 50));

		std::unique_ptr<gui::Button> b1 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(windowSize.x / 2.f, 200), "Resume");
		b1->setMouseButtonReleasedCallback(std::bind(&GameMenuState::toGame, this));

		std::unique_ptr<gui::Button> b2 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(windowSize.x / 2.f, 300), "Option");
		b2->setMouseButtonReleasedCallback(std::bind(&GameMenuState::toOption, this));

		std::unique_ptr<gui::Button> b3 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(windowSize.x / 2.f, 400), "Main menu");
		b3->setMouseButtonReleasedCallback(std::bind(&GameMenuState::toMainMenu, this));

		std::unique_ptr<gui::Button> b4 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(windowSize.x / 2.f, 500), "Quit");
		b4->setMouseButtonReleasedCallback(std::bind(&GameEngine::Quit, &m_gameEngine));

		m_layout.AddWidget(std::move(b1));
		m_layout.AddWidget(std::move(b2));
		m_layout.AddWidget(std::move(b3));
		m_layout.AddWidget(std::move(b4));
		m_layout.AddWidget(std::move(l1));
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
		m_layout.onEvent(event);

		switch (event.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				this->toGame();
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
		m_window.clear();

		m_window.draw(m_layout);

		m_window.display();
	}

	void GameMenuState::toMainMenu()
	{
		this->setNext(GameEngine::BuildState<MainMenuState>(m_gameEngine, true));
	}

	void GameMenuState::toGame()
	{
		m_gameEngine.ResumeLastState();
	}

	void GameMenuState::toOption()
	{
		this->setNext(GameEngine::BuildState<OptionState>(m_gameEngine, false));
	}
}