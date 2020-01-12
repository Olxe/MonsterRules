#pragma once

#include "../ECS/EntitySystems/EntityManager.h"

class Application
{
public:
	Application();
	~Application();

	bool Init();
	void Update(float dt);

private:
	EntityManager m_enitityManager;

};

