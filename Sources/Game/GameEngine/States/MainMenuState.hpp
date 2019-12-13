#pragma once

#include "State.hpp"

namespace gameEngine
{
	class MainMenuState: public State
	{
	public:
		MainMenuState(GameEngine& gameEngine, Window::CRenderWindow& window, bool replace = true);
		~MainMenuState();

		void onPause() override;
		void onResume() override;
		void onEvent(sf::Event& event) override;
		void onUpdate() override;
		void onDraw() override;

		void toOption();
		void toGame();

	};
}