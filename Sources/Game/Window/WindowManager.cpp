#include "WindowManager.hpp"

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
		m_inputs.Update();
	}
}