#include "LevelManager.h"

LevelManager::LevelManager()
	: m_directory("D:/bugno/Documents/Programming/Projects/Finish_it!/Finish_it!/Res/Maps/")
	, m_currentLevel(-1)
{
	m_levels[Level::LEVEL_1] = "level_1.tmx";
	m_levels[Level::LEVEL_2] = "level_2.tmx";
	m_levels[Level::LEVEL_3] = "level_3.tmx";
	m_levels[Level::LEVEL_4] = "level_4.tmx";
	m_levels[Level::LEVEL_5] = "level_5.tmx";
}

LevelManager::~LevelManager()
{
}

void LevelManager::LoadLevel(Level level)
{
	Parser::TiledParser parser;
	Parser::MapNode* map = parser.ParseTMX(m_directory, m_levels[level]);

	Builder::TiledBuilder builder;
	std::vector< Builder::Layout* > layouts = builder.Build(map);

	m_currentLevel = static_cast<int>(level);
}

void LevelManager::NextLevel()
{
	this->LoadLevel(static_cast<Level>(m_currentLevel + 1));
}

void LevelManager::PreviousLevel()
{
	this->LoadLevel(static_cast<Level>(m_currentLevel - 1));
}
