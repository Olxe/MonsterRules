#pragma once

#include "SystemTypes.h"

class Entity;

class Component
{
public:
	explicit Component(ComponentID id, Entity* entity = nullptr);
	virtual ~Component() = default;

	ComponentID getID() const { return m_id; }
	void setEntity(Entity* entity) { m_entity = entity; }

	virtual void onInit() { }
	virtual void onUpdate(const float& deltaTime) { }
	virtual void onDraw(sf::RenderWindow& window) { }

private:
	ComponentID m_id;
	Entity* m_entity;

};


