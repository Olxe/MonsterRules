#pragma once

#include "../Parser/Nodes/mapnode.h"
#include "TilesetBuilder.h"
#include "Layers/LayerBuilder.h"
#include "Layers/ObjectGroupBuilder.h"

namespace Builder
{
	class TiledBuilder
	{
	public:
		TiledBuilder();
		~TiledBuilder();

		std::vector< Layout* > Build(Parser::MapNode* map);

	private:
		std::vector< Tile* > m_tiles;
		std::vector< Layout* > m_layouts;
	};
}

