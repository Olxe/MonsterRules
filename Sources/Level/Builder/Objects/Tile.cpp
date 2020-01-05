#include "Tile.h"

using namespace Builder;

Tile::Tile(int gid, Parser::TileNode* tile, std::string templateDirectory)
	: m_gid(gid)
	, m_tile(tile)
	, m_templateDirectory(templateDirectory)
	, m_size(sf::Vector2f(-1, -1))
{
}

Tile::~Tile()
{
}

std::string Builder::Tile::getType() const
{
	if (m_tile) {
		return m_tile->GetType();
	}
	return std::string();
}

Parser::PropertyNode Builder::Tile::getProperty(std::string name) const
{
	if (m_tile) {
		if (Parser::PropertiesNode* properties = dynamic_cast<Parser::PropertiesNode*>(m_tile->GetFirstSpecificChild(Parser::NodeType::PROPERTIES))) {
			return properties->GetProperty(name);
		}
	}
	return Parser::PropertyNode();
}

int Builder::Tile::getId() const
{
	if (m_tile) {
		return m_tile->GetId();
	}
	return -1;
}

std::string Builder::Tile::getSource() const
{
	if (m_source.length() > 0) {
		return m_templateDirectory + m_source;
	}
	else if (m_tile) {
		if (Parser::ImageNode* imageNode = dynamic_cast<Parser::ImageNode*>(m_tile->GetFirstSpecificChild(Parser::NodeType::IMAGE))) {
			return m_templateDirectory + imageNode->getSource();
		}
	}
	return std::string();
}

sf::Vector2f Builder::Tile::getSize() const
{
	if (m_size.x > 0 && m_size.y > 0) {
		return m_size;
	}
	else if (m_tile) {
		if (Parser::ImageNode* imageNode = dynamic_cast<Parser::ImageNode*>(m_tile->GetFirstSpecificChild(Parser::NodeType::IMAGE))) {
			return sf::Vector2f(imageNode->getWidth(), imageNode->getHeight());
		}
	}
	return sf::Vector2f(0, 0);
}

void Builder::Tile::setSource(std::string source)
{
	m_source = source;
}

void Builder::Tile::setSize(sf::Vector2f size)
{
	m_size = size;
}

void Builder::Tile::setTile(Parser::TileNode* tile)
{
	m_tile = tile;

	if (Parser::ObjectGroupNode* objectgroup = dynamic_cast<Parser::ObjectGroupNode*>(tile->GetFirstSpecificChild(Parser::NodeType::OBJECTGROUP))) {
		for (auto it : objectgroup->GetSpecificListOfChild(Parser::NodeType::OBJECT)) {
			if (Parser::ObjectNode* objectNode = dynamic_cast<Parser::ObjectNode*>(it)) {
				m_objects.push_back(std::move(ObjectBuilder::BuildObject(objectNode)));
			}
		}
	}
}
