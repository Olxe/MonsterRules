#include "State.hpp"

namespace GameEngine
{
	State::State(GameEngine& gameEngine, bool replace)
		: m_gameEngine(gameEngine)
		, m_replacing(replace)
	{
	}

	State::~State()
	{
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