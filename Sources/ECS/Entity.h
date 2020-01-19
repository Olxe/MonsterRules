#pragma once

#include "SystemTypes.h"

class Component;

class Entity
{
public:
	explicit Entity(EntityID id);
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
	T* AddComponent(TArgs&&... args);

private:
	EntityID m_id;
	bool m_active;
	std::map<ComponentID, std::unique_ptr<Component>> m_components;
	//std::vector<std::unique_ptr<Component>> m_components;//?
};

template<typename T>
inline T* Entity::getComponent() const
{
	for (auto c = m_components.begin(); c != m_components.end(); ++c) {
		if (T* c_return = dynamic_cast<T*>(c->second.get())) {
			return c_return;
		}
	}
	return nullptr;
}

template<typename T>
inline bool Entity::HasComponent() const
{
	if (getComponent<T>()) {
		return true;
	}
	return false;
}

template<typename T, typename ...TArgs>
inline T* Entity::AddComponent(TArgs&& ...args)
{
	T* c = new T(std::forward<TArgs>(args)...);
	c->setEntity(this);
	c->Init();
	m_components.push_back(std::make_unique<Component>(c));

	return c;
}
