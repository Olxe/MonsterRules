#include "GameEngine.hpp"
#include "State.hpp"

namespace gameEngine
{
	GameEngine::GameEngine(sf::RenderWindow& window)
		: m_window(window)
		, m_running(false)
	{
	}

	GameEngine::~GameEngine()
	{
	}

	void GameEngine::Run(std::string name, std::unique_ptr<State> state)
	{
		m_running = true;
		m_states.push_back(std::pair<std::string, std::unique_ptr<State>>(name, std::move(state)));
	}

	void GameEngine::DeleteState(std::string name)
	{
		for (auto it = m_states.begin(); it != m_states.end();) {
			if (it->first == name) {
				it = m_states.erase(it);
			}
			else {
				++it;
			}
		}
	}

	void GameEngine::ResumeLastState()
	{
		m_resume = true;
	}
	
	void GameEngine::NextState()
	{
		if (m_resume)
		{
			if (!m_states.empty())
			{
				m_states.pop_back();
			}

			if (!m_states.empty())
			{
				this->m_states.back().second->onResume();
			}

			m_resume = false;
		}

		if (!m_states.empty())
		{
			std::pair<std::string, std::unique_ptr<State>> temp = m_states.back().second->Next();

			if (temp.second != nullptr)
			{
				if (temp.second->IsReplacing())
					m_states.pop_back();
				else {
					this->m_states.back().second->onPause();
				}

				m_states.push_back(std::move(temp));
			}
		}

		//if (state) {
		//	if (!m_states.empty()) {
		//		if (state->IsReplacing()) {
		//			m_states.pop_back();
		//		}
		//		else {
		//			this->m_states.back().second->onPause();
		//		}
		//	}
		//	m_running = true;
		//	m_states.push_back(std::pair<std::string, std::unique_ptr<State>>(name, std::move(state)));
		//}
		//else {
		//	this->Quit();
		//}
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
				this->m_states.back().second->onEvent(event);
				break;
			}
		}

		this->m_states.back().second->onUpdate();
	}

	void GameEngine::Draw()
	{
		this->m_states.back().second->onDraw();
	}
}