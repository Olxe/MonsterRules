#pragma once

#include "../../Parser/Nodes/layernode.h"
#include "Layout.h"

namespace Builder
{
	class LayerBuilder: public Layout
	{
	public:
		LayerBuilder(Parser::LayerNode* layerNode, std::vector< Tile* >& tiles, float tileWidth, float tileHeight);
		~LayerBuilder();

		std::vector< Tile* > getLayout() const { return m_layout; }
		int getLayerWidth() const { return m_layerWidth; }
		int getLayerHeight() const { return m_layerHeight; }
		float getTileWidth() const { return m_tileWidth; }
		float getTileHeight() const { return m_tileHeight; }

	private:
		void fillLayoutFromCSV(const char* data, std::vector<Tile*>& tiles);

	private:
		std::vector< Tile* > m_layout;
		int m_layerWidth;
		int m_layerHeight;
		float m_tileWidth;
		float m_tileHeight;
	};
}

