#pragma once

#include <limits>

#include "EntitySystemTypes.h"

class EntityComponent
{
public:
	EntityComponent() : m_entityId(INVALID_ENTITY_ID), m_poolIndex(INVALID_POOL_INDEX) {}
	virtual ~EntityComponent() = default;

	virtual bool onInit(void* data) = 0;

	void setEntityId(EntityId id) { m_entityId = id; }
	EntityId getEntityId() const { return m_entityId; }
	void setPoolIndex(size_t index) { m_poolIndex = index; }
	size_t getPoolIndex() const { return m_poolIndex; }

private:
	static constexpr size_t INVALID_POOL_INDEX = std::numeric_limits<size_t>::max();
	EntityId m_entityId;
	size_t m_poolIndex;
};

