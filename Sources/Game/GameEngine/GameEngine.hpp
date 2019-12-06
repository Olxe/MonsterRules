#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <stack>

namespace gameEngine
{
 	class State;

	class GameEngine
	{
	public:
		GameEngine(sf::RenderWindow& window);
		~GameEngine();
		
		void Run(std::string name, std::unique_ptr<State> state);
		void DeleteState(std::string name);
		void ResumeLastState();
		void NextState();
		void Update();
		void Draw();

		bool Running() const { return m_running; }
		void Quit() { m_running = false; }
		sf::RenderWindow& Window() const { return m_window; }

		template <typename T>
		static std::unique_ptr<T> BuildState(GameEngine& gameEngine, bool replace = true);

		bool m_resume = false;
	private:
		std::vector < std::pair<std::string, std::unique_ptr<State>>> m_states;
		sf::RenderWindow& m_window;
		bool m_running;

	};

	template <typename T>
	std::unique_ptr<T> GameEngine::BuildState(GameEngine& machine, bool replace)
	{
		return std::unique_ptr<T>(new T(machine, replace));
	}
}