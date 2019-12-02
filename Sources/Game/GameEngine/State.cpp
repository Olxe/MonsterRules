#include "State.hpp"
#include "GameEngine.hpp"

namespace gameEngine
{
	State::State(GameEngine& gameEngine, bool replace)
		: m_gameEngine(gameEngine)
		, m_layout(gameEngine.Window(), sf::Vector2f(1000, 500))
		, m_replacing(replace)
	{
	}

	State::~State()
	{
	}

	sf::Vector2f State::ConvertMousePosition(sf::Vector2i position) const
	{
		return m_gameEngine.Window().mapPixelToCoords(position);
	}

	std::pair<std::string, std::unique_ptr<State>> State::Next()
	{
		return std::move(m_next);
	}

	bool State::IsReplacing()
	{
		return m_replacing;
	}
}