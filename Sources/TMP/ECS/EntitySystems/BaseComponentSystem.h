#pragma once

class Entity;
class EntityManager;

class BaseComponentSystem
{
public:
	explicit BaseComponentSystem(EntityManager* entityManager) : m_entityManager(entityManager) { }
	virtual ~BaseComponentSystem() = default;

	virtual void onEntityCreated(const Entity& entity) = 0;
	virtual void onEntityDestroyed(const Entity& entity) = 0;

protected:
	EntityManager* m_entityManager;
};

