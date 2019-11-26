#include "Layout.h"

using namespace Builder;

Layout::Layout()
{
}

Layout::~Layout()
{
}

Tile* Builder::Layout::getTileWithGid(const int gid, std::vector<Tile*>& tiles)
{
	for (auto tile : tiles) {
		if (tile->GetGid() == gid) return tile;
	}

	return nullptr;
}
