#include "EntityLayer.hpp"

namespace layer
{
	EntityLayer::EntityLayer()
	{
	}

	EntityLayer::~EntityLayer()
	{
	}

	void EntityLayer::onLoad(Builder::ObjectGroupBuilder* objGrp, int& idObj)
	{
		for (auto obj : objGrp->getLayout()) {
			if (Builder::SceneObject* sceneObj = dynamic_cast<Builder::SceneObject*>(obj)) {
				m_entities.push_back(this->createEntity(sceneObj, idObj));
				idObj++;
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

	std::unique_ptr<entities::Entity> EntityLayer::createEntity(Builder::SceneObject* sceneObj, int& idObj)
	{
		std::string type = sceneObj->GetTile()->GetType();

		if (type == "HERO_ARCHER") {
			return std::unique_ptr<entities::Archer>(new entities::Archer(sceneObj, idObj));
		}

		return std::unique_ptr<entities::Entity>(new entities::Entity(sceneObj, idObj));
	}
}