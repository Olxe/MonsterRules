#pragma once

//typedef size_t EntityId;
//constexpr EntityId INVALID_ENTITY_ID = 0;
//
//typedef size_t ComponentID;
//constexpr ComponentID INVALID_COMPONENT_ID = 0;
//
//constexpr size_t maxComponents = 32;
//
//typedef std::bitset<maxComponents> ComponentBitset;
//typedef std::array<Component*, maxComponents> ComponentArray;

//inline ComponentID getComponentID()
//{
//	static ComponentID lastID = 0;
//	std::cout << lastID << std::endl;
//	return lastID++;
//}
//
//template <typename T>
//inline ComponentID getComponentID() noexcept
//{
//	static ComponentID typeID = getComponentID();
//	std::cout << lastID << std::endl;
//	return typeID();
//}

#include "SystemTypes.h"

class Entity;

class Component
{
public:
	explicit Component(ComponentID id, Entity* entity = nullptr);
	virtual ~Component() = default;

	void setEntity(Entity* entity) { m_entity = entity; }

	virtual void onInit() { }
	virtual void onUpdate(const float& deltaTime) { }
	virtual void onDraw(sf::RenderWindow& window) { }

private:
	ComponentID m_id;
	Entity* m_entity;

};


