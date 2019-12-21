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

		void onLoad(Builder::LayerBuilder* layer);
		void onUpdate(const float& deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;

	private:
		std::vector< std::unique_ptr<layer::Tilemap> > m_tilemaps;
	};
}