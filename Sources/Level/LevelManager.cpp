#include "LevelManager.h"

LevelManager::LevelManager()
	: m_directory("Resources/Maps/")
	, m_currentLevel(-1)
	, isDebugActivate(true)
{
	m_levels[Level::LEVEL_1] = "level_1.tmx";
	m_levels[Level::LEVEL_2] = "level_2.tmx";
	m_levels[Level::LEVEL_3] = "level_3.tmx";
	m_levels[Level::LEVEL_4] = "level_4.tmx";
	m_levels[Level::LEVEL_5] = "level_5.tmx";

	Box2DWorld::Instance()->getWorld()->SetContactListener(&m_contactListenner);
}

LevelManager::~LevelManager()
{
	m_layers.clear();
	Box2DWorld::Instance()->DeleteInstance();
}

void LevelManager::LoadLevel(Level level)
{
	Parser::TiledParser t_parser;
	Parser::MapNode* map = t_parser.ParseTMX(m_directory, m_levels[level]);

	Builder::TiledBuilder t_builder;
	std::vector<std::unique_ptr<Builder::Layout>> layouts = t_builder.Build(map);

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
	Window::WindowManager::Instance()->GetWindow()->setGameView();

	for (auto& it : m_layers) {
		it->onUpdate(deltaTime);
	}

	Box2DWorld::Instance()->getWorld()->Step(1 / 60.f, 8, 3);
}

void LevelManager::Draw(sf::RenderWindow& window)
{
	for (auto& it : m_layers) {
		if (layer::EntityLayer* entity = dynamic_cast<layer::EntityLayer*>(it.get())) {
			if (entities::CEntity* mainPlayer = entity->getEntity("MAIN_PLAYER")) {
				//window.getGameView().setCenter(mainPlayer->getPosition());
			}
		}
	}

	//window.setGameView();

	for (auto& it : m_layers) {
		it->onDraw(window);
	}

	if (isDebugActivate) {
		for (auto& it : m_layers) {
			it->onDebugDraw(window);
		}
	}
}
