#include "Entity.h"
#include "Component.h"

Entity::Entity(EntityID id)
	: m_id(id)
	, m_active(true)
	, m_lastCompID(INVALID_COMPONENT_ID)
{
}

void Entity::onUpdate(const float& deltaTime)
{
	for (auto& c : m_components) c->onUpdate(deltaTime);
}

void Entity::onDraw(sf::RenderWindow& window)
{
	for (auto& c : m_components) c->onDraw(window);
}
