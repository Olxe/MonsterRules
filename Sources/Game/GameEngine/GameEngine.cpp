#include "GameEngine.hpp"
#include "State.hpp"

namespace GameEngine
{
	GameEngine::GameEngine(sf::RenderWindow& window)
		: m_window(window)
		, m_running(false)
	{
	}

	GameEngine::~GameEngine()
	{
	}

	void GameEngine::LastState()
	{
		if (!m_states.empty())
		{
			m_states.pop();
		}
		if (!m_states.empty())
		{
			m_states.top()->Resume();
		}
	}
	
	void GameEngine::NextState(std::unique_ptr<State> state)
	{
		if (state) {
			if (!m_states.empty()) {
				if (state->IsReplacing()) {
					m_states.pop();
				}
				else {
					m_states.top()->Pause();
				}
			}
			m_running = true;
			m_states.push(std::move(state));
		}
		else {
			this->Quit();
		}
	}

	void GameEngine::Update()
	{
		sf::Event event;

		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->Quit();
				break;

			default:
				m_states.top()->Event(event);
				break;
			}
		}

		m_states.top()->Update();
	}

	void GameEngine::Draw()
	{
		m_states.top()->Draw(m_window);
	}
}