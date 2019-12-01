#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "../../Tools/ToolsFunction.h"

namespace GameEngine
{
	class GameEngine;

	class State
	{
	public:
		State(GameEngine& gameEngine, bool replace = true);
		virtual ~State();

		virtual void Pause() = 0;
		virtual void Resume() = 0;
		virtual void Event(sf::Event& event) = 0;
		virtual void Update() = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;

		bool IsReplacing();

	protected:
		GameEngine& m_gameEngine;
		bool m_replacing;

	};
}