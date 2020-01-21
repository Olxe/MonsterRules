#include "MainMenuState.hpp"
#include "../GameEngine.hpp"
#include "GameState.hpp"
#include "OptionState.hpp"

namespace gameEngine
{
	MainMenuState::MainMenuState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		Out("menu created");
		sf::Vector2f windowSize = (sf::Vector2f)m_window.getSize();

		m_gameEngine.ClearPreviousState();

		std::unique_ptr<gui::Label> l1 = std::make_unique<gui::Label>("Main menu", *AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"), 96, sf::Text::Regular, sf::Color::White, sf::Vector2f(windowSize.x / 2.f, 50));

		std::unique_ptr<gui::Button> b1 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(windowSize.x / 2.f, 300), "Play");
		b1->setMouseButtonReleasedCallback(std::bind(&MainMenuState::toGame, this));

		std::unique_ptr<gui::Button> b2 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(windowSize.x / 2.f, 400), "Option");
		b2->setMouseButtonReleasedCallback(std::bind(&MainMenuState::toOption, this));

		std::unique_ptr<gui::Button> b3 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(windowSize.x / 2.f, 500), "Quit");
		b3->setMouseButtonReleasedCallback(std::bind(&GameEngine::Quit, &m_gameEngine));
		
		m_layout.AddWidget(std::move(b1));
		m_layout.AddWidget(std::move(b2));
		m_layout.AddWidget(std::move(b3));
		m_layout.AddWidget(std::move(l1));

		this->setNext(GameEngine::BuildState<GameState>(m_gameEngine, true));
	}

	MainMenuState::~MainMenuState()
	{
		Out("menu destroyed");
	}

	void MainMenuState::onPause()
	{
	}

	void MainMenuState::onResume()
	{
	}

	void MainMenuState::onEvent(sf::Event& event)
	{
		m_layout.onEvent(event);
	}

	void MainMenuState::onUpdate()
	{
	}

	void MainMenuState::onDraw()
	{
		m_window.clear();
		
		m_window.draw(m_layout);

		m_window.display();
	}

	void MainMenuState::toOption()
	{
		this->setNext(GameEngine::BuildState<OptionState>(m_gameEngine, false));
	}

	void MainMenuState::toGame()
	{
		this->setNext(GameEngine::BuildState<GameState>(m_gameEngine, true));
	}
}