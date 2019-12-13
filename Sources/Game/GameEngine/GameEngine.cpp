#include "GameEngine.hpp"
#include "States/State.hpp"

namespace gameEngine
{
	GameEngine::GameEngine(Window::CRenderWindow& window)
		: m_window(window)
		, m_resume(false)
	{
	}

	GameEngine::~GameEngine()
	{
	}

	void GameEngine::Run(std::unique_ptr<State> state)
	{
		m_states.push_back(std::move(state));
	}

	void GameEngine::ClearPreviousState()
	{
		for (unsigned int i = 0; i < m_states.size(); ++i) {
			if (i != m_states.size() - 1) {
				m_states.erase(m_states.begin() + i);
			}
		}
	}

	void GameEngine::ResumeLastState()
	{
		m_resume = true;
	}
	
	void GameEngine::NextState()
	{
		if (m_resume){
			if (!m_states.empty()){
				m_states.pop_back();
			}

			if (!m_states.empty()){
				this->m_states.back()->onResume();
			}

			m_resume = false;
		}

		if (!m_states.empty()){
			std::unique_ptr<State> temp = m_states.back()->Next();

			if (temp != nullptr){
				if (temp->IsReplacing())
					m_states.pop_back();
				else {
					this->m_states.back()->onPause();
				}

				m_states.push_back(std::move(temp));
			}
		}
	}

	void GameEngine::Update()
	{
		if (m_states.empty()) {
			this->Quit();
			return;
		}

		sf::Event event;

		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->Quit();
				break;
			case sf::Event::GainedFocus:
				m_window.SetWindowFocus(true);
				break;
			case sf::Event::LostFocus:
				m_window.SetWindowFocus(false);
				break;

			default:
				this->m_states.back()->onEvent(event);
				break;
			}
		}

		if (m_window.IsFocus()) {
			this->m_states.back()->onUpdate();
		}
	}

	void GameEngine::Draw()
	{
		if (m_states.empty()) {
			this->Quit();
			return;
		}

		this->m_states.back()->onDraw();
	}

	void GameEngine::Quit()
	{
		if (m_window.isOpen()) m_window.close();
	}
}