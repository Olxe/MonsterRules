#pragma once

#include <SFML/Graphics.hpp>

#include "../Level/LevelManager.h"

class World
{
public:
	World();
	~World();

	void Update(const float& deltaTime);
	void Draw(Window::CRenderWindow& window);

private:
	LevelManager m_levelManager;

};

