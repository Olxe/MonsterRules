#pragma once

#include "Tile.h"

namespace Builder
{
	class TilesetTile: public Tile
	{
	public:
		TilesetTile(int id, int gid, std::string source, float width, float height, int tilesetPosX, int tilesetPosY);
		~TilesetTile();

	private:
		int m_tilesetPosX;
		int m_tilesetPosY;
	};
}
