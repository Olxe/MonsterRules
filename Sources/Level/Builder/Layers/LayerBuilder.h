#pragma once

#include "../../Parser/Nodes/layernode.h"
#include "Layout.h"

namespace Builder
{
	class LayerBuilder: public Layout
	{
	public:
		LayerBuilder(Parser::LayerNode* layerNode, std::vector< Tile* >& tiles, sf::Vector2f tileSize);
		~LayerBuilder();

		std::vector< Tile* > getLayout() const { return m_layout; }
		sf::Vector2f getTileSize() const { return m_tileSize; }
		sf::Vector2i getLayerSize() const;

	private:
		void fillLayoutFromCSV(const char* data, std::vector<Tile*>& tiles);

	private:
		std::vector< Tile* > m_layout;
		Parser::LayerNode* m_layer;
		sf::Vector2f m_tileSize;
	};
}

