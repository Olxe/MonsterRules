#pragma once

#include "Tile.h"

namespace Builder
{
	class TilesetTile: public Tile
	{
	public:
		TilesetTile(int id, int gid, Parser::ImageNode* image, sf::Vector2f tileSize, sf::Vector2i tilesetPosition, std::string templateDirectory);
		~TilesetTile();

		int getId() const override;
		std::string getSource() const override;
		sf::Vector2f getSize() const override;

		const sf::Vector2i getTilesetPosition() const { return m_tilesetPosition; }

	private:
		int m_id;
		Parser::ImageNode* m_image;
		sf::Vector2i m_tilesetPosition;
		sf::Vector2f m_tileSize;
	};
}
