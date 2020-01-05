#pragma once

#include "../Game/Window/CRenderWindow.h"

#include "Parser/TiledParser.h"
#include "Builder/TiledBuilder.h"
#include "Loader/TiledLoader.hpp"

#include "Loader/Layers/Entities/Physic/MyContactListenner.h"
#include "Loader/Layers/Entities/Physic/Box2DWorld.h"

enum class Level
{
	LEVEL_1,
	LEVEL_2,
	LEVEL_3,
	LEVEL_4,
	LEVEL_5
};

class LevelManager
{
public:
	LevelManager();
	~LevelManager();

	void LoadLevel(Level level);
	void NextLevel();
	void PreviousLevel();

	void Update(const float& deltaTime);
	void Draw(Window::CRenderWindow& window);

private:
	std::string m_directory;
	std::map< Level, std::string > m_levels;
	int m_currentLevel;
	std::vector< std::unique_ptr<layer::Layer> > m_layers;
	MyContactListenner m_contactListenner;
	bool isDebugActivate;
};

