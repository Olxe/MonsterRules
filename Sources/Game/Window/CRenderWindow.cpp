#include "CRenderWindow.h"

using namespace Window;

CRenderWindow::CRenderWindow():
    isWindowFocus(true)
{
}

CRenderWindow::~CRenderWindow()
{
}

void CRenderWindow::Init()
{
    /*Settings::Init();
	this->create(sf::VideoMode(Settings::GetWindowSize().x, Settings::GetWindowSize().y), "MyFirstRealProject", sf::Style::Close);
	this->setFramerateLimit(Settings::GetFPS());*/
}

void CRenderWindow::SetFPS(unsigned int fps)
{
	//Settings::SetFPS(fps);

	//std::cout << Settings::GetFPS() << std::endl;
	//this->setFramerateLimit(Settings::GetFPS());
}

void CRenderWindow::Update()
{
    //EventManager::Update(this);
    //InputManager::Update();

    //if(EventManager::IsEventTriggered(sf::Event::GainedFocus)) isWindowFocus = true;
    //if(EventManager::IsEventTriggered(sf::Event::LostFocus)) isWindowFocus = false;
}

float CRenderWindow::DeltaTime()
{
    return m_clockDeltaTime.restart().asSeconds();
}

bool Window::CRenderWindow::WindowFocus()
{
	return isWindowFocus;
}