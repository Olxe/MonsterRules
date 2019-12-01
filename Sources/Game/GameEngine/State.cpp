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

	bool State::IsReplacing()
	{
		return m_replacing;
	}
}