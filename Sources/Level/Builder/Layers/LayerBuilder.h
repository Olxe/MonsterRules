#pragma once

#include "../../Parser/Nodes/layernode.h"
#include "Layout.h"

namespace Builder
{
	class LayerBuilder: public Layout
	{
	public:
		LayerBuilder(Parser::LayerNode* layerNode, std::vector< Tile* >& tiles);
		~LayerBuilder();

	private:
		void fillLayoutFromCSV(const char* data, int widthGrid, std::vector<Tile*>& tiles);

	private:
		std::vector< std::vector< Tile* > > m_layout;

	};
}

