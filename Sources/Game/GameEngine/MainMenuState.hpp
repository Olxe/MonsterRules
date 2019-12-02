#pragma once

#include "State.hpp"
#include "../../Gui/Button.hpp"

namespace gameEngine
{
	class MainMenuState: public State
	{
	public:
		MainMenuState(GameEngine& gameEngine, bool replace = true);
		~MainMenuState();

		void onPause() override;
		void onResume() override;
		void onEvent(sf::Event& event) override;
		void onUpdate() override;
		void onDraw() override;

	private:
		std::vector<std::unique_ptr<gui::Widget>> m_widgets;
	};
}