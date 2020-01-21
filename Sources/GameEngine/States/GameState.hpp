#pragma once

#include "State.hpp"
#include "../../World.hpp"

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
		World m_world;
		sf::Clock m_clock;

		gui::Label* m_la_fps;
		float m_timeToUpdateGui;

	};
}