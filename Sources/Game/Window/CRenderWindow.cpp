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

		m_gameView.reset(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f((float)this->getSize().x, (float)this->getSize().y)));
		m_gameView.zoom(1920.f / (float)this->getSize().x);
		//m_gameView.reset(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(1920, 1080)));
	}

	void CRenderWindow::SetWindowFocus(bool value)
	{
		m_focusing = value;
	}

	bool Window::CRenderWindow::IsFocus() const
	{
		return m_focusing;
	}

	void CRenderWindow::setDefaultView()
	{
		this->setView(this->getDefaultView());
	}

	void CRenderWindow::setGameView()
	{
		this->setView(m_gameView);
	}

	sf::Vector2f CRenderWindow::getMousePosition()
	{
		return this->mapPixelToCoords(sf::Mouse::getPosition(*this));
	}
}