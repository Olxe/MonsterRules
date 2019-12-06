#include "OptionState.hpp"
#include "../GameEngine.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

namespace gameEngine
{
	OptionState::OptionState(GameEngine& gameEngine, bool replace)
		: State(gameEngine, replace)
	{
		Out("option created");

		std::unique_ptr<gui::Label> l1 = std::make_unique<gui::Label>("Option menu", *AssetManager::Instance()->GetFont("Resources/Fonts/EnchantedLand-jnX9.ttf"), 96, sf::Text::Regular, sf::Color::White, sf::Vector2f(0, -400));

		std::unique_ptr<gui::Button> b1 = std::make_unique<gui::Button>(AssetManager::Instance()->GetTexture("Resources/Textures/ui_temp/blue_button00.png"), sf::Vector2f(0, 0), "Return");
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
	}
	
	void OptionState::onUpdate()
	{
	}
	
	void OptionState::onDraw()
	{
		m_gameEngine.Window().clear();

		m_gameEngine.Window().draw(m_layout);

		m_gameEngine.Window().display();
	}

	void OptionState::toReturn()
	{
		m_gameEngine.ResumeLastState();
	}
}