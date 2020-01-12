#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

bool Application::Init()
{
	return m_enitityManager.onInit();
}

void Application::Update(float dt)
{
	m_enitityManager.onUpdate(dt);
}