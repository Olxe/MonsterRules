#include "CRenderWindow.h"

namespace Window
{
	CRenderWindow::CRenderWindow() :
		isWindowFocus(true)
	{
	}

	CRenderWindow::~CRenderWindow()
	{
	}

	void Window::CRenderWindow::Create(Settings& settings)
	{
		const SRenderWindow& srw = settings.GetRenderWindowSettings();
		this->create(srw.videoMode, srw.title, srw.style, srw.contextSettings);
		this->setFramerateLimit(srw.fps);
		this->setVerticalSyncEnabled(srw.verticalSync);
	}

	void CRenderWindow::SetWindowFocus(bool value)
	{
		isWindowFocus = value;
	}

	bool Window::CRenderWindow::WindowFocus() const
	{
		return isWindowFocus;
	}
}