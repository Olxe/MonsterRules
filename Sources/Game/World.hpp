#pragma once

#include <SFML/Graphics.hpp>

#include "../Level/LevelManager.h"

class World
{
public:
	World();
	~World();

	void Update(const float& deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	LevelManager m_levelManager;

};

