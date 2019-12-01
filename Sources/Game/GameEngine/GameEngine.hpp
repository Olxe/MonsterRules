#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <stack>

namespace GameEngine
{
 	class State;

	class GameEngine
	{
	public:
		GameEngine(sf::RenderWindow& window);
		~GameEngine();

		void LastState();
		void NextState(std::unique_ptr<State> state);
		void Update();
		void Draw();

		bool Running() { return m_running; }
		void Quit() { m_running = false; }

		template <typename T>
		static std::unique_ptr<T> BuildState(GameEngine& gameEngine, bool replace = true);

	private:
		std::stack<std::unique_ptr<State>> m_states;
		sf::RenderWindow& m_window;
		bool m_running;
	};

	template <typename T>
	std::unique_ptr<T> GameEngine::BuildState(GameEngine& machine, bool replace)
	{
		return std::unique_ptr<T>(new T(machine, replace));
	}
}