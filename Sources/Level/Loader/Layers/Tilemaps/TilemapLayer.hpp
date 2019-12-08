#pragma once

#include "../Layer.hpp"
#include "Tilemap.hpp"

namespace layer
{
	class TilemapLayer: public Layer
	{
	public:
		TilemapLayer();
		~TilemapLayer();

		void Load(Builder::LayerBuilder* layer);
		void Update(const float& deltaTime) override;
		void Draw(sf::RenderWindow& window) override;

	private:
		std::vector< std::unique_ptr<layer::Tilemap> > m_tilemaps;
	};
}