#pragma once

#include "Parser/TiledParser.h"
#include "Builder/TiledBuilder.h"

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

private:
	std::string m_directory;
	std::map< Level, std::string > m_levels;
	int m_currentLevel;
	
};

