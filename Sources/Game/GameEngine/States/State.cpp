#include "State.hpp"
#include "../GameEngine.hpp"

namespace gameEngine
{
	State::State(GameEngine& gameEngine, Window::CRenderWindow& window, bool replace)
		: m_gameEngine(gameEngine)
		, m_window(window)
		, m_layout(window)
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