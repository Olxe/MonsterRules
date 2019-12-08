#include "EntityLayer.hpp"

namespace layer
{
	EntityLayer::EntityLayer()
	{
	}

	EntityLayer::~EntityLayer()
	{
	}

	void EntityLayer::Load(Builder::ObjectGroupBuilder* objGrp, int& idObj)
	{
		for (auto obj : objGrp->getLayout()) {
			m_entities.push_back(std::make_unique<entities::Entity>(obj, idObj));
			idObj++;
		}
	}

	void EntityLayer::Update(const float& deltaTime)
	{
		for (auto& entity : m_entities) {
			entity->onUpdate(deltaTime);
		}
	}

	void EntityLayer::Draw(sf::RenderWindow& window)
	{
		for (auto& entity : m_entities) {
			entity->onDraw(window);
		}
	}
}