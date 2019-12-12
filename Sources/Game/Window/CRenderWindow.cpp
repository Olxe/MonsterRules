#include "CRenderWindow.h"

namespace Window
{
	CRenderWindow::CRenderWindow() :
		m_focusing(true)
	{
	}

	CRenderWindow::~CRenderWindow()
	{
	}

	void Window::CRenderWindow::Create(Settings& settings)
	{
		SRenderWindow& srw = settings.GetRenderWindowSettings();
		sf::Uint32 style = sf::Style::Default;
		if (srw.fullscreen) {
			style = sf::Style::Fullscreen;
			srw.videoMode.width = sf::VideoMode::getDesktopMode().width;
			srw.videoMode.height = sf::VideoMode::getDesktopMode().height;
		}
		this->create(srw.videoMode, srw.title, style, srw.contextSettings);
		this->setFramerateLimit(srw.fps);
		this->setVerticalSyncEnabled(srw.verticalSync);
	}

	void CRenderWindow::SetWindowFocus(bool value)
	{
		m_focusing = value;
	}

	bool Window::CRenderWindow::IsFocus() const
	{
		return m_focusing;
	}
}