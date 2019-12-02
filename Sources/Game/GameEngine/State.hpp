#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../../Tools/ToolsFunction.h"

namespace gameEngine
{
	class GameEngine;

	class State
	{
	public:
		State(GameEngine& gameEngine, bool replace = true);
		virtual ~State();

		void setNext(std::pair<std::string, std::unique_ptr<State>> state) { m_next = std::move(state); }

		sf::Vector2f ConvertMousePosition(sf::Vector2i position) const;
		std::pair<std::string, std::unique_ptr<State>> Next();

		virtual void onPause() = 0;
		virtual void onResume() = 0;
		virtual void onEvent(sf::Event& event) = 0;
		virtual void onUpdate() = 0;
		virtual void onDraw() = 0;

		bool IsReplacing();

	protected:
		GameEngine& m_gameEngine;
		std::pair<std::string, std::unique_ptr<State>> m_next;
		bool m_replacing;

	};
}