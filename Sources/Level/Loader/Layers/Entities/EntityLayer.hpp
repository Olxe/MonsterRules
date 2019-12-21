#pragma once

#include "../Layer.hpp"
#include "Entity.hpp"

#include "Heroes/Archer.h"

namespace layer
{
	class EntityLayer: public Layer
	{
	public:
		EntityLayer();
		~EntityLayer();

		void onLoad(Builder::ObjectGroupBuilder* objGrp, int& idObj);
		void onUpdate(const float& deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;

	private:
		std::unique_ptr<entities::Entity> createEntity(Builder::SceneObject* sceneObj, int& idObj);

	private:
		std::vector< std::unique_ptr<entities::Entity> > m_entities;

	};
}