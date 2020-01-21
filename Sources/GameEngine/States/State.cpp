#include "State.hpp"
#include "../GameEngine.hpp"

namespace gameEngine
{
	State::State(GameEngine& gameEngine, bool replace)
		: m_gameEngine(gameEngine)
		, m_window(gameEngine.Window())
		, m_layout(m_window)
		, m_replacing(replace)
	{
	}

	State::~State()
	{
	}

	sf::Vector2f State::ConvertMousePosition(sf::Vector2i position) const
	{
		return m_window.mapPixelToCoords(position);
	}

	std::unique_ptr<State> State::Next()
	{
		return std::move(m_next);
	}

	bool State::IsReplacing()
	{
		return m_replacing;
	}
}