#include "WindowManager.h"

namespace Window
{
	WindowManager::WindowManager()
	{
		m_settings.SetSettings("Config/Settings");
		m_window.Create(m_settings);
		m_inputs.SetBinds(m_settings);
	}

	WindowManager::~WindowManager()
	{
	}

	void WindowManager::Update()
	{
		m_events.Update(&m_window);
		m_inputs.Update();

		if(m_events.IsEventTriggered(sf::Event::GainedFocus)) m_window.SetWindowFocus(true);
		if(m_events.IsEventTriggered(sf::Event::LostFocus)) m_window.SetWindowFocus(false);
	}
}