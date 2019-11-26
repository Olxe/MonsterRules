#include "TilesetTile.h"

using namespace Builder;

TilesetTile::TilesetTile(int id, int gid, std::string source, float width, float height, int tilesetPosX, int tilesetPosY)
	: Tile(id, gid, source, width, height)
	, m_tilesetPosX(tilesetPosX)
	, m_tilesetPosY(tilesetPosY)
{
}

TilesetTile::~TilesetTile()
{
}