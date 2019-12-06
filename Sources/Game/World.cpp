#include "World.hpp"

World::World()
{
	m_levelManager.LoadLevel(Level::LEVEL_1);
}

World::~World()
{
}

void World::Update(const float& deltaTime)
{
}

void World::Draw(sf::RenderWindow& window)
{
	
}
