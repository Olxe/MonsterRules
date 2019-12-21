#include "LevelManager.h"

LevelManager::LevelManager()
	: m_directory("Resources/Maps/")
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
	Parser::TiledParser t_parser;
	Parser::MapNode* map = t_parser.ParseTMX(m_directory, m_levels[level]);

	Builder::TiledBuilder t_builder;
	std::vector< Builder::Layout* > layouts = t_builder.Build(map);

	loader::TiledLoader t_loader;
	m_layers = t_loader.Load(layouts);

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

void LevelManager::Update(const float& deltaTime)
{
	for (auto& it : m_layers) {
		it->onUpdate(deltaTime);
	}
}

void LevelManager::Draw(sf::RenderWindow& window)
{
	for (auto& it : m_layers) {
		it->onDraw(window);
	}
}
