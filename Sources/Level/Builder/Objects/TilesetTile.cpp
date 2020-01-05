#include "TilesetTile.h"

using namespace Builder;

TilesetTile::TilesetTile(int id, int gid, Parser::ImageNode* image, sf::Vector2f tileSize, sf::Vector2i tilesetPosition, std::string templateDirectory)
	: Tile(gid, nullptr, templateDirectory)
	, m_id(id)
	, m_image(image)
	, m_tilesetPosition(tilesetPosition)
	, m_tileSize(tileSize)
{
}

TilesetTile::~TilesetTile()
{
}

int Builder::TilesetTile::getId() const
{
	return m_id;
}

std::string Builder::TilesetTile::getSource() const
{
	if (m_image) {
		return m_templateDirectory + m_image->getSource();
	}

	return Tile::getSource();
}

sf::Vector2f Builder::TilesetTile::getSize() const
{
	return m_tileSize;
}
