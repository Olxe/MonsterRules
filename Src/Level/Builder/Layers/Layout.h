#pragma once

#include "../Objects/Tile.h"

namespace Builder
{
	class Layout
	{
	public:
		Layout();
		virtual ~Layout();

	protected:
		Tile* getTileWithGid(const int gid, std::vector<Tile*>& tiles);

	private:

	};
}

