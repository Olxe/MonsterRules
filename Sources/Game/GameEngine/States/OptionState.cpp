#include "OptionState.hpp"
#include "../GameEngine.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

namespace gameEngine
{
	OptionState::OptionState(GameEngine& gameEngine, Window::CRenderWindow& window, bool replace)
		: State(gameEngine, window, replace)
	{
		Out("option created");
		sf::Vector2f windowSize = (sf::Vector2f)window.getSize();

		std::unique_ptr<gui::Label> l1 = std::make_unique<gui::Label>("Option menu", *AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"), 96, sf::Text::Regular, sf::Color::White, sf::Vector2f(windowSize.x / 2.f, 50));

		std::unique_ptr<gui::Button> b1 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(windowSize.x / 2.f, 500), "Return");
		b1->setMouseButtonReleasedCallback(std::bind(&OptionState::toReturn, this));

		m_layout.AddWidget(std::move(l1));
		m_layout.AddWidget(std::move(b1));
	}

	OptionState::~OptionState()
	{
		Out("option destroyed");
	}

	void OptionState::onPause()
	{
	}
	
	void OptionState::onResume()
	{
	}
	
	void OptionState::onEvent(sf::Event& event)
	{
		m_layout.onEvent(event);

		switch (event.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
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
	
	void OptionState::onUpdate()
	{
	}
	
	void OptionState::onDraw()
	{
		m_window.clear();

		m_window.draw(m_layout);

		m_window.display();
	}

	void OptionState::toReturn()
	{
		m_gameEngine.ResumeLastState();
	}
}