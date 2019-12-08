#pragma once

#include "../Layer.hpp"
#include "Entity.hpp"

namespace layer
{
	class EntityLayer: public Layer
	{
	public:
		EntityLayer();
		~EntityLayer();

		void Load(Builder::ObjectGroupBuilder* objGrp, int& idObj);
		void Update(const float& deltaTime) override;
		void Draw(sf::RenderWindow& window) override;

	private:
		std::vector< std::unique_ptr<entities::Entity> > m_entities;

	};
}