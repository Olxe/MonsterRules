#include "Tilemap.hpp"

namespace layer
{
	Tilemap::Tilemap(const std::string& source)
		: m_texture(nullptr)
		, m_source(source)
	{
	}

	Tilemap::~Tilemap()
	{
	}

	void Tilemap::AddTile(Builder::TilesetTile* tile)
	{
		if (tile && tile->GetSource() == m_source) {
			m_tiles.push_back(tile);
		}
		else {
			m_tiles.push_back(nullptr);
		}
	}

	bool Tilemap::Load(const sf::Vector2i& tilemapSize, const sf::Vector2f& tileSize)
	{
		m_texture = AssetManager::Instance()->GetTexture(m_source);
		if (!m_texture) return false;
		m_vertexArray.setPrimitiveType(sf::Quads);
		m_vertexArray.resize(tilemapSize.x * tilemapSize.y * 4);

		for (int i = 0; i < tilemapSize.x; ++i)
		{
			for (int j = 0; j < tilemapSize.y; ++j)
			{
				if (i + j * tilemapSize.x >= (int)m_tiles.size()) return false;

				const Builder::TilesetTile* tile = m_tiles[i + j * tilemapSize.x];
	
				if (tile)
				{
					//Ptr to quad (future tile)
					sf::Vertex* quad = &m_vertexArray[(i + j * tilemapSize.x) * 4];

					//Pos of the tile
					quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
					quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
					quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
					quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

					//Margin of the m_texture trim (avoid bug display)
					float texMargin = 0.0f;

					//Pos in tileset
					int column = tile->getTilesetPosX();
					int row = tile->getTilesetPosY();

					//Tile coordinated in the tileset m_texture
					quad[0].texCoords = sf::Vector2f(column * tileSize.x + texMargin, row * tileSize.y + texMargin);
					quad[1].texCoords = sf::Vector2f((column + 1) * tileSize.x - texMargin, row * tileSize.y + texMargin);
					quad[2].texCoords = sf::Vector2f((column + 1) * tileSize.x - texMargin, (row + 1) * tileSize.y - texMargin);
					quad[3].texCoords = sf::Vector2f(column * tileSize.x + texMargin, (row + 1) * tileSize.y - texMargin);
				}
			}
		}

		m_tiles.clear();
		return true;
	}

	void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (m_texture) {
			states.transform *= getTransform();
			states.texture = m_texture;
			target.draw(m_vertexArray, states);
		}
	}
}