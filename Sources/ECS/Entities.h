#pragma once

#include <SFML/Graphics.hpp>

class Entities
{
public:
	Entities() {}
	~Entities() {}

	void onUpdate(const float& deltaTime)
	{
		for (auto& e : m_entities) e->onUpdate(deltaTime);
	}
	void onDraw(sf::RenderWindow& window)
	{
		for (auto& e : m_entities) e->onDraw(window);
	}

	void refresh()
	{
		for (auto it = m_entities.begin(); it != m_entities.end();) {
			if (!(*it)->isActive()) {
				it = m_entities.erase(it);
			}
		}
	}

	Entity& Create()
	{
		m_entities.push_back(std::make_unique<Entity>(new Entity()));
		return *m_entities.back().get();
	}

private:
	std::vector<std::unique_ptr<Entity>> m_entities;
};

