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

	void GameEngine::AddState(std::unique_ptr<State> state)
	{
		m_running = true;
		m_states.push(std::move(state));
	}

	void GameEngine::NextState()
	{
		if (!m_states.empty()) {
			if (std::unique_ptr<State> temp = m_states.top()->Next()) {
				if (temp->IsReplacing()) {
					m_states.pop();
				}
				else {
					m_states.top()->Pause();
				}

				m_states.push(std::move(temp));
			}
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