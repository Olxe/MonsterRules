#pragma once

#include <SFML/Graphics.hpp>
#include "../../../../Game/Window/AssetManager.hpp"
#include "../../../Builder/Objects/TilesetTile.h"

namespace layer
{
	class Tilemap: public sf::Drawable, public sf::Transformable
	{
	public:
		Tilemap(const std::string& source);
		~Tilemap();

		void AddTile(Builder::TilesetTile* tile);
		const std::string& getSource() const { return m_source; }
		bool Load(const sf::Vector2i& tilemapSize, const sf::Vector2f& tileSize);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Texture* m_texture;
		sf::VertexArray m_vertexArray;
		std::vector< Builder::TilesetTile* > m_tiles;
		std::string m_source;
	};
}