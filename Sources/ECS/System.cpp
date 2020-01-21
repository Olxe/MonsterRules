#include "System.h"

System::System()
	: m_lastEntityID(INVALID_ENTITY_ID)
{
}

void System::onUpdate(const float& deltaTime)
{
	for (auto& e : m_entities) e->onUpdate(deltaTime);
}

void System::onDraw(sf::RenderWindow& window)
{
	for (auto& e : m_entities) e->onDraw(window);
}

void System::onRefresh()
{
	for (auto it = m_entities.begin(); it != m_entities.end();) {
		if (!(*it)->isActive()) {
			it = m_entities.erase(it);
		}
	}
}

Entity& System::Create()
{
	m_entities.push_back(std::unique_ptr<Entity>(new Entity(m_lastEntityID++, this)));
	return *m_entities.back().get();
}
