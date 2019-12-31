#include "EntityLayer.hpp"

namespace layer
{
	EntityLayer::EntityLayer()
	{
	}

	EntityLayer::~EntityLayer()
	{
	}

	void EntityLayer::onLoad(Builder::ObjectGroupBuilder* objGrp)
	{
		for (auto obj : objGrp->getLayout()) {
			if (Builder::SceneObject* sceneObj = dynamic_cast<Builder::SceneObject*>(obj)) {
				if (sceneObj->GetTile()) {
					m_entities.push_back(this->createEntity(sceneObj));
				}
				else Out("Error : ", "Scene object has not tile");
			}
			else {
				Out("test");
			}
		}
	}

	void EntityLayer::onUpdate(const float& deltaTime)
	{
		for (auto& entity : m_entities) {
			entity->onUpdate(deltaTime);
		}
	}

	void EntityLayer::onDraw(sf::RenderWindow& window)
	{
		for (auto& entity : m_entities) {
			entity->onDraw(window);
		}
	}

	entities::Entity* EntityLayer::getEntity(const std::string& name)
	{
		for (auto& entity : m_entities) {
			if (entity->getName() == name) {
				return entity.get();
			}
		}
		return nullptr;
	}

	std::unique_ptr<entities::PhysicalEntity> EntityLayer::createEntity(Builder::SceneObject* sceneObj)
	{
		std::string type = sceneObj->GetTile()->GetType();

		if (type == "HERO_ARCHER") {
			sceneObj->GetTile()->setSource("Resources/Textures/Characters/Heroes/Hero_2/archer.png");
			sceneObj->GetTile()->setSize(117, 78);
			return std::unique_ptr<entities::Archer>(new entities::Archer(sceneObj));
		}

		return std::unique_ptr<entities::PhysicalEntity>(new entities::Object(sceneObj));
	}
}