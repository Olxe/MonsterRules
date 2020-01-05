#pragma once

#include "Layers/Tilemaps/TilemapLayer.hpp"
#include "Layers/Entities/EntityLayer.hpp"

namespace loader
{
	class TiledLoader
	{
	public:
		TiledLoader();
		~TiledLoader();

		std::vector< std::unique_ptr<layer::Layer> > Load(const std::vector<std::unique_ptr<Builder::Layout>>& layouts);
		
	};
}