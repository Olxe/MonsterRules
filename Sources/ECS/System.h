#pragma once

#include <SFML/Graphics.hpp>

#include "SystemTypes.h"
#include "Entity.h"

class System
{
public:
	System();
	~System() = default;

	void onUpdate(const float& deltaTime);

	void onDraw(sf::RenderWindow& window);

	void onRefresh();

	Entity& Create();

private:
	std::vector<std::unique_ptr<Entity>> m_entities;
	EntityID m_lastEntityID;
};

