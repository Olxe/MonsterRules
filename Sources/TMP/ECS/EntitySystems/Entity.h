#include "..\..\..\ECS\Entity.h"
#pragma once

#include <map>

#include "EntitySystemTypes.h"

class EntityComponent;

class Entity
{
public:
	explicit Entity(EntityId id) : m_id(id) {}
	~Entity() = default;
	EntityId getId() const { return m_id; }

	template <typename CmpType>
	CmpType* getComponent() const
	{
		auto cmp = m_components.find(CmpType::ID);
		if (cmp != m_components.end()) {
			return cmp->second();
		}
		return nullptr;
	}

private:
	EntityId m_id;
	//std::map<EntityComponentId, EntityComponent*> m_components;
	std::map<int, EntityComponent*> m_components;

};

