#include "TiledBuilder.h"

using namespace Builder;

TiledBuilder::TiledBuilder()
{
}

TiledBuilder::~TiledBuilder()
{
	clearVector(m_layouts);
	clearVector(m_tiles);
}

std::vector< Layout* > Builder::TiledBuilder::Build(Parser::MapNode* map)
{
	if (map) {
		clearVector(m_layouts);
		clearVector(m_tiles);

		for (auto map_child_node : map->GetChildNodes()) {
			if (Parser::TilesetNode* tilesetNode = dynamic_cast<Parser::TilesetNode*>(map_child_node)) {
				TilesetBuilder tilesetBuilder;
				std::vector< Tile* > tiles = tilesetBuilder.Build(tilesetNode, map->GetDirectory());
				m_tiles.insert(m_tiles.end(), tiles.begin(), tiles.end());
			}
			else if (Parser::LayerNode* layerNode = dynamic_cast<Parser::LayerNode*>(map_child_node)) {
				m_layouts.push_back(new LayerBuilder(layerNode, m_tiles, map->GetTilewidth(), map->GetTileheight()));
			}
			if (Parser::ObjectGroupNode* objectGroup = dynamic_cast<Parser::ObjectGroupNode*>(map_child_node)) {
				m_layouts.push_back(new ObjectGroupBuilder(objectGroup, m_tiles));
			}
		}
	}
	else {
		Out("Error : ", "No map");
	}

	return m_layouts;
}