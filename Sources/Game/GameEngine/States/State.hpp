#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../../../Gui/GuiLayout.hpp"
#include "../../../Tools/ToolsFunction.h"
#include "../../Window/WindowManager.hpp"

namespace gameEngine
{
	class GameEngine;

	class State
	{
	public:
		State(GameEngine& gameEngine, Window::CRenderWindow& window, bool replace = true);
		virtual ~State();

		void setNext(std::unique_ptr<State> state) { m_next = std::move(state); }

		sf::Vector2f ConvertMousePosition(sf::Vector2i position) const;
		std::unique_ptr<State> Next();

		virtual void onEvent(sf::Event& event) = 0;
		virtual void onUpdate() = 0;
		virtual void onDraw() = 0;
		virtual void onPause() = 0;
		virtual void onResume() = 0;

		bool IsReplacing();

	protected:
		GameEngine& m_gameEngine;
		Window::CRenderWindow& m_window;
		gui::GuiLayout m_layout;
		std::unique_ptr<State> m_next;
		bool m_replacing;

	};
}