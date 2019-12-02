#pragma once

#include "State.hpp"

namespace gameEngine
{
	class GameMenuState: public State
	{
	public:
		GameMenuState(GameEngine& gameEngine, bool replace = true);
		~GameMenuState();

		void onPause() override;
		void onResume() override;
		void onEvent(sf::Event& event) override;
		void onUpdate() override;
		void onDraw() override;

		void toMainMenu();
		void toGame();
	};
}