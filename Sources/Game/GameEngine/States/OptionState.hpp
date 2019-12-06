#pragma once

#include "State.hpp"

namespace gameEngine
{
	class OptionState: public State
	{
	public:
		OptionState(GameEngine& gameEngine, bool replace = true);
		~OptionState();

		void onPause() override;
		void onResume() override;
		void onEvent(sf::Event& event) override;
		void onUpdate() override;
		void onDraw() override;

		void toReturn();
	};
}

