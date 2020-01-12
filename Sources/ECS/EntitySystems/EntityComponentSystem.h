#pragma once

#include <vector>

#include "BaseComponentSystem.h"

template <typename... Cmps>
class ComponentSystem : public BaseComponentSystem
{
public:
	explicit ComponentSystem(EntityManager* entityManager);
	virtual ~ComponentSystem() = default;
	
	virtual bool Init() = 0;
	virtual void onUpdate(float dt) = 0;

protected:
	std::vector<Cmps> m_components;
};

template <typename... Cmps>
ComponentSystem<Cmps...>::ComponentSystem(EntityManager* entityManager) : BaseComponentSystem(entityManager)
{
	m_components.emplace_back(Cmps...);
}