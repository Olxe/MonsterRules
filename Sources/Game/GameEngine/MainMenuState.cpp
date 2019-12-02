#include "MainMenuState.hpp"
#include "GameEngine.hpp"
#include "GameState.hpp"

namespace gameEngine
{
	MainMenuState::MainMenuState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		Out("menu created");
		m_widgets.push_back(std::make_unique<gui::Button>( AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(500, 100), "Play",
			[&]() { this->setNext(std::pair<std::string, std::unique_ptr<State>>("GAME", GameEngine::BuildState<GameState>(m_gameEngine, true))); }) );
		m_widgets.push_back(std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(500, 200), "Option"));
		m_widgets.push_back(std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(500, 300), "Quit"));
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
				m_next = std::pair<std::string, std::unique_ptr<State>>("GAME", GameEngine::BuildState<GameState>(m_gameEngine, true));
				break;

			default:
				break;
			}

			break;
		}
		case sf::Event::MouseButtonReleased:
			for (auto& it : m_widgets) {
				it->onMouseButtonReleased(event.mouseButton.x, event.mouseButton.y);
			}
			break;

		default:
			break;
		}
	}

	void MainMenuState::onUpdate()
	{
	}

	void MainMenuState::onDraw()
	{
		m_gameEngine.Window().clear();
		
		for (auto& it : m_widgets) {
			m_gameEngine.Window().draw(*it);
		}

		m_gameEngine.Window().display();
	}
}