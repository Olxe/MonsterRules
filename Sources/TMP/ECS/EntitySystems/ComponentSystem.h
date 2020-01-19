#pragma once

#include <vector>

#include "BaseComponentSystem.h"
#include "Entity.h"

template <typename... Cmps>
class ComponentSystem : public BaseComponentSystem
{
public:
	explicit ComponentSystem(EntityManager* entityManager) : BaseComponentSystem(entityManager) { }
	virtual ~ComponentSystem() = default;
	
	void onEntityCreated(const Entity& entity) override final;
	void onEntityDestroyed(const Entity& entity) override final;

protected:
	std::vector<Cmps> m_components;
};

//template <typename... Cmps>
//ComponentSystem<Cmps...>::ComponentSystem(EntityManager* entityManager) : BaseComponentSystem(entityManager)
//{
//	m_components.emplace_back(Cmps...);
//}

template<typename ...Cmps>
void ComponentSystem<Cmps...>::onEntityCreated(const Entity& entity)
{

}
