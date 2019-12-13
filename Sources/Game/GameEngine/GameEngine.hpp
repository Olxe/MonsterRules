#pragma once

#include "../Window/WindowManager.hpp"
#include <SFML/Window/Event.hpp>
#include <memory>
#include <stack>

namespace gameEngine
{
 	class State;

	class GameEngine
	{
	public:
		GameEngine(Window::CRenderWindow& window);
		~GameEngine();
		
		void Run(std::unique_ptr<State> state);
		void ClearPreviousState();
		void ResumeLastState();
		void NextState();
		void Update();
		void Draw();
		
		bool Running() const { return m_window.isOpen(); }
		void Quit();
		Window::CRenderWindow& Window() const { return m_window; }

		template <typename T>
		static std::unique_ptr<T> BuildState(GameEngine& gameEngine, Window::CRenderWindow& window, bool replace = true);

	private:
		std::vector <std::unique_ptr<State>> m_states;
		Window::CRenderWindow& m_window;
		bool m_resume;

	};

	template <typename T>
	std::unique_ptr<T> GameEngine::BuildState(GameEngine& machine, Window::CRenderWindow& window, bool replace)
	{
		return std::unique_ptr<T>(new T(machine, window, replace));
	}
}