#pragma once

#include "State.hpp"

namespace GameEngine
{
	class GameState: public State
	{
	public:
		GameState(GameEngine& gameEngine, bool replace = true);
		~GameState();

		void Pause() override;
		void Resume() override;
		void Event(sf::Event& event) override;
		void Update() override;
		void Draw(sf::RenderWindow& window) override;

	private:
		sf::RectangleShape rect;
	};
}