#pragma once

#include "State.hpp"

namespace GameEngine
{
	class GameMenuState: public State
	{
	public:
		GameMenuState(GameEngine& gameEngine, bool replace = true);
		~GameMenuState();

		void Pause() override;
		void Resume() override;
		void Event(sf::Event& event) override;
		void Update() override;
		void Draw(sf::RenderWindow& window) override;

	private:
		sf::CircleShape shape;
	};
}