#pragma once

#include "State.hpp"

namespace GameEngine
{
	class MainMenuState: public State
	{
	public:
		MainMenuState(GameEngine& gameEngine, bool replace = true);
		~MainMenuState();

		void Pause() override;
		void Resume() override;
		void Event(sf::Event& event) override;
		void Update() override;
		void Draw(sf::RenderWindow& window) override;

	private:
		sf::CircleShape shape;
	};
}