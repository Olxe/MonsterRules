#include "World.hpp"

World::World()
{
	int cpt = 100000;
	while (cpt > 0) {

		m_levelManager.LoadLevel(Level::LEVEL_1);

		cpt--;
		std::cout << cpt << std::endl;
	}
	
}

World::~World()
{
}

void World::Update(const float& deltaTime)
{
	m_levelManager.Update(deltaTime);
}

void World::Draw(Window::CRenderWindow& window)
{
	m_levelManager.Draw(window);
}
