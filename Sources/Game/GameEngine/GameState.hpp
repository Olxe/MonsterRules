#pragma once

#include "State.hpp"

namespace gameEngine
{
	class GameState: public State
	{
	public:
		GameState(GameEngine& gameEngine, bool replace = true);
		~GameState();

		void onPause() override;
		void onResume() override;
		void onEvent(sf::Event& event) override;
		void onUpdate() override;
		void onDraw() override;

	private:
		sf::RectangleShape rect;
	};
}