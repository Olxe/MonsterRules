#include "Entity.h"
#include "Component.h"

Entity::Entity(EntityID id)
	: m_id(id)
	, m_active(true)
{
}

void Entity::onUpdate(const float& deltaTime)
{
	for (auto c = m_components.begin(); c != m_components.end(); ++c) {
		c->second->onUpdate(deltaTime);
	}
}

void Entity::onDraw(sf::RenderWindow& window)
{
	for (auto c = m_components.begin(); c != m_components.end(); ++c) {
		c->second->onDraw(window);
	}
}
