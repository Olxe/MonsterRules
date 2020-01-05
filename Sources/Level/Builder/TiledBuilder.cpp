#include "TiledBuilder.h"

namespace Builder
{
	TiledBuilder::TiledBuilder()
	{
	}

	TiledBuilder::~TiledBuilder()
	{
		clearVector(m_tiles);
	}

	std::vector<std::unique_ptr<Layout>> Builder::TiledBuilder::Build(Parser::MapNode* map)
	{
		if (map) {
			std::vector<std::unique_ptr<Layout>> layouts;
			clearVector(m_tiles);

			for (auto map_child_node : map->GetChildNodes()) {
				if (const Parser::TilesetNode* tilesetNode = dynamic_cast<const Parser::TilesetNode*>(map_child_node)) {
					TilesetBuilder tilesetBuilder;
					std::vector< Tile* > tiles = tilesetBuilder.Build(tilesetNode, map->GetDirectory());
					m_tiles.insert(m_tiles.end(), tiles.begin(), tiles.end());
				}
				else if (Parser::LayerNode* layerNode = dynamic_cast<Parser::LayerNode*>(map_child_node)) {
					layouts.push_back(std::unique_ptr<Layout>(new LayerBuilder(layerNode, m_tiles, sf::Vector2f(map->GetTilewidth(), map->GetTileheight()))));
				}
				if (Parser::ObjectGroupNode* objectGroup = dynamic_cast<Parser::ObjectGroupNode*>(map_child_node)) {
					layouts.push_back(std::unique_ptr<Layout>(new ObjectGroupBuilder(objectGroup, m_tiles)));
				}
			}

			return layouts;
		}
		else {
			Out("Error : ", "No map");
		}

		return std::vector<std::unique_ptr<Layout>>();
	}
}