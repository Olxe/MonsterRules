#pragma once

#include "../../Tools/Singleton.hpp"
#include "Settings.h"
#include "CRenderWindow.h"
#include "Inputmanager.h"

namespace Window
{
	class WindowManager: public Singleton< WindowManager >
	{
		friend class Singleton< WindowManager >;

	private:
		WindowManager();
		~WindowManager();

	public:
		void Update();

		CRenderWindow* GetWindow() { return &m_window; }
		Settings* GetSettings() { return &m_settings; }
		InputManager* GetInputs() { return &m_inputs; }

	private:
		CRenderWindow m_window;
		Settings m_settings;
		InputManager m_inputs;
	};
}