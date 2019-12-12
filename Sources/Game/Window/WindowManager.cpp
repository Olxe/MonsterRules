#include "WindowManager.hpp"

namespace Window
{
	WindowManager::WindowManager()
	{
		m_settings.SetSettings("Config/Settings");
		m_window.Create(m_settings);
		m_inputs.SetBinds(m_settings);


		m_view.reset(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f((float)m_window.getSize().x, (float)m_window.getSize().y)));

		m_view.zoom(1920.f / (float)m_window.getSize().x);
		//m_view.setCenter(0, 0);
		//updateView();
	}

	WindowManager::~WindowManager()
	{
	}

	void WindowManager::Update()
	{
		m_window.setView(m_view);
		m_inputs.Update();
	}

	void WindowManager::updateView()
	{
		float newAspectWidth = (float)m_window.getSize().x;
		float newAspectHeight = (float)m_window.getSize().y;

		if (newAspectWidth != m_currentAspectWidth) {
			m_currentAspectWidth = newAspectWidth;
			m_currentAspectHeight = m_currentAspectWidth / (4.f/3.f);
		}
		else if (newAspectHeight != m_currentAspectHeight) {
			m_currentAspectHeight = newAspectHeight;
			m_currentAspectWidth = m_currentAspectHeight * (4.f / 3.f);
		}

		m_view.reset(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(m_currentAspectWidth, m_currentAspectWidth)));
	}
}