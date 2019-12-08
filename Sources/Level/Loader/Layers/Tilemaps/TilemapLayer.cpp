#include "TilemapLayer.hpp"

namespace layer
{
	TilemapLayer::TilemapLayer()
	{
	}

	TilemapLayer::~TilemapLayer()
	{
	}
	void TilemapLayer::Load(Builder::LayerBuilder* layer)
	{
		//build tilemap
		for (auto tile : layer->getLayout()) {
			if (Builder::TilesetTile* tilesetTile = dynamic_cast<Builder::TilesetTile*>(tile)) {
				bool tilemapFound = false;
				for (auto& tilemap : m_tilemaps) {
					if (tilemap->getSource() == tilesetTile->GetSource()) {
						tilemapFound = true;
					}
				}
				if (!tilemapFound) {
					m_tilemaps.push_back(std::make_unique<layer::Tilemap>(tilesetTile->GetSource()));
				}
			}
		}

		//fill tilemap
		for (auto& tilemap : m_tilemaps) {
			for (auto tile : layer->getLayout()) {
				if (Builder::TilesetTile* tilesetTile = dynamic_cast<Builder::TilesetTile*>(tile)) {
					tilemap->AddTile(tilesetTile);
				}
				else tilemap->AddTile(nullptr);
			}
		}

		//load tilemap
		for (auto& tilemap : m_tilemaps) {
			tilemap->Load(sf::Vector2i(layer->getLayerWidth(), layer->getLayerHeight()), sf::Vector2f(layer->getTileWidth(), layer->getTileHeight()));
		}
	}

	void TilemapLayer::Update(const float& deltaTime)
	{
	}

	void TilemapLayer::Draw(sf::RenderWindow& window)
	{
		for (auto& it : m_tilemaps) {
			window.draw(*it);
		}
	}
}