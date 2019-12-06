#include "GameMenuState.hpp"
#include "GameEngine.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "OptionState.hpp"

namespace gameEngine
{
	GameMenuState::GameMenuState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		Out("game menu created");

		std::unique_ptr<gui::Label> l1 = std::make_unique<gui::Label>("Game menu", *AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"), 96, sf::Text::Bold, sf::Color::White, sf::Vector2f(0, -400));

		std::unique_ptr<gui::Button> b1 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(0, -200), "Resume");
		b1->setMouseButtonReleasedCallback(std::bind(&GameMenuState::toGame, this));

		std::unique_ptr<gui::Button> b2 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(0, -100), "Option");
		b2->setMouseButtonReleasedCallback(std::bind(&GameMenuState::toOption, this));

		std::unique_ptr<gui::Button> b3 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(0, 0), "Main menu");
		b3->setMouseButtonReleasedCallback(std::bind(&GameMenuState::toMainMenu, this));

		std::unique_ptr<gui::Button> b4 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(0, 100), "Quit");
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
		m_gameEngine.Window().clear();

		m_gameEngine.Window().draw(m_layout);

		m_gameEngine.Window().display();
	}

	void GameMenuState::toMainMenu()
	{
		m_next = std::pair<std::string, std::unique_ptr<State>>("MAIN_MENU", GameEngine::BuildState<MainMenuState>(m_gameEngine, true));
		//m_gameEngine.DeleteState("GAME");
	}

	void GameMenuState::toGame()
	{
		m_gameEngine.ResumeLastState();
	}

	void GameMenuState::toOption()
	{
		this->setNext(std::pair<std::string, std::unique_ptr<State>>("OPTION", GameEngine::BuildState<OptionState>(m_gameEngine, false)));
	}
}