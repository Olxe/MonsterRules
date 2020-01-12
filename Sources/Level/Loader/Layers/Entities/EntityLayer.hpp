#pragma once

#include "../Layer.hpp"

#include "Heroes/Archer.h"
#include "Objects/Object.h"

namespace layer
{
	class EntityLayer: public Layer
	{
	public:
		EntityLayer();
		~EntityLayer();

		void onLoad(Builder::ObjectGroupBuilder* objGrp);
		void onUpdate(const float& deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;
		void onDebugDraw(sf::RenderWindow& window) override;

		entities::CEntity* getEntity(const std::string& name);

	private:
		std::unique_ptr<entities::PhysicalEntity> createEntity(Builder::SceneObject* sceneObj);

	private:
		std::vector< std::unique_ptr<entities::PhysicalEntity> > m_entities;

	};
}