#pragma once

#include <vector>
#include <map>

#include "EntitySystemTypes.h"
#include "Entity.h"

class ComponentSystem;
class Component;

class EntityManager
{
public:
	EntityManager() {}
	EntityManager(const EntityManager&) = delete;
	EntityManager(const EntityManager&&) = delete;
	~EntityManager() {}

	bool onInit();
	void onUpdate(float dt);
	void CreateSystem();
	EntityId CreateEntity();
	void DestroyEntity(EntityId id);

private:
	using Entities = std::map<EntityId, Entity>;
	using Components = std::vector<std::vector<ComponentSystem*>>;
	using Systems = std::vector<ComponentSystem*>;

	Systems m_systems;
	Entities m_entities;
	Components m_components;
};

