#pragma once

#include "../Parser/Nodes/tilesetnode.h"
#include "Objects/TilesetTile.h"

#include "Objects/Shapes/Ellipse.h"
#include "Objects/Shapes/Point.h"
#include "Objects/Shapes/Polygone.h"
#include "Objects/Shapes/Polyline.h"

namespace Builder
{
	class TilesetBuilder
	{
	public:
		TilesetBuilder();
		~TilesetBuilder();

		std::vector< Tile* > Build(Parser::TilesetNode* tileset, std::string directory);

	private:
		void createTiles(Parser::TilesetNode* tileset, std::string directory, Parser::ImageNode* imageNode, std::vector< Tile* >& tiles);
		void updateTiles(Parser::TileNode* tileNode, std::vector< Tile* >& tiles);
		void createObject(Parser::ObjectNode* objectNode, Tile* tile);
	};
}

