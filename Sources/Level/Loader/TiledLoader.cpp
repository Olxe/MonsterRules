#include "TiledLoader.hpp"

namespace loader
{
	TiledLoader::TiledLoader()
	{
	}

	TiledLoader::~TiledLoader()
	{
	}

	std::vector< std::unique_ptr<layer::Layer> > TiledLoader::Load(std::vector<Builder::Layout*> layouts)
	{
		std::vector< std::unique_ptr<layer::Layer> > layers;

		int idObj = 1;
		for (auto it : layouts) {
			if (Builder::LayerBuilder* layer = dynamic_cast<Builder::LayerBuilder*>(it)) {
				
				std::unique_ptr< layer::TilemapLayer > obj = std::make_unique< layer::TilemapLayer >();
				obj->Load(layer);
				layers.push_back(std::move(obj));
			}
			else if (Builder::ObjectGroupBuilder* objGrp = dynamic_cast<Builder::ObjectGroupBuilder*>(it)) {
				std::unique_ptr< layer::EntityLayer > obj = std::make_unique< layer::EntityLayer >();
				obj->Load(objGrp, idObj);
				layers.push_back(std::move(obj));
			}
		}

		return std::move(layers);
	}
}