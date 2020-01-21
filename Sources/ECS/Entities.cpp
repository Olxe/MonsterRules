#include "Entities.h"
#include "Entity.h"
Entities::Entities()
	: m_lastEntityID(INVALID_ENTITY_ID)
{
}

void Entities::onUpdate(const float& deltaTime)
{
	for (auto& e : m_entities) e->onUpdate(deltaTime);
}

void Entities::onDraw(sf::RenderWindow& window)
{
	for (auto& e : m_entities) e->onDraw(window);
}

void Entities::onRefresh()
{
	for (auto it = m_entities.begin(); it != m_entities.end();) {
		if (!(*it)->isActive()) {
			it = m_entities.erase(it);
		}
	}
}

Entity& Entities::Create()
{
	m_entities.push_back(std::unique_ptr<Entity>(new Entity(m_lastEntityID++)));
	return *m_entities.back().get();
}
