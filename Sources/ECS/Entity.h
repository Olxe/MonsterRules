#pragma once

#include "Component.h"

class System;

class Entity
{
public:
	Entity(EntityID id, System* system = nullptr);
	~Entity() = default;

	EntityID getID() const { return m_id; }
	bool isActive() const { return m_active; }

	virtual void onUpdate(const float& deltaTime);
	virtual void onDraw(sf::RenderWindow& window);

	template <typename T> 
	T* getComponent() const;

	template <typename T>
	bool HasComponent() const;

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args);

private:
	EntityID m_id;
	bool m_active;
	std::vector<std::unique_ptr<Component>> m_components;
	ComponentID m_lastCompID;
	System* m_system;
};

template <typename T>
inline T* Entity::getComponent() const
{
	for (auto& c : m_components) {
		if (T* c_return = dynamic_cast<T*>(c.get())) {
			return c_return;
		}
	}
	return nullptr;
}

template <typename T>
inline bool Entity::HasComponent() const
{
	if (this->getComponent<T>()) {
		return true;
	}
	return false;
}

template <typename T, typename ...TArgs>
inline T& Entity::AddComponent(TArgs&& ...args)
{
	T* c = new T(m_lastCompID++, std::forward<TArgs>(args)...);
	c->setEntity(this);
	c->Init();
	m_components.push_back(std::unique_ptr<Component>(c));

	return *c;
}
