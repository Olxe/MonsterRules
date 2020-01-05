#pragma once

#include "../Parser/Nodes/tilesetnode.h"
#include "Objects/TilesetTile.h"

#include "Objects/Shapes/Ellipse.h"
#include "Objects/Shapes/Point.h"
#include "Objects/Shapes/Polygone.h"

namespace Builder
{
	class TilesetBuilder
	{
	public:
		TilesetBuilder();
		~TilesetBuilder();

		std::vector< Tile* > Build(const Parser::TilesetNode* tileset, std::string directory);

	private:
		void createTiles(const Parser::TilesetNode* tileset, std::string templateDirectory, Parser::ImageNode* imageNode, std::vector< Tile* >& tiles);
		void updateTiles(Parser::TileNode* tileNode, std::vector< Tile* >& tiles);
		//void createObject(const Parser::ObjectNode* objectNode, Tile* tile);
	};
}

