#include "State.hpp"
#include "../GameEngine.hpp"

namespace gameEngine
{
	State::State(GameEngine& gameEngine, bool replace)
		: m_gameEngine(gameEngine)
		, m_layout(gameEngine.Window())
		, m_replacing(replace)
	{
		//m_layout.setPosition(sf::Vector2f(Window::WindowManager::Instance()->GetWindow()->getSize().x / 2.f, Window::WindowManager::Instance()->GetWindow()->getSize().y / 2.f));
	}

	State::~State()
	{
	}

	sf::Vector2f State::ConvertMousePosition(sf::Vector2i position) const
	{
		return m_gameEngine.Window().mapPixelToCoords(position);
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