#include "TilemapLayer.hpp"

namespace layer
{
	TilemapLayer::TilemapLayer()
	{
	}

	TilemapLayer::~TilemapLayer()
	{
	}
	void TilemapLayer::onLoad(Builder::LayerBuilder* layer)
	{
		//build tilemap
		for (auto tile : layer->getLayout()) {
			if (Builder::TilesetTile* tilesetTile = dynamic_cast<Builder::TilesetTile*>(tile)) {
				bool tilemapFound = false;
				for (auto& tilemap : m_tilemaps) {
					if (tilemap->getSource() == tilesetTile->getSource()) {
						tilemapFound = true;
					}
				}
				if (!tilemapFound) {
					m_tilemaps.push_back(std::make_unique<layer::Tilemap>(tilesetTile->getSource()));
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
			tilemap->Load(layer->getLayerSize(), layer->getTileSize());
		}
	}

	void TilemapLayer::onUpdate(const float& deltaTime)
	{
	}

	void TilemapLayer::onDraw(sf::RenderWindow& window)
	{
		for (auto& it : m_tilemaps) {
			window.draw(*it);
		}
	}

	void TilemapLayer::onDebugDraw(sf::RenderWindow& window)
	{
	}
}