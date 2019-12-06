#include "MainMenuState.hpp"
#include "GameEngine.hpp"
#include "GameState.hpp"
#include "OptionState.hpp"

namespace gameEngine
{
	MainMenuState::MainMenuState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		Out("menu created");

		std::unique_ptr<gui::Label> l1 = std::make_unique<gui::Label>("Main menu", *AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"), 96, sf::Text::Regular, sf::Color::White, sf::Vector2f(0, -400));

		std::unique_ptr<gui::Button> b1 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(0, -100), "Play");
		b1->setMouseButtonReleasedCallback([&]() { this->toGame(); });

		std::unique_ptr<gui::Button> b2 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(0, 0), "Option");
		b2->setMouseButtonReleasedCallback([&]() { this->toOption(); });

		std::unique_ptr<gui::Button> b3 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(0, 100), "Quit");
		b3->setMouseButtonReleasedCallback([&]() { m_gameEngine.Quit(); });
		
		m_layout.AddWidget(std::move(b1));
		m_layout.AddWidget(std::move(b2));
		m_layout.AddWidget(std::move(b3));
		m_layout.AddWidget(std::move(l1));
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
		m_gameEngine.Window().clear();
		
		m_gameEngine.Window().draw(m_layout);

		m_gameEngine.Window().display();
	}

	void MainMenuState::toOption()
	{
		this->setNext(std::pair<std::string, std::unique_ptr<State>>("OPTION", GameEngine::BuildState<OptionState>(m_gameEngine, false)));
	}

	void MainMenuState::toGame()
	{
		this->setNext(std::pair<std::string, std::unique_ptr<State>>("GAME", GameEngine::BuildState<GameState>(m_gameEngine, true)));
	}
}